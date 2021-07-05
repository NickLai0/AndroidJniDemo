package com.jni.test.activity;

import android.app.Activity;
import android.content.Intent;
import android.text.Editable;
import android.text.TextWatcher;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

import com.jni.test.R;
import com.jni.test.adapter.TextWatcherAdapter;
import com.jni.test.activity.base.BaseActivity;
import com.jni.test.jni.NativePrime;
import com.jni.test.util.TU;
import com.jni.test.util.ToastUtils;

public class PrimeActivity extends BaseActivity implements View.OnClickListener {

    private EditText mEtFromNumber;
    private EditText mEtToNumber;

    private Button mBtnSavePrimes;
    private Button mBtnRecoverPrimes;

    private TextView mTvPrimes;

    private NativePrime mNativePrime;

    public static void start(Activity a) {
        Intent intent = new Intent(a, PrimeActivity.class);
        a.startActivity(intent);
    }

    @Override
    protected int getLayoutId() {
        return R.layout.activity_prime;
    }

    @Override
    protected void initViews() {
        mEtFromNumber = findViewById(R.id.ap_et_from);
        mEtToNumber = findViewById(R.id.ap_et_to);
        mBtnSavePrimes = findViewById(R.id.ap_btn_save_primes);
        mBtnRecoverPrimes = findViewById(R.id.ap_btn_recover_primes);
        mTvPrimes = findViewById(R.id.ap_tv_primes);
    }

    @Override
    protected void initData() {
        mNativePrime = new NativePrime();
        mNativePrime.init(getFilesDir().getAbsolutePath());
    }

    @Override
    protected void initListener() {
        mEtFromNumber.addTextChangedListener(mTextWatcher);
        mEtToNumber.addTextChangedListener(mTextWatcher);
        mBtnSavePrimes.setOnClickListener(this);
        mBtnRecoverPrimes.setOnClickListener(this);
    }

    private TextWatcher mTextWatcher = new TextWatcherAdapter() {
        @Override
        public void afterTextChanged(Editable s) {
            String fromNumber = mEtFromNumber.getText().toString();
            String toNumber = mEtToNumber.getText().toString();
            mNativePrime.clear();
            if (TU.isEmpty(fromNumber) || TU.isEmpty(toNumber)) {
                mTvPrimes.setText(null);
            } else {
                int from = Integer.parseInt(fromNumber);
                int to = Integer.parseInt(toNumber);
                mNativePrime.getPrimes(from, to);
                mTvPrimes.setText(mNativePrime.toString());
            }
        }
    };

    @Override
    public void onClick(View v) {
        switch (v.getId()) {
            case R.id.ap_btn_save_primes:
                if (mNativePrime.size() == 0) {
                    ToastUtils.showShort(this, "There is no prime!");
                } else {
                    if (mNativePrime.size() > 0) {
                        mNativePrime.savePrimes();
                        ToastUtils.showShort(this, "Primes saved!");
                    } else {
                        ToastUtils.showShort(this, "No primes!");
                    }
                }
                break;

            case R.id.ap_btn_recover_primes:
                mNativePrime.recoverPrimes();
                mTvPrimes.setText(mNativePrime.toString());
                break;
        }
    }

    @Override
    protected void onFinish() {
        mNativePrime.uninit();
    }
}
