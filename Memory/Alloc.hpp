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

inline void *Memory::Heap::Allocate(size_t Size)
{
#ifndef SCRT_USE_CUSTOM_MALLOC
    return malloc(Size);
#else
    return nullptr;
#endif    
}

inline void *Memory::Heap::Reallocate(void *Address, size_t NewSize)
{
#ifndef SCRT_USE_CUSTOM_MALLOC
    return realloc(Address, NewSize);
#else
    return nullptr;
#endif
}

inline void Memory::Heap::Free(void *Address)
{
#ifndef SCRT_USE_CUSTOM_MALLOC
    return free(Address);
#else
    return nullptr;
#endif
}

SCPPRT_NAMESPACE_END

#endif

#endif