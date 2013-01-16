/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 2.0.4
 * 
 * This file is not intended to be easily readable and contains a number of 
 * coding conventions designed to improve portability and efficiency. Do not make
 * changes to this file unless you know what you are doing--modify the SWIG 
 * interface file instead. 
 * ----------------------------------------------------------------------------- */

#define SWIGJAVA


#ifdef __cplusplus
/* SwigValueWrapper is described in swig.swg */
template<typename T> class SwigValueWrapper {
  struct SwigMovePointer {
    T *ptr;
    SwigMovePointer(T *p) : ptr(p) { }
    ~SwigMovePointer() { delete ptr; }
    SwigMovePointer& operator=(SwigMovePointer& rhs) { T* oldptr = ptr; ptr = 0; delete oldptr; ptr = rhs.ptr; rhs.ptr = 0; return *this; }
  } pointer;
  SwigValueWrapper& operator=(const SwigValueWrapper<T>& rhs);
  SwigValueWrapper(const SwigValueWrapper<T>& rhs);
public:
  SwigValueWrapper() : pointer(0) { }
  SwigValueWrapper& operator=(const T& t) { SwigMovePointer tmp(new T(t)); pointer = tmp; return *this; }
  operator T&() const { return *pointer.ptr; }
  T *operator&() { return pointer.ptr; }
};

template <typename T> T SwigValueInit() {
  return T();
}
#endif

/* -----------------------------------------------------------------------------
 *  This section contains generic SWIG labels for method/variable
 *  declarations/attributes, and other compiler dependent labels.
 * ----------------------------------------------------------------------------- */

/* template workaround for compilers that cannot correctly implement the C++ standard */
#ifndef SWIGTEMPLATEDISAMBIGUATOR
# if defined(__SUNPRO_CC) && (__SUNPRO_CC <= 0x560)
#  define SWIGTEMPLATEDISAMBIGUATOR template
# elif defined(__HP_aCC)
/* Needed even with `aCC -AA' when `aCC -V' reports HP ANSI C++ B3910B A.03.55 */
/* If we find a maximum version that requires this, the test would be __HP_aCC <= 35500 for A.03.55 */
#  define SWIGTEMPLATEDISAMBIGUATOR template
# else
#  define SWIGTEMPLATEDISAMBIGUATOR
# endif
#endif

/* inline attribute */
#ifndef SWIGINLINE
# if defined(__cplusplus) || (defined(__GNUC__) && !defined(__STRICT_ANSI__))
#   define SWIGINLINE inline
# else
#   define SWIGINLINE
# endif
#endif

/* attribute recognised by some compilers to avoid 'unused' warnings */
#ifndef SWIGUNUSED
# if defined(__GNUC__)
#   if !(defined(__cplusplus)) || (__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4))
#     define SWIGUNUSED __attribute__ ((__unused__)) 
#   else
#     define SWIGUNUSED
#   endif
# elif defined(__ICC)
#   define SWIGUNUSED __attribute__ ((__unused__)) 
# else
#   define SWIGUNUSED 
# endif
#endif

#ifndef SWIG_MSC_UNSUPPRESS_4505
# if defined(_MSC_VER)
#   pragma warning(disable : 4505) /* unreferenced local function has been removed */
# endif 
#endif

#ifndef SWIGUNUSEDPARM
# ifdef __cplusplus
#   define SWIGUNUSEDPARM(p)
# else
#   define SWIGUNUSEDPARM(p) p SWIGUNUSED 
# endif
#endif

/* internal SWIG method */
#ifndef SWIGINTERN
# define SWIGINTERN static SWIGUNUSED
#endif

/* internal inline SWIG method */
#ifndef SWIGINTERNINLINE
# define SWIGINTERNINLINE SWIGINTERN SWIGINLINE
#endif

/* exporting methods */
#if (__GNUC__ >= 4) || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4)
#  ifndef GCC_HASCLASSVISIBILITY
#    define GCC_HASCLASSVISIBILITY
#  endif
#endif

#ifndef SWIGEXPORT
# if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#   if defined(STATIC_LINKED)
#     define SWIGEXPORT
#   else
#     define SWIGEXPORT __declspec(dllexport)
#   endif
# else
#   if defined(__GNUC__) && defined(GCC_HASCLASSVISIBILITY)
#     define SWIGEXPORT __attribute__ ((visibility("default")))
#   else
#     define SWIGEXPORT
#   endif
# endif
#endif

