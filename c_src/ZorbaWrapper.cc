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

#include <stdio.h>

//static initializations
int ZorbaWrapper::num_instances = 0;
zorba::Zorba *ZorbaWrapper::lZorba = NULL;
void* ZorbaWrapper::lStore = NULL;
zorba::String ZorbaWrapper::uriPaths, ZorbaWrapper::libPaths, ZorbaWrapper::modulePaths;


using namespace zorba;

void ZorbaWrapper::setUriPaths(char *prop) {
	ZorbaWrapper::uriPaths = prop;
}

void ZorbaWrapper::setLibPaths(char *prop) {
	ZorbaWrapper::libPaths = prop;
}

void ZorbaWrapper::setModulePaths(char *prop) {
	ZorbaWrapper::modulePaths = prop;
}

//Constructor
ZorbaWrapper::ZorbaWrapper() {
	if (lStore == NULL) {
		lStore = StoreManager::getStore();
	}
	if (lZorba == NULL) {
		lZorba = Zorba::getInstance(lStore);
	}
	num_instances++;
	std::cout << "Created instance ";

	std::cout.flush();
}

//Destructor
ZorbaWrapper::~ZorbaWrapper() {
	std::cout << "Disconnecting instance - data "
			<< ((lQuery == NULL) ? "is null" : "is not null") << "\n";
	std::cout.flush();
	lQuery->close();
	num_instances--;
	std::cout << "ZorbaJavaWrapper successfully disconnected\n";
	if (num_instances <= 0) {
		disconnectAll();
	}
	std::cout.flush();
	std::cout << "Disconnected instance - data "
			<< ((lQuery == NULL) ? "is null" : "is not null") << "\n";
	std::cout.flush();
}

void ZorbaWrapper::disconnectAll() {
	std::cout << "Disconnecting all\n";
	std::cout.flush();
	StoreManager::shutdownStore(lStore);
	lZorba->shutdown();
	lZorba = NULL;
	lStore = NULL;
	std::cout << "Zorba shutdown completed successfully \n";
	std::cout << "Finished disconnecting all - num_instances = "
			<< num_instances << " \n";
	std::cout.flush();
}

void ZorbaWrapper::create_transformation(char *transformationQuery) {
	StaticContext_t sc = lZorba->createStaticContext();
	/* Create lib vector */
	std::vector < zorba::String > libPathsV;
	libPathsV.push_back(libPaths);
	if (libPaths.size() > 0) {
		std::cout << "Setting lib path to '" << libPaths << "'\n";
		sc->setLibPath(libPathsV);
	}
	/* Create uri vector */
	std::vector < zorba::String > uriPathsV;
	uriPathsV.push_back(uriPaths);
	if (uriPaths.size() > 0) {
		std::cout << "Setting uri path to '" << uriPaths << "'\n";
		sc->setURIPath(uriPathsV);
	}
	/* Create module vector */
	std::vector < zorba::String > modulePathsV;
	modulePathsV.push_back(modulePaths);
	if (modulePaths.size() > 0) {
		std::cout << "Setting module path to '" << modulePaths << "'\n";
		sc->setModulePaths(modulePathsV);
	}
	std::cout.flush();
	/* Create query using the static context */
	if (lQuery != NULL)
			lQuery->close();
	lQuery = lZorba->compileQuery(transformationQuery, sc);
}

char *
ZorbaWrapper::transform_data(char *data) {
	std::cout << "transform_data " << data << "\n";
	std::cout.flush();
	if (lQuery==NULL)
		throw "query cannot be null when calling transform";
	ItemFactory* lFactory = lZorba->getItemFactory();
	/* The item that is to be bound to the external variable */
	Item lItem = lFactory->createString(data);
	DynamicContext* lCtx = lQuery->getDynamicContext();
	/* Actually perform the binding. */
	lCtx->setVariable("inputdoc", lItem);
	std::ostringstream oss(std::ostringstream::out);
//	try {
	oss << lQuery;
	transformationResult = oss.str();
//	} catch (ZorbaException &e) {
//	    std::cerr << e << std::endl;
//	    return false;
//	}

	return (char *) transformationResult.c_str();
}

