#include <stdio.h>
#include <ZorbaWrapper.h>

int
main(int argc, char* argv[]){
	int instance;
	ZorbaWrapper zorbaWrapper;
	char *result;
	char *transformation = " \ndeclare variable $inputdoc external; \njn:parse-json($inputdoc)(\"satellites\")";
	char *data ="{\"creator\" : \"Sat plugin\", \"satellites\" : {\"AAU CUBESAT\" : {\"tle1\" : \"1 27846U \", \"visible\" : false } } }";

	printf("I will execute \n'%s'\n using \n'%s'\n", transformation, data);

	instance = zorbaWrapper.create_transformation(transformation);
	result = zorbaWrapper.transform_data(instance, data);
	zorbaWrapper.disconnect(instance);

	printf("Result = '%s'\n", result);
	return 0;
}

