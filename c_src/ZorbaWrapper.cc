/*
 * Copyright 2006-2008 The FLWOR Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <iostream>
#include <sstream>
#include <string>

#include <zorba/zorba.h>
#include <zorba/store_manager.h>
#include <zorba/serializer.h>
#include <zorba/singleton_item_sequence.h>
#include <zorba/zorba_exception.h>

#include <stdio.h> 

using namespace zorba;
int num_instances=0, instance_count=0;
Zorba *lZorba=NULL;
void* lStore=NULL;
XQuery_t lQuery;
std::string transformationResult;



int connect() {
	if (num_instances<=0) {
		lStore = StoreManager::getStore();
		lZorba = Zorba::getInstance(lStore);
	}
	num_instances++;
	return ++instance_count;
}

void disconnect(int instance) {
	num_instances--;
	if (num_instances<=0){
		lQuery->close();
		lZorba->shutdown();
		StoreManager::shutdownStore(lStore);	
		lZorba=NULL;
		lStore=NULL;
	}
}



int create_transformation(char *transformationQuery) {
	int instance = connect();
	lQuery = lZorba->compileQuery(transformationQuery);
	return instance;
}


char *transform_data(int instance, char *data) {
	ItemFactory* lFactory = lZorba->getItemFactory();
	/* The item that is to be bound to the external variable */
	Item lItem = lFactory->createString(data);
	DynamicContext* lCtx = lQuery->getDynamicContext();
	/* Actually perform the binding. */
	lCtx->setVariable("inputdoc", lItem);
	std::ostringstream oss (std::ostringstream::out);		
	try {
		oss << lQuery;
		transformationResult = oss.str();
	} catch (ZorbaException &e) {
	    std::cerr << e << std::endl;
	    return false;
	}
	
	return (char *)transformationResult.c_str();
}



