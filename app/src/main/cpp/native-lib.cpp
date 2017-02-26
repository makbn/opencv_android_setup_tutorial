#include "native-lib.h"
#include <string>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/features2d/features2d.hpp>



using namespace std;
using namespace cv;

JNIEXPORT jstring JNICALL
Java_ir_whiteapp_maremat_Inpainting_test(JNIEnv *env, jclass type, jint a) {

    // TODO


    return env->NewStringUTF("hiiii");
}
