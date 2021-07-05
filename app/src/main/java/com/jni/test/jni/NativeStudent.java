package com.jni.test.jni;

import com.jni.test.bean.Student;

import java.util.List;

public class NativeStudent extends BaseMyTestLibary {

    public native void init(String dir);

    public native void uninit();

    public native boolean check(String number, String name, String scoreChinese, String scoreMath, String scoreEnglish);

    public native void add(String number, String name, String scoreChinese, String scoreMath, String scoreEnglish);

    public native void delete(String number);

    public native void delete(int number);

    public native List<Student> getStudentList();


    public native void store();

    public native void recover();
}
