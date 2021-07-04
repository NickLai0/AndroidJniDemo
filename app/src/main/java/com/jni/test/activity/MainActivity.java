package com.jni.test.activity;

import android.view.View;
import android.widget.Button;

import com.jni.test.R;
import com.jni.test.base.BaseActivity;


public class MainActivity extends BaseActivity implements View.OnClickListener {

    private Button mBtnPrime;
    private Button mBtnStudent;

    @Override
    protected int getLayoutId() {
        return R.layout.activity_main;
    }

    @Override
    protected void initViews() {
        //Initial views.
        mBtnPrime = findViewById(R.id.ab_btn_prime);
        mBtnStudent = findViewById(R.id.ab_btn_student);
    }

    @Override
    protected void initData() {
        //L.i(TAG, "initData -> new StringTest().get() = " + new StringTest().get());
//        List<Integer> integers = new ArrayList<>();
//        for (int i = 0; i < 100000 / 2; i++) {
//            integers.add(i + 1);
//        }
//        mTv.setText(integers.toString());
    }

    @Override
    protected void initListener() {
        //Set listener.
        mBtnPrime.setOnClickListener(this);
        mBtnStudent.setOnClickListener(this);
    }

    @Override
    public void onClick(View v) {
        switch (v.getId()) {
            case R.id.ab_btn_prime:
                PrimeActivity.start(this);
                break;
            case R.id.ab_btn_student:
                StudentActivity.start(this);
                break;
        }
    }
}