//============================================================================
// Name        : CppHelloWorld.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
/**
Compile .dll library
gcc -shared -I D:\JDK\include -I D:\JDK\include\win32 -fPIC D:\code\libs\CppHelloWorld.cpp -o D:\code\libs\test.dll

Compile .so library
gcc -shared -I D:\JDK\include -I D:\JDK\include\win32 -fPIC D:\code\libs\CppHelloWorld.cpp -o D:\code\libs\test.so

*/

#include <stdio.h>
#include "com_interact_nati_CallNativeFunction.h"


int main() {
		printf("Hello World from C++ program.");
		return 0;
	}

	


JNIEXPORT void JNICALL Java_com_interact_nati_CallNativeFunction_set
  (JNIEnv *env, jobject jobj, jstring jstr) {
	printf("C code: set(...) is be called\n");
}

JNIEXPORT jstring JNICALL Java_com_interact_nati_CallNativeFunction_get
  (JNIEnv *env, jobject jobj) {
	printf("C code: get(...) is be called\n");
	return (env)->NewStringUTF("Hello from JNI!");
}
