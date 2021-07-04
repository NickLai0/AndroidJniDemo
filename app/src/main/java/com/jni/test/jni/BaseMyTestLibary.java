package com.jni.test.jni;

import com.jni.test.util.L;

public class BaseMyTestLibary {
    static {
        L.i("BaseMyTestLibary", "Loading libmytest.so library.");
        System.loadLibrary("mytest");
    }
}
