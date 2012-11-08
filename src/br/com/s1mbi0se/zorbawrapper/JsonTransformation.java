package br.com.s1mbi0se.zorbawrapper;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;

public class JsonTransformation {
	private int instance;

	public JsonTransformation(String transformation) {
		System.loadLibrary("zorbawrapper");
		instance = ZorbaJavaWrapperSWIG.create_transformation(transformation);
	}

	public JsonTransformation(InputStream Transformation) throws IOException {
		this(readFile(Transformation));
	}

	public void destroy() {
		ZorbaJavaWrapperSWIG.disconnect(instance);
	}

	public String transform(String origin) throws JsonTransformationException {
		if (instance < 0)
			throw new JsonTransformationException(
					"Instance not created, please connect first");
		return ZorbaJavaWrapperSWIG.transform_data(instance, origin);
	}

	public String transform(InputStream origin) throws IOException,
			JsonTransformationException {
		return transform(readFile(origin));
	}

	public static String readFile(InputStream inputStream) throws IOException {
		BufferedReader reader = new BufferedReader(new InputStreamReader(
				inputStream));
		StringBuilder fileData = new StringBuilder();
		char[] buf = new char[1024];
		int numRead = 0;
		while ((numRead = reader.read(buf)) != -1) {
			fileData.append(buf, 0, numRead);
		}
		reader.close();
		return fileData.toString();
	}

}
