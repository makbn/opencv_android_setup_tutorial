package ir.whiteapp.maremat;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

public class Main2Activity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main2);
        System.loadLibrary("native-lib");
        ((TextView)findViewById(R.id.txt_jni)).setText(Inpainting.test(1));
    }
}
