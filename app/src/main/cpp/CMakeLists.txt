cmake_minimum_required(VERSION 3.4.1)

add_library(mytest SHARED

        android_log.h

        stringTest.c
        prime.c
        student.c

        file.h
        file.c

        storeutils/ArrayList.h
        storeutils/ArrayList.c
        storeutils/LinkedList.h
        storeutils/LinkedList.c
        storeutils/ArrayStack.h
        storeutils/ArrayStack.c

        log/log.h
        log/log.c

        test/testArrayList.c
        test/testLinkedList.c
        test/testArrayStack.c
        test/storeDifferentPointerTypes.c
        )

# Include libraries needed for hello-jni lib
target_link_libraries(mytest
        #                      android
        log)
