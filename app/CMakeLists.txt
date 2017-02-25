
cmake_minimum_required(VERSION 3.4.1)

include_directories(src/main/jniLibs/jni/include)
add_library( lib_opencv SHARED IMPORTED )
set_target_properties(lib_opencv PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI}/libopencv_java3.so)
add_library( native-lib SHARED src/main/cpp/native-lib.cpp )
add_library( libdetection_based_tracker SHARED src/main/cpp/libdetection_based_tracker.cpp )

find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

target_link_libraries( # Specifies the target library.
                       native-lib

                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib} )
