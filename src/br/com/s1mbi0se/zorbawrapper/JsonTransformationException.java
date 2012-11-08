package br.com.s1mbi0se.zorbawrapper;

public class JsonTransformationException extends Exception {
	private static final long serialVersionUID = -6495893569762307894L;

	public JsonTransformationException() {
		super();
	}

//	public JsonTransformationException(String message, Throwable cause,
//			boolean enableSuppression, boolean writableStackTrace) {
//		super(message, cause, enableSuppression, writableStackTrace);
//	}

	public JsonTransformationException(String message, Throwable cause) {
		super(message, cause);
	}

	public JsonTransformationException(String message) {
		super(message);
	}

	public JsonTransformationException(Throwable cause) {
		super(cause);
	}

}