/* calling conventions for Windows */
#ifndef SWIGSTDCALL
# if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#   define SWIGSTDCALL __stdcall
# else
#   define SWIGSTDCALL
# endif 
#endif

/* Deal with Microsoft's attempt at deprecating C standard runtime functions */
#if !defined(SWIG_NO_CRT_SECURE_NO_DEPRECATE) && defined(_MSC_VER) && !defined(_CRT_SECURE_NO_DEPRECATE)
# define _CRT_SECURE_NO_DEPRECATE
#endif

/* Deal with Microsoft's attempt at deprecating methods in the standard C++ library */
#if !defined(SWIG_NO_SCL_SECURE_NO_DEPRECATE) && defined(_MSC_VER) && !defined(_SCL_SECURE_NO_DEPRECATE)
# define _SCL_SECURE_NO_DEPRECATE
#endif



/* Fix for jlong on some versions of gcc on Windows */
#if defined(__GNUC__) && !defined(__INTEL_COMPILER)
  typedef long long __int64;
#endif

/* Fix for jlong on 64-bit x86 Solaris */
#if defined(__x86_64)
# ifdef _LP64
#   undef _LP64
# endif
#endif

#include <jni.h>
#include <stdlib.h>
#include <string.h>


/* Support for throwing Java exceptions */
typedef enum {
  SWIG_JavaOutOfMemoryError = 1, 
  SWIG_JavaIOException, 
  SWIG_JavaRuntimeException, 
  SWIG_JavaIndexOutOfBoundsException,
  SWIG_JavaArithmeticException,
  SWIG_JavaIllegalArgumentException,
  SWIG_JavaNullPointerException,
  SWIG_JavaDirectorPureVirtual,
  SWIG_JavaUnknownError
} SWIG_JavaExceptionCodes;

typedef struct {
  SWIG_JavaExceptionCodes code;
  const char *java_exception;
} SWIG_JavaExceptions_t;


static void SWIGUNUSED SWIG_JavaThrowException(JNIEnv *jenv, SWIG_JavaExceptionCodes code, const char *msg) {
  jclass excep;
  static const SWIG_JavaExceptions_t java_exceptions[] = {
    { SWIG_JavaOutOfMemoryError, "java/lang/OutOfMemoryError" },
    { SWIG_JavaIOException, "java/io/IOException" },
    { SWIG_JavaRuntimeException, "java/lang/RuntimeException" },
    { SWIG_JavaIndexOutOfBoundsException, "java/lang/IndexOutOfBoundsException" },
    { SWIG_JavaArithmeticException, "java/lang/ArithmeticException" },
    { SWIG_JavaIllegalArgumentException, "java/lang/IllegalArgumentException" },
    { SWIG_JavaNullPointerException, "java/lang/NullPointerException" },
    { SWIG_JavaDirectorPureVirtual, "java/lang/RuntimeException" },
    { SWIG_JavaUnknownError,  "java/lang/UnknownError" },
    { (SWIG_JavaExceptionCodes)0,  "java/lang/UnknownError" }
  };
  const SWIG_JavaExceptions_t *except_ptr = java_exceptions;

  while (except_ptr->code != code && except_ptr->code)
    except_ptr++;

  jenv->ExceptionClear();
  excep = jenv->FindClass(except_ptr->java_exception);
  if (excep)
    jenv->ThrowNew(excep, msg);
}


/* Contract support */

#define SWIG_contract_assert(nullreturn, expr, msg) if (!(expr)) {SWIG_JavaThrowException(jenv, SWIG_JavaIllegalArgumentException, msg); return nullreturn; } else

/*  Errors in SWIG */
#define  SWIG_UnknownError    	   -1 
#define  SWIG_IOError        	   -2 
#define  SWIG_RuntimeError   	   -3 
#define  SWIG_IndexError     	   -4 
#define  SWIG_TypeError      	   -5 
#define  SWIG_DivisionByZero 	   -6 
#define  SWIG_OverflowError  	   -7 
#define  SWIG_SyntaxError    	   -8 
#define  SWIG_ValueError     	   -9 
#define  SWIG_SystemError    	   -10
#define  SWIG_AttributeError 	   -11
#define  SWIG_MemoryError    	   -12 
#define  SWIG_NullReferenceError   -13




