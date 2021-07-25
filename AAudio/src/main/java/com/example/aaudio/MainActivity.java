package com.example.aaudio;

import android.content.Context;
import android.content.res.AssetManager;
import android.media.AudioManager;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Spinner;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityCompat;

import com.example.aaudio.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity implements ActivityCompat.OnRequestPermissionsResultCallback {
    static {
        System.loadLibrary("NAAudio");
    }

    private static final String TAG = "MainActivity";

    private static final int AUDIO_ECHO_REQUEST = 0;

    static final int CLIP_NONE = 0;
    static final int CLIP_HELLO = 1;
    static final int CLIP_ANDROID = 2;
    static final int CLIP_SAWTOOTH = 3;
    static final int CLIP_PLAYBACK = 4;


    private ActivityMainBinding binding = null;
    private AssetManager assetManager = null;
    private String URI = null;

    private boolean isPlayingAsset = false;
    private boolean isPlayingUri = false;

    private int numChannelsUri = 0;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        // 1- init native audio system
        createEngine();


        // 2-
        {
            int sampleRate = 0;
            int bufferSize = 0;
            AudioManager am = (AudioManager) getSystemService(Context.AUDIO_SERVICE);
            String strSampleRateParam = am.getProperty(AudioManager.PROPERTY_OUTPUT_SAMPLE_RATE);
            sampleRate = Integer.parseInt(strSampleRateParam);

            String strBufferSizeParam = am.getProperty(AudioManager.PROPERTY_OUTPUT_FRAMES_PER_BUFFER);
            bufferSize = Integer.parseInt(strBufferSizeParam);

            // Log.d(TAG, "System Audio Param: sampleRate=" + sampleRate + ", bufferSize=" + bufferSize);

            createBufferQueueAudioPlayer(sampleRate, bufferSize);
        }

        // 3-
        Spinner uriSpinner = binding.uriSpinner;
        ArrayAdapter<CharSequence> uriAdapter = ArrayAdapter.createFromResource(
                this, R.array.uri_spinner_array, android.R.layout.simple_spinner_item);
        uriAdapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        uriSpinner.setAdapter(uriAdapter);
        uriSpinner.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                URI = parent.getItemAtPosition(position).toString();
            }

            @Override
            public void onNothingSelected(AdapterView<?> parent) {
                URI = null;
            }
        });


        ////  // Example of a call to a native method
        ////  TextView tv = binding.sampleText;
        ////  tv.setText(stringFromJNI());
    }

    @Override
    protected void onPause() {
        selectClip(CLIP_NONE, 0);

        isPlayingAsset = false;
        setPlayingAssetAudioPlayer(false);

        isPlayingUri = false;
        setPlayingUriAudioPlayer(false);

        super.onPause();
    }

    @Override
    protected void onDestroy() {
        //shutdown();
        super.onDestroy();
    }

    @Override
    public void onRequestPermissionsResult(int requestCode, @NonNull String[] permissions, @NonNull int[] grantResults) {
        super.onRequestPermissionsResult(requestCode, permissions, grantResults);
    }


    private boolean created = false;

    private void recordAudio() {
        if (!created) {
            created = createAudioRecorder();
        }

        if (created) {
            startRecording();
        }
    }


    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    // native function
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    /**
     * Native methods, implemented in jni folder
     */
    private static native void createEngine();

    private static native void createBufferQueueAudioPlayer(int sampleRate, int samplesPerBuf);

    private static native boolean createAssetAudioPlayer(AssetManager assetManager, String filename);

    // true == PLAYING, false == PAUSED
    private static native void setPlayingAssetAudioPlayer(boolean isPlaying);

    private static native boolean createUriAudioPlayer(String uri);

    private static native void setPlayingUriAudioPlayer(boolean isPlaying);

    private static native void setLoopingUriAudioPlayer(boolean isLooping);

    private static native void setChannelMuteUriAudioPlayer(int chan, boolean mute);

    private static native void setChannelSoloUriAudioPlayer(int chan, boolean solo);

    private static native int getNumChannelsUriAudioPlayer();

    private static native void setVolumeUriAudioPlayer(int millibel);

    private static native void setMuteUriAudioPlayer(boolean mute);

    private static native void enableStereoPositionUriAudioPlayer(boolean enable);

    private static native void setStereoPositionUriAudioPlayer(int permille);

    private static native boolean selectClip(int which, int count);

    private static native boolean enableReverb(boolean enabled);

    private static native boolean createAudioRecorder();

    private static native void startRecording();

    private static native void shutdown();
}