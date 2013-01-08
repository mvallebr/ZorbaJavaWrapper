

class ZorbaWrapper {
public:
	ZorbaWrapper();
	~ZorbaWrapper();

	int create_transformation(char *transformationQuery);
	char *transform_data(int instance, char *data);
	void disconnect(int instance);
	void setUriPaths(char *prop);
	void setLibPaths(char *prop);
	void setModulePaths(char *prop);
};

//extern int create_transformation(char *transformationQuery);
//extern char *transform_data(int instance, char *data);
//extern void disconnect(int instance);


