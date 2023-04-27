#ifndef __SCPPRT_CONFIG__
#define __SCPPRT_CONFIG__

#ifdef __cplusplus
    #ifndef SCPPRT_NAMESPACE
        #define SCPPRT_NAMESPACE        cpprt
    #endif

    #define SCPPRT_NAMESPACE_START  namespace SCPPRT_NAMESPACE {
    #define SCPPRT_NAMESPACE_END    }
#else
    #define SCPPRT_NAMESPACE_START
    #define SCPPRT_NAMESPACE_END
#endif

#endif