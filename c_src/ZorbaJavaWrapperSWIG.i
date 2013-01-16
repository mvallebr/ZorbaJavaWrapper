%module ZorbaJavaWrapperSWIG

 // Language independent exception handler
%include exception.i
%allowexception; 
%exception {
  try {
    $action
  }
  catch (zorba::XQueryException& e) {
    std::stringstream lStream;
    lStream << e;
    SWIG_exception(SWIG_RuntimeError, lStream.str().c_str());
  }
  catch (zorba::ZorbaException& e) {
    std::stringstream lStream;
    lStream << e;
    SWIG_exception(SWIG_RuntimeError, lStream.str().c_str());
  }
}
 
 
%{  // Implementations

#include <string>
#include <sstream>
#include <zorba/zorba.h>
#include <zorba/store_manager.h>
#include <zorba/zorba_exception.h>
#include <zorba/diagnostic_handler.h>
#include <zorba/options.h>
#include <zorba/singleton_item_sequence.h>
#include <zorba/serializer.h>
#include <zorba/static_collection_manager.h>

  class CompilerHints;
  class DiagnosticHandler;
  class Store;
  class Zorba;
  class Iterator;

  class DynamicException;
  class DocumentManager;
  class XQueryException;
  class SerializationException;
  class StaticException;
  class SystemException;
  class TypeException;
  class UserException;
  class ZorbaException;
  class XmlDataManager;
  class StaticCollectionManager;
  class Store;
  class InMemoryStore;
  
%}
 
 
 

%{
	#include "ZorbaWrapper.h"
%}
 
class ZorbaWrapper {

public:
	ZorbaWrapper();
	~ZorbaWrapper();

	static void disconnectAll();
	void create_transformation(char *transformationQuery);
	char *transform_data(char *data);	
	static void setUriPaths(char *prop);
	static void setLibPaths(char *prop);
	static void setModulePaths(char *prop);
};
