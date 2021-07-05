//
// Created by Nick Lai on 2021/7/4.
//
#include <jni.h>
#include <string.h>
#include <malloc.h>
#include "android_log.h"
#include "file.h"

#define FILENAME  "student.dat"
#define TAG  "student"

jobject jobjList;

char *path;

JNIEXPORT void JNICALL
Java_com_jni_test_jni_NativeStudent_uninit(JNIEnv *env, jobject thiz) {
    if (jobjList != NULL) {
        (*env)->DeleteGlobalRef(env, jobjList);
        jobjList = NULL;
    }
}

JNIEXPORT void JNICALL
Java_com_jni_test_jni_NativeStudent_init(JNIEnv *env, jobject thiz,
                                         jstring jstrDir) {
    Java_com_jni_test_jni_NativeStudent_uninit(env, thiz);
    jclass jclsList = (*env)->FindClass(env, "java/util/ArrayList");
    jmethodID midConstructor = (*env)->GetMethodID(env, jclsList, "<init>", "()V");
    jobject jobjListLocalReference = (*env)->NewObject(env, jclsList, midConstructor);
    jobjList = (*env)->NewGlobalRef(env, jobjListLocalReference);


    const char *dir = (*env)->GetStringUTFChars(env, jstrDir, NULL);
    path = malloc(strlen(dir) + strlen(FILENAME) + 2);
    combinePath(path, dir, FILENAME);
    (*env)->ReleaseStringUTFChars(env, jstrDir, dir);
}


jboolean check(JNIEnv *env, jobject thiz,
               jint number, jstring name,
               jint scoreChinese, jint scoreMath,
               jint scoreEnglish) {
    if (number >= 0
        && strlen(name) > 0
        && scoreChinese >= 0 && scoreChinese <= 100
        && scoreMath >= 0 && scoreMath <= 100
        && scoreEnglish >= 0 && scoreEnglish <= 100) {
        return JNI_TRUE;
    }
    return JNI_FALSE;
}


JNIEXPORT jboolean JNICALL
Java_com_jni_test_jni_NativeStudent_check(JNIEnv *env, jobject thiz,
                                          jstring number, jstring name,
                                          jstring scoreChinese, jstring scoreMath,
                                          jstring scoreEnglish) {
    jclass jclsString = (*env)->FindClass(env, "java/lang/String");
    jmethodID midLength = (*env)->GetMethodID(env, jclsString, "length", "()I");
    if (number == NULL || (*env)->CallIntMethod(env, number, midLength) == 0
        //        || name == NULL || (*env)->CallIntMethod(env, name, midLength) == 0
        || scoreChinese == NULL || (*env)->CallIntMethod(env, scoreChinese, midLength) == 0
        || scoreMath == NULL || (*env)->CallIntMethod(env, scoreMath, midLength) == 0
        || scoreEnglish == NULL || (*env)->CallIntMethod(env, scoreEnglish, midLength) == 0) {
        return JNI_FALSE;
    }
    jclass jclsInteger = (*env)->FindClass(env, "java/lang/Integer");
    jmethodID midValueOf = (*env)->GetStaticMethodID(env, jclsInteger, "valueOf",
                                                     "(Ljava/lang/String;)Ljava/lang/Integer;");
    jobject jIntegerNumber = (*env)->CallStaticObjectMethod(env, jclsInteger, midValueOf, number);
    jobject jIntegerScoreChinese = (*env)->CallStaticObjectMethod(env, jclsInteger, midValueOf,
                                                                  scoreChinese);
    jobject jIntegerScoreMath = (*env)->CallStaticObjectMethod(env, jclsInteger, midValueOf,
                                                               scoreMath);
    jobject jIntegerScoreEnglish = (*env)->CallStaticObjectMethod(env, jclsInteger, midValueOf,
                                                                  scoreEnglish);
    jobject midIntValue = (*env)->GetMethodID(env, jclsInteger, "intValue", "()I");
    jint jintNumber = (*env)->CallIntMethod(env, jIntegerNumber, midIntValue);
    jint jintScoreChinese = (*env)->CallIntMethod(env, jIntegerScoreChinese, midIntValue);
    jint jintScoreMath = (*env)->CallIntMethod(env, jIntegerScoreMath, midIntValue);
    jint jintScoreEnglish = (*env)->CallIntMethod(env, jIntegerScoreEnglish, midIntValue);

    (*env)->DeleteLocalRef(env, jIntegerNumber);
    (*env)->DeleteLocalRef(env, jIntegerScoreChinese);
    (*env)->DeleteLocalRef(env, jIntegerScoreMath);
    (*env)->DeleteLocalRef(env, jIntegerScoreEnglish);

    return check(env, thiz, jintNumber, name, jintScoreChinese, jintScoreMath, jintScoreEnglish);
}

