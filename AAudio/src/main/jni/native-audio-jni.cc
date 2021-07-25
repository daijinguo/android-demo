
#include "Logger.hpp"

#include <jni.h>
#include <string>

//extern "C" JNIEXPORT jstring JNICALL
//Java_com_example_aaudio_MainActivity_stringFromJNI(
//        JNIEnv *env,
//        jobject /* this */) {
//    std::string hello = "Hello from C++";
//    return env->NewStringUTF(hello.c_str());
//}


extern "C" JNIEXPORT void JNICALL
Java_com_example_aaudio_MainActivity_createEngine(JNIEnv *env, jclass clazz) {
    LOGV("log-1");
    LOGD("log-2");
    LOGI("log-3");
    LOGW("log-4");
    LOGE("log-5");
}

extern "C" JNIEXPORT void JNICALL
Java_com_example_aaudio_MainActivity_createBufferQueueAudioPlayer(
        JNIEnv *env, jclass clazz,
        jint sample_rate,
        jint samples_per_buf) {
    LOGI("sample_rate=%d sample_pre_buf=%d", sample_rate, samples_per_buf);
}

extern "C" JNIEXPORT jboolean JNICALL
Java_com_example_aaudio_MainActivity_createAssetAudioPlayer(
        JNIEnv *env, jclass clazz,
        jobject asset_manager,
        jstring filename) {
    // TODO: implement createAssetAudioPlayer()
    return JNI_TRUE;
}

extern "C" JNIEXPORT void JNICALL
Java_com_example_aaudio_MainActivity_setPlayingAssetAudioPlayer(
        JNIEnv *env, jclass clazz,
        jboolean is_playing) {
    LOGI("is_playing=%d", is_playing ? 1 : 0);
}

extern "C" JNIEXPORT jboolean JNICALL
Java_com_example_aaudio_MainActivity_createUriAudioPlayer(
        JNIEnv *env, jclass clazz, jstring uri) {


    return JNI_TRUE;
}

extern "C" JNIEXPORT void JNICALL
Java_com_example_aaudio_MainActivity_setPlayingUriAudioPlayer(
        JNIEnv *env, jclass clazz,
        jboolean is_playing) {
    LOGI("is_playing=%d", is_playing ? 1 : 0);
}

extern "C" JNIEXPORT void JNICALL
Java_com_example_aaudio_MainActivity_setLoopingUriAudioPlayer(
        JNIEnv *env, jclass clazz,
        jboolean is_looping) {
    // TODO: implement setLoopingUriAudioPlayer()
}

extern "C" JNIEXPORT void JNICALL
Java_com_example_aaudio_MainActivity_setChannelMuteUriAudioPlayer(
        JNIEnv *env, jclass clazz,
        jint chan, jboolean mute) {
    // TODO: implement setChannelMuteUriAudioPlayer()
}

extern "C" JNIEXPORT void JNICALL
Java_com_example_aaudio_MainActivity_setChannelSoloUriAudioPlayer(
        JNIEnv *env, jclass clazz,
        jint chan, jboolean solo) {
    // TODO: implement setChannelSoloUriAudioPlayer()
}

extern "C" JNIEXPORT jint JNICALL
Java_com_example_aaudio_MainActivity_getNumChannelsUriAudioPlayer(JNIEnv *env, jclass clazz) {
    return 1;
}

extern "C" JNIEXPORT void JNICALL
Java_com_example_aaudio_MainActivity_setVolumeUriAudioPlayer(
        JNIEnv *env, jclass clazz,
        jint millibel) {
    // TODO: implement setVolumeUriAudioPlayer()
}

extern "C" JNIEXPORT void JNICALL
Java_com_example_aaudio_MainActivity_setMuteUriAudioPlayer(
        JNIEnv *env, jclass clazz,
        jboolean mute) {
    // TODO: implement setMuteUriAudioPlayer()
}

extern "C" JNIEXPORT void JNICALL
Java_com_example_aaudio_MainActivity_enableStereoPositionUriAudioPlayer(
        JNIEnv *env, jclass clazz,
        jboolean enable) {
    // TODO: implement enableStereoPositionUriAudioPlayer()
}

extern "C" JNIEXPORT void JNICALL
Java_com_example_aaudio_MainActivity_setStereoPositionUriAudioPlayer(
        JNIEnv *env, jclass clazz,
        jint permille) {
    // TODO: implement setStereoPositionUriAudioPlayer()
}

extern "C" JNIEXPORT jboolean JNICALL
Java_com_example_aaudio_MainActivity_selectClip(JNIEnv *env, jclass clazz, jint which, jint count) {
    return JNI_FALSE;
}

extern "C" JNIEXPORT jboolean JNICALL
Java_com_example_aaudio_MainActivity_enableReverb(JNIEnv *env, jclass clazz, jboolean enabled) {
    return JNI_FALSE;
}

extern "C" JNIEXPORT jboolean JNICALL
Java_com_example_aaudio_MainActivity_createAudioRecorder(JNIEnv *env, jclass clazz) {
    return JNI_FALSE;
}

extern "C" JNIEXPORT void JNICALL
Java_com_example_aaudio_MainActivity_startRecording(JNIEnv *env, jclass clazz) {
    // TODO: implement startRecording()
}

extern "C" JNIEXPORT void JNICALL
Java_com_example_aaudio_MainActivity_shutdown(JNIEnv *env, jclass clazz) {
    LOGW("will shutdown this");
    int i = 0;
    int j = 2;
}

