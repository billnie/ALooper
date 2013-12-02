/*
 * Copyright (C) 2012 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

//#define LOG_NDEBUG 0
#define LOG_TAG "ALooper_test"
#include "utils/Log.h"

#include "config.h"

#include "foundation/ALooper.h"

static int test(
        const tangmai::sp<tangmai::ALooper> &looper) {
    using namespace tangmai;

    looper->setName("test");

    int64_t timeUs = ALooper::GetNowUs();

    ALOGD("timeUs:%lld", timeUs);

    return 0;
}

int main(int argc, char **argv) {
    using namespace tangmai;

    ALOGV("new Alooper, it should not be displayed");

    ALOGD("new Alooper");
			
    sp<ALooper> looper = new ALooper;

    ALOGD("looper start");
    looper->start();

    ALOGD("looper test");
    test(looper);

    ALOGD("looper stop");
    looper->stop();

    ALOGD("looper exit");

    return 0;
}
