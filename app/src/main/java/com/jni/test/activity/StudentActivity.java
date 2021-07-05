package com.jni.test.activity;

import android.app.Activity;
import android.content.Intent;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

import com.jni.test.R;
import com.jni.test.activity.base.BaseActivity;
import com.jni.test.bean.Student;
import com.jni.test.jni.NativeStudent;
import com.jni.test.util.TU;
import com.jni.test.util.ToastUtils;

import org.jetbrains.annotations.NotNull;

import java.util.List;

public class StudentActivity extends BaseActivity implements View.OnClickListener {

    private EditText mEdNumber;
    private EditText mEdName;
    private EditText mEdScoreChiense;
    private EditText mEdScoreMath;
    private EditText mEdScoreEnglish;
    private EditText mEtDeleteNumber;

    private Button mBtnAdd;
    private Button mBtnDelete;
    private Button mBtnStore;
    private Button mBtnRecover;

    private TextView mTvRemaining;
    private TextView mTvStudentsInformation;
    private NativeStudent mNativeStudent;

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
        mEtDeleteNumber = findViewById(R.id.as_et_delete_number);
        mBtnDelete = findViewById(R.id.as_btn_delete);
        mBtnStore = findViewById(R.id.as_btn_store);
        mBtnRecover = findViewById(R.id.as_btn_recover);
        mTvRemaining = findViewById(R.id.as_tv_remaining);
        mTvStudentsInformation = findViewById(R.id.as_tv_students_information);
    }

    @Override
    protected void initData() {
        mNativeStudent = new NativeStudent();
        mNativeStudent.init(getFilesDir().toString());
        mNativeStudent.recover();
        showInformation();
    }

    @Override
    protected void onFinish() {
        mNativeStudent.store();
        mNativeStudent.uninit();
    }

    @Override
    protected void initListener() {
//        mEdNumber.addTextChangedListener(mTextWatcher);
//        mEdName.addTextChangedListener(mTextWatcher);
//        mEdScoreChiense.addTextChangedListener(mTextWatcher);
//        mEdScoreMath.addTextChangedListener(mTextWatcher);
//        mEdScoreEnglish.addTextChangedListener(mTextWatcher);

        mBtnAdd.setOnClickListener(this);
        mBtnDelete.setOnClickListener(this);
        mBtnStore.setOnClickListener(this);
        mBtnRecover.setOnClickListener(this);
    }

//    private TextWatcher mTextWatcher = new TextWatcherAdapter() {
//        @Override
//        public void afterTextChanged(Editable s) {
//        }
//    };

    @Override
    public void onClick(View v) {
        switch (v.getId()) {
            case R.id.as_btn_add: {
                String number = mEdNumber.getText().toString();
                String name = mEdName.getText().toString();
                String scoreChinese = mEdScoreChiense.getText().toString();
                String scoreMath = mEdScoreMath.getText().toString();
                String scoreEnglish = mEdScoreEnglish.getText().toString();
                if (mNativeStudent.check(number, name, scoreChinese, scoreMath, scoreEnglish)) {
                    mNativeStudent.add(number, name, scoreChinese, scoreMath, scoreEnglish);
                    showInformation();
                } else {
                    ToastUtils.showShort(this, "Data uncompleted or wrong!");
                }
            }
            break;

            case R.id.as_btn_delete: {
                String number = mEtDeleteNumber.getText().toString();
                if (!TU.isEmpty(number)) {
                    mNativeStudent.delete(number);
                    showInformation();
                }
            }
            break;
            case R.id.as_btn_store: {
                mNativeStudent.store();
            }
            break;
            case R.id.as_btn_recover: {
                //mNativeStudent.recover();
            }
            break;
        }
    }

    private StringBuilder mSb = new StringBuilder();

    private void showInformation() {
        List<Student> list = mNativeStudent.getStudentList();
        mSb.setLength(0);
        for (int i = 0; i < list.size(); i++) {
            Student stu = list.get(i);
            mSb
                    .append("Number: ").append(stu.getNumber()).append('\n')
                    .append("Name: ").append(stu.getName()).append('\n')
                    .append("Chinese: ").append(stu.getScoreChinese()).append('\n')
                    .append("Math: ").append(stu.getScoreMath()).append('\n')
                    .append("English: ").append(stu.getScoreEnglish()).append('\n')
                    .append("Average: ").append(stu.getAverage()).append('\n')
                    .append("\n\n")
            ;
        }
        mTvRemaining.setText("There are " + list.size() + " students.");
        mTvStudentsInformation.setText(mSb.toString());
    }


}