SWIGINTERN void SWIG_JavaException(JNIEnv *jenv, int code, const char *msg) {
  SWIG_JavaExceptionCodes exception_code = SWIG_JavaUnknownError;
  switch(code) {
  case SWIG_MemoryError:
    exception_code = SWIG_JavaOutOfMemoryError;
    break;
  case SWIG_IOError:
    exception_code = SWIG_JavaIOException;
    break;
  case SWIG_SystemError:
  case SWIG_RuntimeError:
    exception_code = SWIG_JavaRuntimeException;
    break;
  case SWIG_OverflowError:
  case SWIG_IndexError:
    exception_code = SWIG_JavaIndexOutOfBoundsException;
    break;
  case SWIG_DivisionByZero:
    exception_code = SWIG_JavaArithmeticException;
    break;
  case SWIG_SyntaxError:
  case SWIG_ValueError:
  case SWIG_TypeError:
    exception_code = SWIG_JavaIllegalArgumentException;
    break;
  case SWIG_UnknownError:
  default:
    exception_code = SWIG_JavaUnknownError;
    break;
  }
  SWIG_JavaThrowException(jenv, exception_code, msg);
}


#include <stdexcept>

  // Implementations

#include <string>
#include <sstream>
#include <zorba/zorba.h>
#include <zorba/store_manager.h>
#include <zorba/zorba_exception.h>
#include <zorba/diagnostic_handler.h>
#include <zorba/options.h>
#include <zorba/singleton_item_sequence.h>
#include <zorba/serializer.h>
#include <zorba/static_collection_manager.h>

  class CompilerHints;
  class DiagnosticHandler;
  class Store;
  class Zorba;
  class Iterator;

  class DynamicException;
  class DocumentManager;
  class XQueryException;
  class SerializationException;
  class StaticException;
  class SystemException;
  class TypeException;
  class UserException;
  class ZorbaException;
  class XmlDataManager;
  class StaticCollectionManager;
  class Store;
  class InMemoryStore;
  


	#include "ZorbaWrapper.h"


#ifdef __cplusplus
extern "C" {
#endif

SWIGEXPORT jlong JNICALL Java_br_com_s1mbi0se_zorbawrapper_ZorbaJavaWrapperSWIGJNI_new_1ZorbaWrapper(JNIEnv *jenv, jclass jcls) {
  jlong jresult = 0 ;
  ZorbaWrapper *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  {
    try {
      result = (ZorbaWrapper *)new ZorbaWrapper();
    }
    catch (zorba::XQueryException& e) {
      std::stringstream lStream;
      lStream << e;
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, lStream.str().c_str()); return 0; 
      };
    }
    catch (zorba::ZorbaException& e) {
      std::stringstream lStream;
      lStream << e;
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, lStream.str().c_str()); return 0; 
      };
    }
  }
  *(ZorbaWrapper **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_br_com_s1mbi0se_zorbawrapper_ZorbaJavaWrapperSWIGJNI_delete_1ZorbaWrapper(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  ZorbaWrapper *arg1 = (ZorbaWrapper *) 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(ZorbaWrapper **)&jarg1; 
  {
    try {
      delete arg1;
    }
    catch (zorba::XQueryException& e) {
      std::stringstream lStream;
      lStream << e;
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, lStream.str().c_str()); return ; 
      };
    }
    catch (zorba::ZorbaException& e) {
      std::stringstream lStream;
      lStream << e;
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, lStream.str().c_str()); return ; 
      };
    }
  }
}


SWIGEXPORT void JNICALL Java_br_com_s1mbi0se_zorbawrapper_ZorbaJavaWrapperSWIGJNI_ZorbaWrapper_1disconnectAll(JNIEnv *jenv, jclass jcls) {
  (void)jenv;
  (void)jcls;
  {
    try {
      ZorbaWrapper::disconnectAll();
    }
    catch (zorba::XQueryException& e) {
      std::stringstream lStream;
      lStream << e;
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, lStream.str().c_str()); return ; 
      };
    }
    catch (zorba::ZorbaException& e) {
      std::stringstream lStream;
      lStream << e;
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, lStream.str().c_str()); return ; 
      };
    }
  }
}


SWIGEXPORT void JNICALL Java_br_com_s1mbi0se_zorbawrapper_ZorbaJavaWrapperSWIGJNI_ZorbaWrapper_1create_1transformation(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jstring jarg2) {
  ZorbaWrapper *arg1 = (ZorbaWrapper *) 0 ;
  char *arg2 = (char *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(ZorbaWrapper **)&jarg1; 
  arg2 = 0;
  if (jarg2) {
    arg2 = (char *)jenv->GetStringUTFChars(jarg2, 0);
    if (!arg2) return ;
  }
  {
    try {
      (arg1)->create_transformation(arg2);
    }
    catch (zorba::XQueryException& e) {
      std::stringstream lStream;
      lStream << e;
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, lStream.str().c_str()); return ; 
      };
    }
    catch (zorba::ZorbaException& e) {
      std::stringstream lStream;
      lStream << e;
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, lStream.str().c_str()); return ; 
      };
    }
  }
  if (arg2) jenv->ReleaseStringUTFChars(jarg2, (const char *)arg2);
}


