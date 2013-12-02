LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES:=                 \
    AAtomizer.cpp                 \
    ABitReader.cpp                \
    ABuffer.cpp                   \
    AHandler.cpp                  \
    AHierarchicalStateMachine.cpp \
    ALooper.cpp                   \
    ALooperRoster.cpp             \
    AMessage.cpp                  \
    AString.cpp                   \
    base64.cpp                    \
    hexdump.cpp

LOCAL_C_INCLUDES:= \
	$(LOCAL_PATH)/../../inc \
	$(LOCAL_PATH)/../../inc/foundation

LOCAL_SHARED_LIBRARIES := \
	libtmcutils \
	libtmutils

LOCAL_CFLAGS += -Wno-multichar

LOCAL_MODULE_TAGS := optional

LOCAL_MODULE:= libtmfoundation

include $(BUILD_SHARED_LIBRARY)
