package com.jni.test.util;

import android.util.Log;

public final class L {

    public static final int V = Log.VERBOSE;
    public static final int D = Log.DEBUG;
    public static final int I = Log.INFO;
    public static final int W = Log.WARN;
    public static final int E = Log.ERROR;
    public static final int DISABLE = Log.ASSERT + 1;

    //Output all of log by default.
    private static int sLevel = E;

    /**
     * Set output level for all logs.
     *
     * @param level the value from constant V to DISABLE.
     */
    public static void setLevel(int level) {
        sLevel = level;
    }

    public static void v(String tag, String msg) {
        if (sLevel >= V) {
            Log.v(tag, msg);
        }
    }

    public static void d(String tag, String msg) {
        if (sLevel >= D) {
            Log.v(tag, msg);
        }
    }

    public static void i(String tag, String msg) {
        if (sLevel >= I) {
            Log.v(tag, msg);
        }
    }

    public static void w(String tag, String msg) {
        if (sLevel >= W) {
            Log.d(tag, msg);
        }
    }
    public static void e(String tag, String msg) {
        if (sLevel >= E) {
            Log.e(tag, msg);
        }
    }

}
