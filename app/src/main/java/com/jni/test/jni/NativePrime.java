package com.jni.test.jni;

import java.util.ArrayList;
import java.util.List;

public class NativePrime extends BaseMyTestLibary {

    private List<Integer> mList = new ArrayList<>();

//    public List<Integer> getPrimeList() {
//        return mList;
//    }

    public int size() {
        return mList.size();
    }

    public void clear() {
        mList.clear();
    }

    public String genPrimeString() {
        return mList.toString();
    }

    @Override
    public String toString() {
        return genPrimeString();
    }

    public List<Integer> getPrimes(int from, int to) {
        mList.clear();
        getPrimes(mList, from, to);
        return mList;
    }

    public void savePrimes() {
        savePrimes(mList);
    }

    public void recoverPrimes() {
        mList.clear();
        recoverPrimes(mList);
    }


    public native void init(String dir);

    public native void uninit();

    public native boolean isPrime(int num);

    public native void getPrimes(List<Integer> list, int from, int to);

    public native void savePrimes(List<Integer> list);

    public native void recoverPrimes(List<Integer> list);

}
