package com.jni.test.jni;

import android.content.Context;

import org.jetbrains.annotations.NotNull;

import java.util.ArrayList;
import java.util.List;

public class NativePrime extends BaseMyTestLibary {
    public native void init(String dir);
    public native void uninit();
    public native boolean isPrime(int num);
    public native void getPrimes(List<Integer> list, int from, int to);
    public native void savePrimes(List<Integer> list);
    public native void recoveryPrimes(List<Integer> list);
}
