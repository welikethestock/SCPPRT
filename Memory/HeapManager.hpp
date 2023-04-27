#ifndef __SCPPRT_MEMORY_HEAPMANAGER__
#define __SCPPRT_MEMORY_HEAPMANAGER__

#include "../Config.hpp"
#include "../Types/Int.hpp"

#include "Alloc.hpp"

#ifdef __cplusplus

SCPPRT_NAMESPACE_START

namespace Memory
{
    class HeapManager;
}

class Memory::HeapManager
{
public:
    HeapManager() : m_Memory(nullptr), m_Size(0)
    {
    }

    ~HeapManager()
    {
        if(m_Memory != nullptr)
        {
            Heap::Free(m_Memory);
        }
    }

    void *GetBase() const
    {
        return m_Memory;
    }

    void Resize(size_t Size)
    {
        if(m_Memory == nullptr)
        {
            m_Memory = Heap::Allocate(Size);
            m_Size = Size;

            return;
        }

        m_Size   = Size;
        m_Memory = Heap::Reallocate(m_Memory, m_Size);
    }

    void Shrink(size_t Size)
    {
        if(Size >= m_Size)
        {
            if(m_Memory != nullptr)
            {
                Heap::Free(m_Memory);
            }

            m_Memory = nullptr;
            m_Size = 0;

            return;
        }

        m_Size  -= Size;
        m_Memory = Heap::Reallocate(m_Memory, m_Size);
    }

    void Copy(const void *From, size_t Size)
    {
        if(GetSize() < Size)
        {
            Resize(Size);
        }

        for(size_t Index = 0; Index < Size; ++Index)
        {
            *((char *)(m_Memory) + Index) = *((char *)(From) + Index);
        }
    }

    size_t GetSize() const
    {
        return m_Size;
    }
private:
    void    *m_Memory;
    size_t  m_Size;
};

SCPPRT_NAMESPACE_END

#endif

#endif