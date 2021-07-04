//============================================================================
// Name        : CppHelloWorld.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
/**
Compile .so library command:
gcc -shared -I D:\JDK\include -I D:\JDK\include\win32 -fPIC CppHelloWorld.cpp -o libtest.so

Compile .dll library command:
gcc -shared -I D:\JDK\include -I D:\JDK\include\win32 -fPIC CppHelloWorld.cpp -o libtest.dll

Compile .dll library and specify 64-bit version.
gcc -shared -I D:\JDK\include -I D:\JDK\include\win32 -fPIC -m64 CppHelloWorld.cpp -o libtest.dll

Compile .dll library
.\gcc -shared -I D:\JDK\include -I D:\JDK\include\win32 -fPIC D:\code\libs\CppHelloWorld.cpp -o D:\code\libs\test.dll

Compile executable file:
.\gcc  D:\code\libs\CppHelloWorld.cpp -o D:\code\libs\hello
*/

#include <jni.h>

//Java_(packageName)_ClassName_functionname
//JNIEXPORT void JNICALL
//Java_com_jni_test_MainActivity_set
//  (JNIEnv *env, jobject jobj, jstring jstr) {
//	printf("C code: set(...) is be called\n");
//}

JNIEXPORT jstring JNICALL
Java_com_jni_test_jni_NativeStringTest_get
  (JNIEnv *env, jobject jobj) {
	return (*env)->NewStringUTF(env,"Hello from JNI!");
}
