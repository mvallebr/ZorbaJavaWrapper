/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 2.0.4
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package br.com.s1mbi0se.zorbawrapper;

public class ZorbaJavaWrapperSWIGJNI {
  public final static native long new_ZorbaWrapper();
  public final static native void delete_ZorbaWrapper(long jarg1);
  public final static native int ZorbaWrapper_create_transformation(long jarg1, ZorbaWrapper jarg1_, String jarg2);
  public final static native String ZorbaWrapper_transform_data(long jarg1, ZorbaWrapper jarg1_, int jarg2, String jarg3);
  public final static native void ZorbaWrapper_disconnect(long jarg1, ZorbaWrapper jarg1_, int jarg2);
  public final static native void ZorbaWrapper_setUriPaths(long jarg1, ZorbaWrapper jarg1_, String jarg2);
  public final static native void ZorbaWrapper_setLibPaths(long jarg1, ZorbaWrapper jarg1_, String jarg2);
  public final static native void ZorbaWrapper_setModulePaths(long jarg1, ZorbaWrapper jarg1_, String jarg2);
}
