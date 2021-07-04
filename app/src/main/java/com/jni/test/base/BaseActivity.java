package com.jni.test.base;

import android.os.Bundle;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

public abstract class BaseActivity extends AppCompatActivity {

    protected final String TAG = getClass().getSimpleName();

    @Override
    protected void onCreate(@Nullable @org.jetbrains.annotations.Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(getLayoutId());
        initViews();
        initData();
        initListener();
    }

    protected abstract int getLayoutId();

    protected abstract void initViews();

    protected abstract void initData();

    protected abstract void initListener();

    private boolean mOnFinishedCalled = false;

    @Override
    public void finish() {
        super.finish();
        if (!mOnFinishedCalled) {
            onFinish();
            mOnFinishedCalled = true;
        }
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        if (!mOnFinishedCalled) {
            onFinish();
            mOnFinishedCalled = true;
        }
    }

    /**
     * Release resources immediately in this method.
     */
    protected void onFinish() {
    }
}
