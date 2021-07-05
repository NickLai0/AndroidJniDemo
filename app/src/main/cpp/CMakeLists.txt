cmake_minimum_required(VERSION 3.4.1)

add_library(mytest SHARED

        android_log.h

        stringTest.c
        prime.c
        student.c

        file.h
        file.c

        )

# Include libraries needed for hello-jni lib
target_link_libraries(mytest
#                      android
                      log)