SWIGEXPORT jstring JNICALL Java_br_com_s1mbi0se_zorbawrapper_ZorbaJavaWrapperSWIGJNI_ZorbaWrapper_1transform_1data(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jstring jarg2) {
  jstring jresult = 0 ;
  ZorbaWrapper *arg1 = (ZorbaWrapper *) 0 ;
  char *arg2 = (char *) 0 ;
  char *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(ZorbaWrapper **)&jarg1; 
  arg2 = 0;
  if (jarg2) {
    arg2 = (char *)jenv->GetStringUTFChars(jarg2, 0);
    if (!arg2) return 0;
  }
  {
    try {
      result = (char *)(arg1)->transform_data(arg2);
    }
    catch (zorba::XQueryException& e) {
      std::stringstream lStream;
      lStream << e;
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, lStream.str().c_str()); return 0; 
      };
    }
    catch (zorba::ZorbaException& e) {
      std::stringstream lStream;
      lStream << e;
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, lStream.str().c_str()); return 0; 
      };
    }
  }
  if (result) jresult = jenv->NewStringUTF((const char *)result);
  if (arg2) jenv->ReleaseStringUTFChars(jarg2, (const char *)arg2);
  return jresult;
}


SWIGEXPORT void JNICALL Java_br_com_s1mbi0se_zorbawrapper_ZorbaJavaWrapperSWIGJNI_ZorbaWrapper_1setUriPaths(JNIEnv *jenv, jclass jcls, jstring jarg1) {
  char *arg1 = (char *) 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = 0;
  if (jarg1) {
    arg1 = (char *)jenv->GetStringUTFChars(jarg1, 0);
    if (!arg1) return ;
  }
  {
    try {
      ZorbaWrapper::setUriPaths(arg1);
    }
    catch (zorba::XQueryException& e) {
      std::stringstream lStream;
      lStream << e;
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, lStream.str().c_str()); return ; 
      };
    }
    catch (zorba::ZorbaException& e) {
      std::stringstream lStream;
      lStream << e;
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, lStream.str().c_str()); return ; 
      };
    }
  }
  if (arg1) jenv->ReleaseStringUTFChars(jarg1, (const char *)arg1);
}


SWIGEXPORT void JNICALL Java_br_com_s1mbi0se_zorbawrapper_ZorbaJavaWrapperSWIGJNI_ZorbaWrapper_1setLibPaths(JNIEnv *jenv, jclass jcls, jstring jarg1) {
  char *arg1 = (char *) 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = 0;
  if (jarg1) {
    arg1 = (char *)jenv->GetStringUTFChars(jarg1, 0);
    if (!arg1) return ;
  }
  {
    try {
      ZorbaWrapper::setLibPaths(arg1);
    }
    catch (zorba::XQueryException& e) {
      std::stringstream lStream;
      lStream << e;
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, lStream.str().c_str()); return ; 
      };
    }
    catch (zorba::ZorbaException& e) {
      std::stringstream lStream;
      lStream << e;
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, lStream.str().c_str()); return ; 
      };
    }
  }
  if (arg1) jenv->ReleaseStringUTFChars(jarg1, (const char *)arg1);
}


SWIGEXPORT void JNICALL Java_br_com_s1mbi0se_zorbawrapper_ZorbaJavaWrapperSWIGJNI_ZorbaWrapper_1setModulePaths(JNIEnv *jenv, jclass jcls, jstring jarg1) {
  char *arg1 = (char *) 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = 0;
  if (jarg1) {
    arg1 = (char *)jenv->GetStringUTFChars(jarg1, 0);
    if (!arg1) return ;
  }
  {
    try {
      ZorbaWrapper::setModulePaths(arg1);
    }
    catch (zorba::XQueryException& e) {
      std::stringstream lStream;
      lStream << e;
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, lStream.str().c_str()); return ; 
      };
    }
    catch (zorba::ZorbaException& e) {
      std::stringstream lStream;
      lStream << e;
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, lStream.str().c_str()); return ; 
      };
    }
  }
  if (arg1) jenv->ReleaseStringUTFChars(jarg1, (const char *)arg1);
}


#ifdef __cplusplus
}
#endif