void setStudentValue(JNIEnv *env, jobject jobStu, const char *methodName, jstring jstrValue) {
    jclass clsStudent = (*env)->FindClass(env, "com/jni/test/bean/Student");
    jmethodID midSetter = NULL;
    if (strcmp(methodName, "setNumber") == 0
        || strcmp(methodName, "setScoreChinese") == 0
        || strcmp(methodName, "setScoreMath") == 0
        || strcmp(methodName, "setScoreEnglish") == 0) {
        midSetter = (*env)->GetMethodID(env, clsStudent, methodName, "(I)V");

        jclass clsInteger = (*env)->FindClass(env, "java/lang/Integer");
        jmethodID midParseInt = (*env)->GetStaticMethodID(env, clsInteger, "parseInt",
                                                          "(Ljava/lang/String;)I");
        jint jintValue = (*env)->CallStaticIntMethod(env, clsInteger, midParseInt, jstrValue);
        (*env)->CallVoidMethod(env, jobStu, midSetter, jintValue);

    } else if (strcmp(methodName, "setName") == 0) {
        midSetter = (*env)->GetMethodID(env, clsStudent, methodName, "(Ljava/lang/String;)V");
        (*env)->CallVoidMethod(env, jobStu, midSetter, jstrValue);
    } else if (strcmp(methodName, "setAverage") == 0) {
        midSetter = (*env)->GetMethodID(env, clsStudent, methodName, "(I)V");

        jclass clsIFloat = (*env)->FindClass(env, "java/lang/Float");
        jmethodID midParseFloat = (*env)->GetStaticMethodID(env, clsIFloat, "parseFloat",
                                                            "(Ljava/lang/String;)F");
        jfloat jfltValue = (*env)->CallStaticFloatMethod(env, clsIFloat, midParseFloat, jstrValue);
        (*env)->CallVoidMethod(env, jobStu, midSetter, jfltValue);
    } else {
        LOGW(TAG, "Unknown method name: %s", methodName);
    }
}

jfloat calculateAverage(JNIEnv *env, jobject jobjStu) {
    jclass jclsStudent = (*env)->FindClass(env, "com/jni/test/bean/Student");

    jmethodID midGetScoreChinese = (*env)->GetMethodID(env, jclsStudent, "getScoreChinese", "()I");
    jmethodID midGetScoreMath = (*env)->GetMethodID(env, jclsStudent, "getScoreMath", "()I");
    jmethodID midGetScoreEnglish = (*env)->GetMethodID(env, jclsStudent, "getScoreEnglish", "()I");

    jint scoreChinese = (*env)->CallIntMethod(env, jobjStu, midGetScoreChinese);
    jint scoreMath = (*env)->CallIntMethod(env, jobjStu, midGetScoreMath);
    jint scoreEnglish = (*env)->CallIntMethod(env, jobjStu, midGetScoreEnglish);

    jfloat jfltAverage = (scoreChinese + scoreMath + scoreEnglish) * 1.0F / 3;

    return jfltAverage;
}

