/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com4j_Native */

#ifndef _Included_com4j_Native
#define _Included_com4j_Native
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com4j_Native
 * Method:    init
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com4j_Native_init
  (JNIEnv *, jclass);

/*
 * Class:     com4j_Native
 * Method:    createInstance
 * Signature: (Ljava/lang/String;JJ)I
 */
JNIEXPORT jint JNICALL Java_com4j_Native_createInstance
  (JNIEnv *, jclass, jstring, jlong, jlong);

/*
 * Class:     com4j_Native
 * Method:    release
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_com4j_Native_release
  (JNIEnv *, jclass, jint);

/*
 * Class:     com4j_Native
 * Method:    invoke
 * Signature: (II[Ljava/lang/Object;[ILjava/lang/Class;IZI)Ljava/lang/Object;
 */
JNIEXPORT jobject JNICALL Java_com4j_Native_invoke
  (JNIEnv *, jclass, jint, jint, jobjectArray, jintArray, jclass, jint, jboolean, jint);

/*
 * Class:     com4j_Native
 * Method:    queryInterface
 * Signature: (IJJ)I
 */
JNIEXPORT jint JNICALL Java_com4j_Native_queryInterface
  (JNIEnv *, jclass, jint, jlong, jlong);

#ifdef __cplusplus
}
#endif
#endif
