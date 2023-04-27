#ifndef __SCPPRT_MEMORY_ALLOC__
#define __SCPPRT_MEMORY_ALLOC__

#include "../Config.hpp"
#include "../Types/Int.hpp"

#ifndef SCRT_USE_CUSTOM_MALLOC
#include <stdlib.h>
#endif

#ifdef __cplusplus

SCPPRT_NAMESPACE_START

namespace Memory
{
    namespace Heap
    {
        void *Allocate(size_t Size);
        void *Reallocate(void *Address, size_t NewSize);
        void Free(void *Address);
    }
}

#ifdef SCRT_USE_CUSTOM_MALLOC
    extern "C"
    void *__cpprt_malloc(size_t);
    
    extern "C"
    void *__cpprt_realloc(void *, size_t);

    extern "C"
    void __cpprt_free(void *);

#endif

inline void *Memory::Heap::Allocate(size_t Size)
{
#ifndef SCRT_USE_CUSTOM_MALLOC
    return malloc(Size);
#else
    return __cpprt_malloc(Size);
#endif    
}

inline void *Memory::Heap::Reallocate(void *Address, size_t NewSize)
{
#ifndef SCRT_USE_CUSTOM_MALLOC
    return realloc(Address, NewSize);
#else
    return __cpprt_realloc(Address, NewSize);
#endif
}

inline void Memory::Heap::Free(void *Address)
{
#ifndef SCRT_USE_CUSTOM_MALLOC
    return free(Address);
#else
    return __cpprt_free(Address);
#endif
}

SCPPRT_NAMESPACE_END

#endif

#endif