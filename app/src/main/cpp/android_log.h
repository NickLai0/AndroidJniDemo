//
// Created by Nick Lai on 2021/7/4.
//


#ifndef MY_APPLICATION_ANDROID_LOG_H
#define MY_APPLICATION_ANDROID_LOG_H

//Even #include instruction should be included in here.
#include <android/log.h>

#define LOGE(TAG, ...) __android_log_print(ANDROID_LOG_ERROR,    TAG, __VA_ARGS__)
#define LOGW(TAG, ...) __android_log_print(ANDROID_LOG_WARN,     TAG, __VA_ARGS__)
#define LOGI(TAG, ...) __android_log_print(ANDROID_LOG_INFO,     TAG, __VA_ARGS__)
#define LOGD(TAG, ...) __android_log_print(ANDROID_LOG_DEBUG,    TAG, __VA_ARGS__)

#endif //MY_APPLICATION_ANDROID_LOG_H
