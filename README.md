# Tutorial on OpenCV for Android Setup

Welcome guys!
my goal is to make it easy to create an android CV application with **[OpenCV](http://opencv.org/)** libraries.

before starting tutorial its better to know the [version of tools](#tools-version) that i used!

#

![OpenCV for Android](/images/LOGO.png)

#Tools Version

Tool | Version
------------ | -------------
OpenCV Android SDK | openCv-3.2.0
Android Studio | v2.2.2
Android SDK build-tools | v25
Android SDK platform-tools | v25.0.3
Android Official NDK | android-ndk-r12b

* **OS:** Windows 10 :shit:

#Getting Start

First of all you need to download [**OpenCv Android SDK**](http://opencv.org/downloads.html) and [**Android Official NDK**](https://developer.android.com/ndk/downloads/index.html)!
* Extract downloaded NDK in a simple direction without  space in dir path! like *C:\work\android-ndk-r12b*
* Extract extract OpenCV SDK beside NDK folder (technically this direction is **Not** important! :smile:)

###Edit system environment for java and ndk-build:

1. Right click on **This PC** and go to **Properties** find **Advanced dystem Settings** on right side and open it!
2. In new Window go to **Advanced** tab and click on **Environment Variables**.
3. Find **PATH** variable for current user and click on **Edit**
4. Click **New** button in opened window and paste the direction of your java **bin** folder! like : *C:\Program Files\Java\jdk1.8.0_40\bin\*

5. Add the path of **NDK** like step 4!for NDK you need to add root direction! like : *C:\work\android-ndk-r12b*
6. Done!

###Installing Cmake for Android SDK:

1. Open **Android Studio** and go to **Settings**
2. Go to **Appearance & Behavior** and click on **System settings** on opened sublist,and find **Android SDK**!
3. Click on **SDK Tools** tab and make sure that **CMake** is install. if not!check it for install!

#Creating Project

###Time to creating New Android Project

1. Open **Android Studio** and clcik on **New Projcet** (its all over and done! :smile:)
2. Its clear that you need to fill **Application Name** and **Company Domain** but most Important Job here is to check **Include C++ Support**
3. Continue like all other default android project and in the last step before click on **Finish** you need to set your C++ Standard! i use **Toolchain Default**!

* if you got an exceptin with this message : ``Error:NDK not configured. 
Download it with SDK manager.)`` you should follow this steps:

  4. open **Project Structure** under **File** tab.
  5. set you NDK direction in **Android NDK location** and Done!

###Add OpenCV Java Wrapper Module!

1. On **File** menu click on **New** and click on **Import Module**!
2. Go to *{YOUR_OPENCV_SDK_DIR}\sdk\* and select **java** folder!click on **OK**!
3. Click on next then finish.
4. Open app level gradle and add this line under **dependencies** scope:

```gradle
compile project(':openCVLibrary320')

```
* `openCVLibrary320` is the name of added module from OpenCV and it may have different name for you!

###Add *jniLibs* folder

1. Right click on *app* folder (or its better to say app module) of your project!
2. Click on **New** an go to **Folder** submenu, select **JNI Folder**.
3. Check **Change Folder Location**
4. Change `src/main/jni/` to `src/main/jniLibs/` and click on **Finish**

###Add native libs

You need to add native libraries for different type of proccessors!fortunetly OpenCV provides all of them for you and you can find them under OpenCV SDK directory `\sdk\native\libs`!

In order to add a specific proccessor's library you just need to copy that folder and paste it under *jniLibs* folder!

* you can add them all but its better to add what you need specificly!

###Create `Android.mk` file and configure it!

1. Create new File under *jniLibs* dir and name it `Android.mk`!
2. Copy this lines and paste there:

```mk
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

OPENCV_LIB_TYPE:=SHARED
OPENCV_CAMERA_MODULES:=on
OPENCV_INSTALL_MODULES:=on

include {OpenCV.mk_DIR}

LOCAL_SRC_FILES  := native-lib.cpp
LOCAL_C_INCLUDES += C:\work\OpenCV-android-sdk\sdk\native\jni\include
LOCAL_LDLIBS     += -llog -ldl
LOCAL_CFLAGS    += -DOPENCV_OLDER_VISION

LOCAL_CPP_FEATURES += exceptions (Recommended)
LOCAL_CPPFLAGS += -fexceptions


LOCAL_MODULE     := native-lib

include $(BUILD_SHARED_LIBRARY)
```

* `{OpenCV.mk_DIR}` : directory of your `OpenCV.mk` file under under OpenCV SDK directory `\sdk\native\jni\OpenCV.mk`



