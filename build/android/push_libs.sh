#!/bin/bash

adb root
adb remount

# libs
adb push libs/armeabi/libtmcutils.so		/system/lib/
adb push libs/armeabi/libtmutils.so			/system/lib/
adb push libs/armeabi/libtmfoundation.so	/system/lib/
# bin
adb push libs/armeabi/ALooper_test			/system/bin/
adb push libs/armeabi/AHandler_test			/system/bin/
