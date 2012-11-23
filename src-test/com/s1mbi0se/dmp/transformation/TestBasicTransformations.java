package com.s1mbi0se.dmp.transformation;

import java.io.IOException;
import java.io.InputStream;

import org.junit.Test;

import br.com.s1mbi0se.zorbawrapper.JsonTransformation;
import br.com.s1mbi0se.zorbawrapper.JsonTransformationException;

public class TestBasicTransformations {

	@Test
	public void testTransform() throws JsonTransformationException, IOException {
		InputStream query = TestBasicTransformations.class
				.getResourceAsStream("/query.json");
		JsonTransformation jsonTransformation = new JsonTransformation(query);

		InputStream originData1 = TestBasicTransformations.class
				.getResourceAsStream("/origin_data.json");
		System.out.println("Transformation result 1 = "
				+ jsonTransformation.transform(originData1));
		InputStream originData2 = TestBasicTransformations.class
				.getResourceAsStream("/origin_data2.json");
		System.out.println("Transformation result 2 = "
				+ jsonTransformation.transform(originData2));

		jsonTransformation.destroy();	
		System.exit(0);
	}
}
