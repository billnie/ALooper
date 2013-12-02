/*
 * Copyright (C) 2010 The Android Open Source Project
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
#define LOG_TAG "AHandler_test"
#include "utils/Log.h"

#include "config.h"

#include "foundation/hexdump.h"
#include "foundation/ABuffer.h"
#include "foundation/ADebug.h"
#include "foundation/AHandler.h"
#include "foundation/ALooper.h"
#include "foundation/AMessage.h"

using namespace tangmai;

struct Controller : public AHandler {
    Controller() {
    }

    void startAsync() {
        (new AMessage(kWhatStart, id()))->post();
    }

protected:
    virtual ~Controller() {
    }

    virtual void onMessageReceived(const sp<AMessage> &msg) {
        switch (msg->what()) {
            case kWhatStart:
            {
                ALOGD("start\n");
                //(new AMessage(kWhatSeek, id()))->post(5000000ll); //5s
                (new AMessage(kWhatSeek, id()))->post();
                break;
            }

            case kWhatSeek:
            {
                ALOGD("seek\n");
                //(new AMessage(kWhatTest, id()))->post(5000000ll); //5s
                (new AMessage(kWhatTest, id()))->post();
                break;
            }

            case kWhatStop:
            {
                ALOGD("stop\n");
                looper()->stop();
                //sp<AMessage> reply;
                //CHECK(msg->findMessage("reply", &reply));
                //reply->setInt32("err", OK);
                //reply->post();
                break;
            }

            case kWhatTest:
            {
                ALOGD("test\n");
                //int32_t what;
                //CHECK(msg->findInt32("what", &what));
                (new AMessage(kWhatStop, id()))->post();
                break;
            }

            default:
                TRESPASS();
                break;
        }
    }

private:
    enum {
        kWhatStart             = 'strt',
        kWhatStop              = 'stop',
        kWhatSeek              = 'seek',
        kWhatTest              = 'test',
    };

    DISALLOW_EVIL_CONSTRUCTORS(Controller);
};

int main(int argc, char **argv) {
    sp<ALooper> looper = new ALooper;
    looper->setName("AHandler_test");

    sp<Controller> controller = new Controller();

    ALOGD("looper registerHandler\n");

    looper->registerHandler(controller);

    ALOGD("controller startAsync\n");

    controller->startAsync();

    ALOGD("looper start\n");

    CHECK_EQ(looper->start(true /* runOnCallingThread */), (status_t)OK);

    ALOGD("looper unregisterHandler\n");

    looper->unregisterHandler(controller->id());

    ALOGD("main exit\n");

    return 0;
}

