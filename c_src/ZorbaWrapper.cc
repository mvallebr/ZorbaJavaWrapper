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

#include <ZorbaWrapper.h>

#include <iostream>
#include <sstream>
#include <string>
#include <map>

#include <zorba/zorba.h>
#include <zorba/store_manager.h>
#include <zorba/serializer.h>
#include <zorba/singleton_item_sequence.h>
#include <zorba/zorba_exception.h>
#include <zorba/zorba_string.h>

#include <stdio.h> 

using namespace zorba;
int num_instances=0, instance_count=0;
Zorba *lZorba=NULL;
void* lStore=NULL;
std::string transformationResult;
std::map<int,XQuery_t> queries;
zorba::String uriPaths, libPaths, modulePaths;

void
ZorbaWrapper::setUriPaths(char *prop) {
	uriPaths = prop;
}

void
ZorbaWrapper::setLibPaths(char *prop) {
	libPaths = prop;
}

void
ZorbaWrapper::setModulePaths(char *prop) {
	modulePaths = prop;
}

int connect() {
	if (num_instances<=0) {
		lStore = StoreManager::getStore();
		lZorba = Zorba::getInstance(lStore);
	}
	num_instances++;
	return ++instance_count;
}

//Constructor
ZorbaWrapper::ZorbaWrapper() {

}

//Destructor
ZorbaWrapper::~ZorbaWrapper() {

}

void
ZorbaWrapper::disconnect(int instance) {
	XQuery_t lQuery = queries[instance];
	lQuery->close();
	num_instances--;
	std::cout << "ZorbaJavaWrapper successfully disconnected\n";
	if (num_instances<=0){
		lZorba->shutdown();
		StoreManager::shutdownStore(lStore);	
		lZorba=NULL;
		lStore=NULL;
		std::cout << "Zorba shutdown completed successfully \n";
	}
	std::cout.flush();
}



int
ZorbaWrapper::create_transformation(char *transformationQuery) {
	int instance = connect();
	StaticContext_t sc = lZorba->createStaticContext();
	/* Create lib vector */
	std::vector<zorba::String> libPathsV;
	libPathsV.push_back(libPaths);
	if (libPaths.size()>0){
		std::cout << "Setting lib path to '" << libPaths << "'\n";
		sc->setLibPath(libPathsV);
	}
	/* Create uri vector */
	std::vector<zorba::String> uriPathsV;
	uriPathsV.push_back(uriPaths);
	if (uriPaths.size()>0) {
		std::cout << "Setting uri path to '" << uriPaths << "'\n";
		sc->setURIPath(uriPathsV);
	}
	/* Create module vector */
	std::vector<zorba::String> modulePathsV;
	modulePathsV.push_back(modulePaths);
	if (modulePaths.size()>0) {
		std::cout << "Setting module path to '" << modulePaths << "'\n";
		sc->setModulePaths(modulePathsV);
	}
	std::cout.flush();
	/* Create query using the static context */
	XQuery_t lQuery = lZorba->compileQuery(transformationQuery, sc);
	queries[instance] = lQuery;
	return instance;
}


char *
ZorbaWrapper::transform_data(int instance, char *data) {
	XQuery_t lQuery = queries[instance];
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


















