# Tutorial: Setting Up OpenCV for Android

Hey everyone,  
Welcome!  
My goal with this tutorial is to make it super easy for you to create an Android application using the **[OpenCV](http://opencv.org/)** library.

Before we dive in, it's helpful to check the [tool versions](#tools-version) I used to avoid any compatibility issues.

#

![OpenCV for Android](/images/LOGO.png)

---

## Tools Version

Tool | Version
------------ | -------------
OpenCV Android SDK | openCV-3.2.0  
Android Studio | v2.2.2  
Android SDK Build-tools | v25  
Android SDK Platform-tools | v25.0.3  
Android Official NDK | android-ndk-r12b  

**OS:** Windows 10

---

## Getting Started

First things first—download these:

- [**OpenCV Android SDK**](http://opencv.org/downloads.html)  
- [**Android NDK (Native Development Kit)**](https://developer.android.com/ndk/downloads/index.html)

### Extract the Files

- Extract the NDK to a directory **without spaces** in the path, e.g. `C:\work\android-ndk-r12b`
- Extract the OpenCV SDK to a location near the NDK (though its exact location doesn't really matter)

---

## Setting Up Environment Variables (Java & NDK)

1. Right-click **This PC** → **Properties** → click **Advanced system settings**
2. In the window that appears, go to the **Advanced** tab and click **Environment Variables**
3. Under **User variables**, find the `PATH` variable and click **Edit**
4. Click **New**, then add the path to your Java `bin` folder  
   _Example:_ `C:\Program Files\Java\jdk1.8.0_40\bin\`
5. Add the NDK root path in the same way  
   _Example:_ `C:\work\android-ndk-r12b`
6. Done!

---

## Installing CMake (Required for Native Code)

1. Open **Android Studio** and go to **Settings**
2. Navigate to **Appearance & Behavior** → **System Settings** → **Android SDK**
3. Go to the **SDK Tools** tab and make sure **CMake** is checked and installed  
   If it’s not, check it and click **Apply**

---

## Creating Your Android Project

Let’s build your first project:

1. Open **Android Studio** → click **New Project**
2. Fill in the **Application Name** and **Company Domain**
3. **Important:** Check the box for **Include C++ Support**
4. Proceed with the default settings  
   On the final screen before clicking **Finish**, set the C++ standard. I recommend using **Toolchain Default**

> **Note:**  
If you encounter this error:  
`Error: NDK not configured. Download it with SDK manager.`  
Follow these steps:
- Go to **File** → **Project Structure**
- Set the correct **NDK path** under **Android NDK location**

---

## Import the OpenCV Java Module

1. Go to **File** → **New** → **Import Module**
2. Navigate to `{YOUR_OPENCV_SDK_DIR}\sdk\` and select the `java` folder  
3. Click **OK**, then **Next**, then **Finish**
4. Open your app-level `build.gradle` file and add this under `dependencies`:

```gradle
implementation project(':openCVLibrary320')
```

> `openCVLibrary320` is the default module name. Yours might differ depending on the SDK version.

---

## Add `jniLibs` Folder

1. Right-click the **app** module → **New** → **Folder** → **JNI Folder**
2. Check **Change Folder Location**
3. Change the directory from `src/main/jni/` to `src/main/jniLibs/`
4. Click **Finish**

---

## Add Native Libraries

You’ll need native libraries for each processor architecture you want to support. Luckily, OpenCV provides them all!

- They’re located in `\sdk\native\libs` inside the OpenCV SDK
- Copy only the folders you need (or all of them) into your project’s `jniLibs` directory

> Pro tip: Only include the architectures you plan to support to reduce app size.

---

## Create and Configure `Android.mk`

1. Inside `jniLibs`, create a new file named `Android.mk`
2. Add the following content:

```make
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

OPENCV_LIB_TYPE := SHARED
OPENCV_CAMERA_MODULES := on
OPENCV_INSTALL_MODULES := on

include {OpenCV.mk_DIR}

LOCAL_SRC_FILES  := native-lib.cpp
LOCAL_C_INCLUDES += {INCLUDE_DIR}
LOCAL_LDLIBS     += -llog -ldl
LOCAL_CFLAGS     += -DOPENCV_OLDER_VERSION

LOCAL_CPP_FEATURES += exceptions
LOCAL_CPPFLAGS += -fexceptions

LOCAL_MODULE     := native-lib

include $(BUILD_SHARED_LIBRARY)
```

### Notes:
- `{OpenCV.mk_DIR}` → path to `OpenCV.mk`, usually:  
  `\sdk\native\jni\OpenCV.mk`
- `{INCLUDE_DIR}` → path to OpenCV’s `include` directory:  
  `\sdk\native\jni\include`
- `LOCAL_MODULE` → name of your native C++ source file (`native-lib.cpp`)

> Optional Configs:  
- `OPENCV_CAMERA_MODULES` and `OPENCV_INSTALL_MODULES`:  
  Set to **off** if you want the app to require the OpenCV Manager app on the user's device

---

## That’s It!

You’re now all set to start building your Android OpenCV app with native C++ support.
