package com.s1mbi0se.dmp.transformation;

import java.io.IOException;
import java.io.InputStream;

import org.junit.Test;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import br.com.s1mbi0se.zorbawrapper.JsonTransformation;
import br.com.s1mbi0se.zorbawrapper.JsonTransformationException;

public class TestBasicTransformations {
    private final Logger log = LoggerFactory.getLogger(TestBasicTransformations.class);

	@Test
	public void testTransform() throws JsonTransformationException, IOException {
		try {
			InputStream query = TestBasicTransformations.class
					.getResourceAsStream("/query.xq");
			JsonTransformation jsonTransformation = new JsonTransformation(
					query);

			InputStream originData1 = TestBasicTransformations.class
					.getResourceAsStream("/origin_data.json");
			InputStream originData2 = TestBasicTransformations.class
					.getResourceAsStream("/origin_data2.json");
			String o1 = JsonTransformation.readFile(originData1);
			String o2 = JsonTransformation.readFile(originData2);
			for (int i = 0; i < 100; i++) {
				log.info("i=" + i
				        + "\nTransformation result 1 = '"
						+ jsonTransformation.transform(o1)+"'"
						+ "\nTransformation result 2 = '"
						+ jsonTransformation.transform(o2)+"'");
			}
		} catch (Throwable t){
			log.error(t.getMessage(), t);
		} finally {
			JsonTransformation.finishAll();
		}
	}
}
