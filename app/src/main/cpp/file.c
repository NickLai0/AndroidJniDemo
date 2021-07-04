//
// Created by Nick Lai on 2021/7/4.
//
#include <string.h>
#include <malloc.h>
#include "file.h"

char *generateAbsPath(JNIEnv *env, jstring jstrDir, jstring jstrFilename) {
    const char *dir = (*env)->GetStringUTFChars(env, jstrDir, NULL);
    const char *filename = (*env)->GetStringUTFChars(env, jstrFilename, NULL);
    int dirLen = strlen(dir);
    int filenameLen = strlen(filename);
    //There are two extra characters ('/' and '\0').
    int absPathLen = dirLen + filenameLen + 2;
    char *absPath = malloc(absPathLen);
    strcpy(absPath, dir);
    strcat(absPath, "/");
    strcat(absPath, filename);
//    LOGI(TAG, "generateAbsPath-> absPath=%s", absPath);
//    LOGI(TAG, "generateAbsPath-> before release: jstrDir=%d, jstrFilename=%d", jstrDir,
//         jstrFilename);
//    LOGI(TAG, "generateAbsPath-> before release: dir=%d, filename=%d", dir, filename);
    (*env)->ReleaseStringUTFChars(env, jstrDir, dir);
    (*env)->ReleaseStringUTFChars(env, jstrFilename, filename);
//    LOGI(TAG, "generateAbsPath-> after release: jstrDir=%d, jstrFilename=%d", jstrDir,
//         jstrFilename);
//    LOGI(TAG, "generateAbsPath-> after release: dir=%d, filename=%d", dir, filename);
    return absPath;
}

void combinePath(const char *path, const char *dir,const  char *filename) {
    strcpy(path, dir);
    strcat(path, "/");
    strcat(path, filename);
}