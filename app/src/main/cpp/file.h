//
// Created by Nick Lai on 2021/7/4.
//

#ifndef MY_APPLICATION_FILE_H
#define MY_APPLICATION_FILE_H

#include <jni.h>

extern char *generateAbsPath(JNIEnv *env, jstring jstrDir, jstring jstrFilename);

extern void combinePath(const char *path,const  char *dir, const char *filename);

#endif //MY_APPLICATION_FILE_H