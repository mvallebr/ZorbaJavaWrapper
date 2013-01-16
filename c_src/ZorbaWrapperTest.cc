#include <stdio.h>
#include <ZorbaWrapper.h>

int
main(int argc, char* argv[]){
	ZorbaWrapper *zorbaWrapper;
	char *result;
	char *transformation = " \ndeclare variable $inputdoc external; \njn:parse-json($inputdoc)(\"satellites\")";
	char *data ="{\"creator\" : \"Sat plugin\", \"satellites\" : {\"AAU CUBESAT\" : {\"tle1\" : \"1 27846U \", \"visible\" : false } } }";

	zorbaWrapper = new ZorbaWrapper();

	printf("I will execute \n'%s'\n using \n'%s'\n", transformation, data);
	zorbaWrapper->create_transformation(transformation);
	for (int i=0; i<100; i++){

		result = zorbaWrapper->transform_data(data);
		printf("Result = '%s'\n", result);
	}

    delete zorbaWrapper;

    ZorbaWrapper::disconnectAll();

	return 0;
}

