/*
 * Copyright (C) 2005 The Android Open Source Project
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

/*
 * Android config -- "android-arm".  Used for ARM device builds.
 */
#ifndef _TANGMAI_CONFIG_ARM_H
#define _TANGMAI_CONFIG_ARM_H

#ifdef HAVE_ANDROID_OS
//#define HAVE_TANGMAI_OS 1
#endif

#ifndef HAVE_PTHREADS
#define HAVE_PTHREADS
#endif

#ifndef HAVE_POSIX_FILEMAP
#define HAVE_POSIX_FILEMAP
#endif

#ifndef HAVE_SYS_UIO_H
#define HAVE_SYS_UIO_H 1
#endif

#ifndef HAVE_SYMLINKS
#define HAVE_SYMLINKS
#endif

#ifndef HAVE_POSIX_CLOCKS
#define HAVE_POSIX_CLOCKS
#endif

#ifndef HAVE_ENDIAN_H
#define HAVE_ENDIAN_H
#endif

#ifndef HAVE_LITTLE_ENDIAN
#define HAVE_LITTLE_ENDIAN
#endif

#ifndef HAVE_OFF64_T
#define HAVE_OFF64_T
#endif

#ifndef HAVE_GETTID
#define HAVE_GETTID
#endif

#ifndef HAVE_MADVISE
#define HAVE_MADVISE 1
#endif

#ifndef HAVE_PRCTL
#define HAVE_PRCTL 1
#endif

#ifndef HAVE_PREAD
#define HAVE_PREAD 1
#endif

#ifndef HAVE_PRINTF_ZD
#define HAVE_PRINTF_ZD 1
#endif

#endif /* _TANGMAI_CONFIG_AMR_H */
