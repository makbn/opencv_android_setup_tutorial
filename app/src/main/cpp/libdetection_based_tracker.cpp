#include "libdetection_based_tracker.h"
#include <opencv2/core/core.hpp>
#include <opencv2/contrib/detection_based_tracker.hpp>

#include <string>
#include <vector>

#include <android/log.h>

#define LOG_TAG "FaceDetection/libdetection_based_tracker"
#define LOGD(...) ((void)__android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__))

using namespace std;
using namespace cv;

inline void vector_Rect_to_Mat(vector<Rect>& v_rect, Mat& mat)
{
    mat = Mat(v_rect, true);
}

JNIEXPORT jlong JNICALL Java_ir_whiteapp_maremat_DetectionBasedTracker_nativeCreateObject
(JNIEnv * jenv, jclass, jstring jFileName, jint faceSize)
{
    const char* jnamestr = jenv->GetStringUTFChars(jFileName, NULL);
    string stdFileName(jnamestr);
    jlong result = 0;

    DetectionBasedTracker::Parameters DetectorParams;
    if (faceSize > 0)
        DetectorParams.minObjectSize = faceSize;
    result = (jlong)new DetectionBasedTracker(stdFileName, DetectorParams);

    return result;
}

JNIEXPORT void JNICALL Java_ir_whiteapp_maremat_DetectionBasedTracker_nativeDestroyObject
(JNIEnv * jenv, jclass, jlong thiz)
{
    if(thiz != 0)
    {
        ((DetectionBasedTracker*)thiz)->stop();
        delete (DetectionBasedTracker*)thiz;
    }
}

JNIEXPORT void JNICALL Java_ir_whiteapp_maremat_DetectionBasedTracker_nativeStart
(JNIEnv * jenv, jclass, jlong thiz)
{
    ((DetectionBasedTracker*)thiz)->run();
}

JNIEXPORT void JNICALL Java_ir_whiteapp_maremat_DetectionBasedTracker_nativeStop
(JNIEnv * jenv, jclass, jlong thiz)
{
    ((DetectionBasedTracker*)thiz)->stop();
}

JNIEXPORT void JNICALL Java_ir_whiteapp_maremat_DetectionBasedTracker_nativeSetFaceSize
(JNIEnv * jenv, jclass, jlong thiz, jint faceSize)
{
    if (faceSize > 0)
    {
        DetectionBasedTracker::Parameters DetectorParams = \
            ((DetectionBasedTracker*)thiz)->getParameters();
        DetectorParams.minObjectSize = faceSize;
        ((DetectionBasedTracker*)thiz)->setParameters(DetectorParams);
    }
}


JNIEXPORT void JNICALL Java_ir_whiteapp_maremat_DetectionBasedTracker_nativeDetect
(JNIEnv * jenv, jclass, jlong thiz, jlong imageGray, jlong faces)
{
    vector<Rect> RectFaces;
    ((DetectionBasedTracker*)thiz)->process(*((Mat*)imageGray));
    ((DetectionBasedTracker*)thiz)->getObjects(RectFaces);
    vector_Rect_to_Mat(RectFaces, *((Mat*)faces));
}