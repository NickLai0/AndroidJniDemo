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
        storeutils/LinkedStack.h
        storeutils/LinkedStack.c
        storeutils/ArrayQueue.c
        storeutils/ArrayQueue.h
        storeutils/LinkedQueue.c
        storeutils/LinkedQueue.h


        log/log.h
        log/log.c

        test/testArrayList.c
        test/testLinkedList.c
        test/testArrayStack.c
        test/testLinkedStack.c
        test/testArrayQueue.c
        test/testLinkedQueue.c
        test/storeDifferentPointerTypes.c
        )

# Include libraries needed for hello-jni lib
target_link_libraries(mytest
        #                      android
        log)