JNIEXPORT void JNICALL
Java_com_jni_test_jni_NativeStudent_add(JNIEnv *env, jobject thiz,
                                        jstring number, jstring name,
                                        jstring scoreChinese, jstring scoreMath,
                                        jstring scoreEnglish) {

    jclass jclsStudent = (*env)->FindClass(env, "com/jni/test/bean/Student");
    jmethodID midConstructor = (*env)->GetMethodID(env, jclsStudent, "<init>", "()V");
    jobject jobjStu = (*env)->NewObject(env, jclsStudent, midConstructor);

    setStudentValue(env, jobjStu, "setNumber", number);
    setStudentValue(env, jobjStu, "setName", name);
    setStudentValue(env, jobjStu, "setScoreChinese", scoreChinese);
    setStudentValue(env, jobjStu, "setScoreMath", scoreMath);
    setStudentValue(env, jobjStu, "setScoreEnglish", scoreEnglish);
    jfloat jfltAverage = calculateAverage(env, jobjStu);
    jmethodID midSetAverage = (*env)->GetMethodID(env, jclsStudent, "setAverage", "(F)V");
    (*env)->CallVoidMethod(env, jobjStu, midSetAverage, jfltAverage);

    jobject jclsList = (*env)->FindClass(env, "java/util/List");
    jmethodID midAdd = (*env)->GetMethodID(env, jclsList, "add", "(Ljava/lang/Object;)Z");
    (*env)->CallBooleanMethod(env, jobjList, midAdd, jobjStu);
}

JNIEXPORT jobject JNICALL
Java_com_jni_test_jni_NativeStudent_getStudentList(JNIEnv *env, jobject thiz) {
    return jobjList;
}


JNIEXPORT void JNICALL
Java_com_jni_test_jni_NativeStudent_delete__I(JNIEnv *env, jobject thiz, jint number) {
    jclass jclsList = (*env)->FindClass(env, "java/util/List");
    jmethodID midSize = (*env)->GetMethodID(env, jclsList, "size", "()I");
    jmethodID midGet = (*env)->GetMethodID(env, jclsList, "get", "(I)Ljava/lang/Object;");
    jint size = (*env)->CallIntMethod(env, jobjList, midSize);

    jclass jclsStudent = (*env)->FindClass(env, "com/jni/test/bean/Student");
    jmethodID midGetNumber = (*env)->GetMethodID(env, jclsStudent, "getNumber", "()I");

    for (int i = 0; i < size; ++i) {
        jobject jobjStu = (*env)->CallObjectMethod(env, jobjList, midGet, i);
        jint anotherNumber = (*env)->CallIntMethod(env, jobjStu, midGetNumber);
        if (number == anotherNumber) {
            jmethodID midRemove = (*env)->GetMethodID(env, jclsList, "remove",
                                                      "(I)Ljava/lang/Object;");
            (*env)->CallObjectMethod(env, jobjList, midRemove, i);
            break;
        }
    }
}

JNIEXPORT void JNICALL
Java_com_jni_test_jni_NativeStudent_delete__Ljava_lang_String_2(JNIEnv *env, jobject thiz,
                                                                jstring jstrNumber) {
    jclass jclsInteger = (*env)->FindClass(env, "java/lang/Integer");
    jmethodID midParseInt = (*env)->GetStaticMethodID(env, jclsInteger, "parseInt",
                                                      "(Ljava/lang/String;)I");
    jint number = (*env)->CallStaticIntMethod(env, jclsInteger, midParseInt, jstrNumber);
    Java_com_jni_test_jni_NativeStudent_delete__I(env, thiz, number);
}

