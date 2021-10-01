cmake_minimum_required(VERSION 3.4.1)

#Can not use test as the .so library name.
add_library(mytest SHARED
        charCount.c
        file/writeBinaryAndTextData.c
        file/freadTest.c
        file/printTextFile.c
        file/fputcRetrieveTest.c
        smallestGeneratedTree.c
        )