#include <stdio.h>
#include <ZorbaWrapper.h>

int
main(int argc, char* argv[]){
	int instance;
	char *result;
	char *transformation = "import module namespace jn = \"http://jsoniq.org/functions\"; \ndeclare variable $inputdoc external; \njn:parse-json($inputdoc)(\"satellites\")";
	char *data ="{\"creator\" : \"Sat plugin\", \"satellites\" : {\"AAU CUBESAT\" : {\"tle1\" : \"1 27846U \", \"visible\" : false } } }";

	printf("I will execute \n'%s'\n using \n'%s'\n", transformation, data);

	instance = create_transformation(transformation);
	result = transform_data(instance, data);
	disconnect(instance);

	printf("Result = '%s'\n", result);
	return 0;
}

