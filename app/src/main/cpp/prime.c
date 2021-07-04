////
//// Created by Nick Lai on 2021/7/1.
////

#include <jni.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "android_log.h"
#include "file.h"

#define TAG "prime"
#define FILENAME TAG ".txt"

char *path;

void uninit() {
    if (path != NULL) {
        free(path);
        path = NULL;
    }
}

JNIEXPORT void JNICALL
Java_com_jni_test_jni_NativePrime_init(JNIEnv *env, jobject thiz,
                                       jstring jstrDir) {
    uninit();
    const char *dir = (*env)->GetStringUTFChars(env, jstrDir, NULL);
    path = malloc(strlen(dir) + strlen(FILENAME) + 2);
    combinePath(path, dir, FILENAME);
    (*env)->ReleaseStringUTFChars(env, jstrDir, dir);
}

JNIEXPORT void JNICALL
Java_com_jni_test_jni_NativePrime_uninit(JNIEnv *env, jobject thiz) {
    uninit();
}

/**
 * prefix for funcitons:Java_com_jni_test_jni_
 *
 * 1.Judge prime.
 * 2.Get primes.
 * 3.Save primes.
 * 4.Read primes.
 */


int isPrime(int num) {
    if (num < 2) {
        //0 and 1 are both not a prime.
        return 0;
    }
    if (num == 2 || num == 3 || num == 5) {
        return 1;
    }
    if (num % 2 != 0 && num % 3 != 0 && num % 5 != 0) {
        return 1;
    }
    return 0;
}

JNIEXPORT jboolean JNICALL
Java_com_jni_test_jni_NativePrime_isPrime(
        JNIEnv *env, jobject jobj,
        int num) {
    return (jboolean) isPrime(num);
}

JNIEXPORT void JNICALL
Java_com_jni_test_jni_NativePrime_getPrimes(
        JNIEnv *env, jobject jobj,
        jobject jList, jint from, jint to) {
    if (to < from) {
        //Arguments passed in incorrectly.
        return;
    }
    //1.Get size method.
    //2.Call size method.
    //3.Get add method.
    //4.Use add method.

    //Should I use java/util/List???
    jclass jClsList = (*env)->FindClass(env, "java/util/List");
    jmethodID midAdd = (*env)->GetMethodID(env, jClsList, "add", "(Ljava/lang/Object;)Z");

    /**
     * public static java.lang.Integer valueOf(int);
            descriptor: (I)Ljava/lang/Integer;
     */
    jclass jClsInteger = (*env)->FindClass(env, "java/lang/Integer");
    jmethodID midValueOf = (*env)->GetStaticMethodID(env, jClsInteger, "valueOf",
                                                     "(I)Ljava/lang/Integer;");

    for (jint i = from; i <= to; i++) {
        if (isPrime(i)) {
            //Convert java int to java Integer object.
            jobject jInteger = (*env)->CallStaticObjectMethod(env, jClsInteger, midValueOf, i);
            (*env)->CallBooleanMethod(env, jList, midAdd, jInteger);
            (*env)->DeleteLocalRef(env, jInteger);
        }
    }

}

/**
 * Write primes to file.
 * @param env
 * @param jobj
 * @param jList
 */
JNIEXPORT void JNICALL
Java_com_jni_test_jni_NativePrime_savePrimes(
        JNIEnv *env, jobject jobj,
        jobject jList) {
    FILE *file = fopen(path, "w");
    if (file == NULL) {
        //Can not open file!
        LOGW(TAG, "savePrimes-> can not open %s", path);
        return;
    }

    jclass jclsList = (*env)->FindClass(env, "java/util/List");
    jmethodID midSize = (*env)->GetMethodID(env, jclsList, "size", "()I");
    const jint SIZE = (*env)->CallIntMethod(env, jList, midSize);
    if (SIZE < 1) {
        return;
    }

    jmethodID midGet = (*env)->GetMethodID(env, jclsList, "get", "(I)Ljava/lang/Object;");

    jclass jClsInteger = (*env)->FindClass(env, "java/lang/Integer");
    jmethodID midIntValue = (*env)->GetMethodID(env, jClsInteger, "intValue", "()I");
    for (int i = 0; i < SIZE; i++) {
        jobject jInteger = (*env)->CallObjectMethod(env, jList, midGet, i);
        int temp = (*env)->CallIntMethod(env, jInteger, midIntValue);
        fprintf(file, "%d ", temp);
    }
    fclose(file);
}

/**
 * Read primes from file.
 * @param env
 * @param jobj
 * @param jList
 */
JNIEXPORT void JNICALL
Java_com_jni_test_jni_NativePrime_recoveryPrimes(
        JNIEnv *env, jobject jobj,
        jobject jList) {
    FILE *file = fopen(path, "r");
    if (file == NULL) {
        //Can not open file!
        LOGW(TAG, "recoveryPrimes-> can not open %s", path);
        return;
    }
    jclass jClsList = (*env)->FindClass(env, "java/util/List");
    jmethodID midAdd = (*env)->GetMethodID(env, jClsList, "add",
                                           "(Ljava/lang/Object;)Z");

    jclass jClsInteger = (*env)->FindClass(env, "java/lang/Integer");
    jmethodID midValueOf = (*env)->GetStaticMethodID(env, jClsInteger, "valueOf",
                                                     "(I)Ljava/lang/Integer;");
    int temp;
    while (fscanf(file, "%d ", &temp) > 0) {
        jobject jInteger = (*env)->CallStaticObjectMethod(env, jClsInteger, midValueOf, temp);
        (*env)->CallBooleanMethod(env, jList, midAdd, jInteger);
        (*env)->DeleteLocalRef(env, jInteger);
    }
}
