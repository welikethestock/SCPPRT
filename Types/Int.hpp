#ifndef __SCPPRT_TYPES_INT__
#define __SCPPRT_TYPES_INT__

#include "../Config.hpp"

SCPPRT_NAMESPACE_START

typedef signed char         i8;
typedef unsigned char       u8, uchar;

typedef signed short        i16;
typedef unsigned short      u16, ushort;

typedef signed int          i32;
typedef unsigned int        u32, uint;

typedef long long           i64, longlong;
typedef unsigned long long  u64, ulonglong;

#ifdef __x86_64__
    typedef ulonglong           size_t;
    typedef longlong            ptrdiff_t;
#elif __i386__
    typedef uint                size_t;
    typedef int                 ptrdiff_t;
#else
    #error "Unknown architecture"
#endif

#ifndef __cplusplus
    #ifndef nullptr
        #define nullptr 0
    #endif
#endif

typedef u8                  byte;

SCPPRT_NAMESPACE_END

#endif