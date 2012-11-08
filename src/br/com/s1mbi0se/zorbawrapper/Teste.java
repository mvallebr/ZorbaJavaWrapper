package br.com.s1mbi0se.zorbawrapper;

public class Teste {

	public static void main(String[] args) {
		String transformationQuery = "for $x in (1, 2, 3)";
		String data = "abc";
		int instance = ZorbaJavaWrapperSWIG
				.create_transformation(transformationQuery);
		ZorbaJavaWrapperSWIG.connect(instance);
		String result = ZorbaJavaWrapperSWIG.transform_data(instance, data);
		ZorbaJavaWrapperSWIG.disconnect(instance);

		System.out.println("Result = " + result);
	}

}
