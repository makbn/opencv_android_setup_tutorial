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
* Extract downloaded NDK in a simple direction without  space in dir path! like C:\work\android-ndk-r12b
* Extract extract OpenCV SDK beside NDK folder (technically this direction is **Not** important! :smile:)

Edit system environment for java and ndk-build 

1. Right click on **This PC** and go to **Properties** find **Advanced dystem Settings** on right side and open it!
2. In new Window go to **Advanced** tab and click on **Environment Variables**.
3. Find **PATH** variable for current user and click on **Edit**
4. Click **New** button in opened window and pase the direction of your java **bin** folder! like : C:\Program Files\Java\jdk1.8.0_40\bin\
5. Add the path of **NDK** like step 4!for NDK you need to add root direction! like : C:\work\android-ndk-r12b
6. Done!
