#pragma once

#include <android/log.h>

#ifndef __FILE_NAME__
#define __FILE_NAME__ __FILE__
#endif

#define BASE_LOG(LEVEL, FMT, ...)                                       \
    do {                                                                \
        __android_log_print( (LEVEL), "ndk-demo", "[%s:%d@%s]>>> " FMT, \
            __FILE_NAME__, __LINE__, __FUNCTION__, ##__VA_ARGS__ );     \
    } while(0)


#define LOGV(FMT, ...) BASE_LOG(ANDROID_LOG_VERBOSE, FMT, ##__VA_ARGS__ )
#define LOGD(FMT, ...) BASE_LOG(ANDROID_LOG_DEBUG,   FMT, ##__VA_ARGS__ )
#define LOGI(FMT, ...) BASE_LOG(ANDROID_LOG_INFO,    FMT, ##__VA_ARGS__ )
#define LOGW(FMT, ...) BASE_LOG(ANDROID_LOG_WARN,    FMT, ##__VA_ARGS__ )
#define LOGE(FMT, ...) BASE_LOG(ANDROID_LOG_ERROR,   FMT, ##__VA_ARGS__ )

