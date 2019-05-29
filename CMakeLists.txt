cmake_minimum_required(VERSION 3.4.1)
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2 -g -D_GNU_SOURCE -DHAVE_IPV6 -DHAVE_LINUX -DNOT_HAVE_SA_LEN -DPLATFORM_NO_RLIMIT -DTARGET_OS_LINUX -DUSES_NETLINK -DMDNS_DEBUGMSGS=0 -W -Wall -Wextra -Wno-array-bounds -Wno-pointer-sign -Wno-unused -Wno-unused-parameter -Werror=implicit-function-declaration -DANDROID_TOOLCHAIN=clang")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2 -g   -fno-strict-aliasing  -Wextra  -Wno-array-bounds -Wno-missing-declarations -Wno-missing-braces -Wno-pointer-sign  -Wno-unused  -Wno-unused-parameter  -Werror=implicit-function-declaration")
#-DMDNS_UDS_SERVERPATH=\"/dev/socket/mdnsd\"  -DMDNS_USERNAME=\"mdnsr\"

SET(CROSS_COMPILE 1)
    IF(CROSS_COMPILE) 
    SET(CMAKE_SYSTEM_NAME Linux)
    SET(TOOLCHAIN_DIR "/usr/local/arm/usr/")
    set(CMAKE_CXX_COMPILER ${TOOLCHAIN_DIR}/bin/arm-linux-g++)
    set(CMAKE_C_COMPILER   ${TOOLCHAIN_DIR}/bin/arm-linux-gcc)
    set(GNU_FLAGS " -fPIC")
    set(CMAKE_CXX_FLAGS "${GNU_FLAGS} ")
    set(CMAKE_C_FLAGS "${GNU_FLAGS}  ")

    SET(CMAKE_FIND_ROOT_PATH  ${TOOLCHAIN_DIR}

    ${TOOLCHAIN_DIR}/include
    ${TOOLCHAIN_DIR}/lib )
ENDIF(CROSS_COMPILE)

add_definitions(-DANDROID_SMP=0 )
include_directories(./inc
    ./inc/foundation
    ./inc/libcutils
    ./inc/utils
    ./inc/cutils)
set(aloop .)
aux_source_directory(${aloop}/src/foundation foundation)
aux_source_directory(${aloop}/src/libcutils libcutils)
aux_source_directory(${aloop}/src/utils utils)

list(REMOVE_ITEM  utils ${aloop}/src/utils/CallStack.cpp
                        ${aloop}/src/utils/Trace.cpp
                        ${aloop}/src/utils/ZipFileCRO.cpp
                        ${aloop}/src/utils/ZipFileRO.cpp
                        ${aloop}/src/utils/ZipUtils.cpp)
set(DIR_SRCS ${aloop}
    ${foundation}
    ${libcutils}
    ${utils}
)

add_library( aloop
        SHARED
        ${DIR_SRCS}
        )


# find_library( log-lib
#     hexdump
# )
target_link_libraries( aloop
    log
        )