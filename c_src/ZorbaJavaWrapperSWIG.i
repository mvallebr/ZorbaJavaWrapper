%module ZorbaJavaWrapperSWIG
 %{
 /* Put header files here or function declarations like below */
 extern int create_transformation(char *transformationQuery);
 extern char *transform_data(int instance, char *data);
 extern void disconnect(int instance);
 extern void setUriPaths(char *prop);
 extern void setLibPaths(char *prop);
 extern void setModulePaths(char *prop);
 %}
 
 extern int create_transformation(char *transformationQuery);
 extern char *transform_data(int instance, char *data);
 extern void disconnect(int instance);
 extern void setUriPaths(char *prop);
 extern void setLibPaths(char *prop);
 extern void setModulePaths(char *prop);