JNIEXPORT void JNICALL
Java_com_jni_test_jni_NativeStudent_store(JNIEnv *env, jobject thiz) {
    //Delete old data first.
    FILE *file = fopen(path, "w");
    if (file == NULL) {
        LOGW(TAG, "Can not open file: %s", path);
        return;
    }
    jclass jclsList = (*env)->FindClass(env, "java/util/List");
    jmethodID midSize = (*env)->GetMethodID(env, jclsList, "size", "()I");
    jmethodID midGet = (*env)->GetMethodID(env, jclsList, "get", "(I)Ljava/lang/Object;");
    jint size = (*env)->CallIntMethod(env, jobjList, midSize);
    if (size <= 0) {
        fclose(file);
        LOGI(TAG, "No data for storing!");
        return;
    }

    jclass jclsStu = (*env)->FindClass(env, "com/jni/test/bean/Student");
    jmethodID midGetNumber = (*env)->GetMethodID(env, jclsStu, "getNumber", "()I");
    jmethodID midGetName = (*env)->GetMethodID(env, jclsStu, "getName", "()Ljava/lang/String;");
    jmethodID midGetScoreChinese = (*env)->GetMethodID(env, jclsStu, "getScoreChinese", "()I");
    jmethodID midGetScoreMath = (*env)->GetMethodID(env, jclsStu, "getScoreMath", "()I");
    jmethodID midGetScoreEnglish = (*env)->GetMethodID(env, jclsStu, "getScoreEnglish", "()I");
    jmethodID midGetScoreAverage = (*env)->GetMethodID(env, jclsStu, "getAverage", "()F");

    for (int i = 0; i < size; ++i) {
        jobject jobjStu = (*env)->CallObjectMethod(env, jobjList, midGet, i);
        jint number = (*env)->CallIntMethod(env, jobjStu, midGetNumber);
        jint scoreChinese = (*env)->CallIntMethod(env, jobjStu, midGetScoreChinese);
        jint scoreMath = (*env)->CallIntMethod(env, jobjStu, midGetScoreMath);
        jint scoreEnglish = (*env)->CallIntMethod(env, jobjStu, midGetScoreEnglish);
        jfloat average = (*env)->CallFloatMethod(env, jobjStu, midGetScoreAverage);
        jstring jstrName = (*env)->CallObjectMethod(env, jobjStu, midGetName);
        const char *name = (*env)->GetStringUTFChars(env, jstrName, NULL);

        fprintf(file, "%d %s %d %d %d %f\n",
                number, name, scoreChinese, scoreMath, scoreEnglish, average);

    }
    fclose(file);
}

JNIEXPORT void JNICALL
Java_com_jni_test_jni_NativeStudent_recover(JNIEnv *env, jobject thiz) {
    FILE *file = fopen(path, "r");
    if (file == NULL) {
        LOGW(TAG, "Can not open file: %s", path);
        return;
    }
    jclass jclsList = (*env)->FindClass(env, "java/util/List");
    jmethodID midAdd = (*env)->GetMethodID(env, jclsList, "add", "(Ljava/lang/Object;)Z");

    jint number, scoreChinese, scoreMath, scoreEnglish;
    jfloat average;
    char name[100];
    //scanf/fscanf can not assign string value to name pointer.
    //char *name;
    jclass jclsStu = (*env)->FindClass(env, "com/jni/test/bean/Student");
    jmethodID midConstructor = (*env)->GetMethodID(env, jclsStu, "<init>", "()V");
    jmethodID midSetNumber = (*env)->GetMethodID(env, jclsStu, "setNumber", "(I)V");
    jmethodID midSetName = (*env)->GetMethodID(env, jclsStu, "setName", "(Ljava/lang/String;)V");
    jmethodID midSetScoreChinese = (*env)->GetMethodID(env, jclsStu, "setScoreChinese", "(I)V");
    jmethodID midSetScoreMath = (*env)->GetMethodID(env, jclsStu, "setScoreMath", "(I)V");
    jmethodID midSetScoreEnglish = (*env)->GetMethodID(env, jclsStu, "setScoreEnglish", "(I)V");
    jmethodID midSetScoreAverage = (*env)->GetMethodID(env, jclsStu, "setAverage", "(F)V");

    while (fscanf(file, "%d %s %d %d %d %f",
                  &number, name, &scoreChinese, &scoreMath, &scoreEnglish, &average)
           > 0) {
        jobject jobjStu = (*env)->NewObject(env, jclsStu, midConstructor);
        (*env)->CallVoidMethod(env, jobjStu, midSetNumber, number);
        jstring jstrName = (*env)->NewStringUTF(env, name);
        (*env)->CallVoidMethod(env, jobjStu, midSetName, jstrName);
        (*env)->CallVoidMethod(env, jobjStu, midSetScoreChinese, scoreChinese);
        (*env)->CallVoidMethod(env, jobjStu, midSetScoreMath, scoreMath);
        (*env)->CallVoidMethod(env, jobjStu, midSetScoreEnglish, scoreEnglish);
        (*env)->CallVoidMethod(env, jobjStu, midSetScoreAverage, average);

        (*env)->CallBooleanMethod(env, jobjList, midAdd, jobjStu);
    }

    fclose(file);
}