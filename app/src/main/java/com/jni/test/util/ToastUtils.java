package com.jni.test.util;

import android.content.Context;
import android.widget.Toast;

public class ToastUtils {
    public static void showShort(Context c, String msg) {
        Toast.makeText(c, msg, Toast.LENGTH_SHORT).show();
    }

    public static void showLong(Context c, String msg) {
        Toast.makeText(c, msg, Toast.LENGTH_LONG).show();
    }
}
