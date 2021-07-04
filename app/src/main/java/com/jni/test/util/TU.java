package com.jni.test.util;

import android.text.TextUtils;

public final class TU {

    public static boolean isEmpty(CharSequence str) {
        return TextUtils.isEmpty(str);
    }

    public static boolean isDigitalOnly(CharSequence str) {
        return TextUtils.isDigitsOnly(str);
    }

}
