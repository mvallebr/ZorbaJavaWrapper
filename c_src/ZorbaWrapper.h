
#include <zorba/zorba.h>
#include <zorba/store_manager.h>
#include <zorba/serializer.h>
#include <zorba/singleton_item_sequence.h>
#include <zorba/zorba_exception.h>
#include <zorba/zorba_string.h>

class ZorbaWrapper {
private:
	static int num_instances;
	static zorba::Zorba *lZorba;
	static void* lStore;
	std::string transformationResult;
	zorba::XQuery_t lQuery;
	static zorba::String uriPaths, libPaths, modulePaths;
public:
	ZorbaWrapper();
	~ZorbaWrapper();

	void create_transformation(char *transformationQuery);
	char *transform_data(char *data);
	static void disconnectAll();
	static void setUriPaths(char *prop);
	static void setLibPaths(char *prop);
	static void setModulePaths(char *prop);
};

//extern int create_transformation(char *transformationQuery);
//extern char *transform_data(int instance, char *data);
//extern void disconnect(int instance);


