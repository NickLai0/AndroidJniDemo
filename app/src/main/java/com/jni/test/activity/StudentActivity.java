package com.jni.test.activity;

import android.app.Activity;
import android.content.Intent;
import android.text.Editable;
import android.text.TextWatcher;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

import com.jni.test.R;
import com.jni.test.adapter.TextWatcherAdapter;
import com.jni.test.base.BaseActivity;
import com.jni.test.jni.NativeStudent;

import org.jetbrains.annotations.NotNull;

public class StudentActivity extends BaseActivity {

    private EditText mEdNumber;
    private EditText mEdName;
    private EditText mEdScoreChiense;
    private EditText mEdScoreMath;
    private EditText mEdScoreEnglish;
    private EditText mEtNumberIWannaDelete;

    private Button mBtnAdd;
    private Button mBtnDelete;

    private TextView mTvRemaining;
    private TextView mTvStudentsInformation;
    private NativeStudent mStudent;

    public static void start(@NotNull Activity a) {
        Intent intent = new Intent(a, StudentActivity.class);
        a.startActivity(intent);
    }

    @Override
    protected int getLayoutId() {
        return R.layout.activity_student;
    }

    @Override
    protected void initViews() {
        mEdNumber = findViewById(R.id.as_et_number);
        mEdName = findViewById(R.id.as_et_name);
        mEdScoreChiense = findViewById(R.id.as_et_score_chinese);
        mEdScoreMath = findViewById(R.id.as_et_score_math);
        mEdScoreEnglish = findViewById(R.id.as_et_score_english);
        mBtnAdd = findViewById(R.id.as_btn_add);
        mEtNumberIWannaDelete = findViewById(R.id.as_et_number_i_wanna_delete);
        mBtnDelete = findViewById(R.id.as_btn_delete);
        mTvRemaining = findViewById(R.id.as_tv_remaining);
        mTvStudentsInformation = findViewById(R.id.as_tv_students_information);
    }

    @Override
    protected void initData() {
        mStudent = new NativeStudent(this);
    }

    @Override
    protected void initListener() {
        mEdNumber.addTextChangedListener(mTextWatcher);
        mEdName.addTextChangedListener(mTextWatcher);
        mEdScoreChiense.addTextChangedListener(mTextWatcher);
        mEdScoreMath.addTextChangedListener(mTextWatcher);
        mEdScoreEnglish.addTextChangedListener(mTextWatcher);
    }

    private TextWatcher mTextWatcher = new TextWatcherAdapter() {
        @Override
        public void afterTextChanged(Editable s) {
            //todo:xxx What should I do in the method?
        }
    };

}
