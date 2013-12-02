/*
 * Copyright (C) 2007 The Android Open Source Project
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
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

#include "cutils/log.h"

#ifdef ANDROID
#include <android/log.h>
#endif

#define LOG_BUF_SIZE	1024

static log_print_callback s_log_print = NULL;
static int s_log_level = TANGMAI_LOG_DEFAULT;

#define IS_NEED_LOG(level)    ((level) >= (s_log_level))

void tangmai_log_set_callback(log_print_callback cb)
{
    if (cb != NULL) {
        s_log_print = cb;
    }
}

int tangmai_log_get_level()
{
    return s_log_level;
}

void tangmai_log_set_level(int level)
{
    s_log_level = level;
}

int __tangmai_log_write(int prio, const char *tag, const char *msg)
{
    char buf[LOG_BUF_SIZE];

    if (!IS_NEED_LOG(prio))
        return 0;

    if (!tag)
        tag = "notag";

    snprintf(buf, LOG_BUF_SIZE, "[Tangmai][%s]: %s", tag, msg);
    buf[LOG_BUF_SIZE-1] = '\0';

    if (s_log_print != NULL)
    {
        s_log_print(buf);
    }
    else
    {
#ifdef ANDROID
        __android_log_print(ANDROID_LOG_DEBUG, "Tangmai", "%s", buf);
#else
        printf("%s\n", buf);
#endif
    }

	return 0;
}

int __tangmai_log_vprint(int prio, const char *tag, const char *fmt, va_list ap)
{
    char buf[LOG_BUF_SIZE];

    vsnprintf(buf, LOG_BUF_SIZE, fmt, ap);

    return __tangmai_log_write(prio, tag, buf);
}

int __tangmai_log_print(int prio, const char *tag, const char *fmt, ...)
{
    va_list ap;
    char buf[LOG_BUF_SIZE];

    va_start(ap, fmt);
    vsnprintf(buf, LOG_BUF_SIZE, fmt, ap);
    va_end(ap);

    return __tangmai_log_write(prio, tag, buf);
}

void __tangmai_log_assert(const char *cond, const char *tag,
			  const char *fmt, ...)
{
    char buf[LOG_BUF_SIZE];

    if (fmt) {
        va_list ap;
        va_start(ap, fmt);
        vsnprintf(buf, LOG_BUF_SIZE, fmt, ap);
        va_end(ap);
    } else {
        /* Msg not provided, log condition.  N.B. Do not use cond directly as
         * format string as it could contain spurious '%' syntax (e.g.
         * "%d" in "blocks%devs == 0").
         */
        if (cond)
            snprintf(buf, LOG_BUF_SIZE, "Assertion failed: %s", cond);
        else
            strcpy(buf, "Unspecified assertion failed");
    }

    __tangmai_log_write(TANGMAI_LOG_FATAL, tag, buf);
}
