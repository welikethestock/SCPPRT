#ifndef __CPPRT_CONTAINERS_STACK__
#define __CPPRT_CONTAINERS_STACK__

#include "../Config.hpp"
#include "../Types/Int.hpp"
#include "../Memory/HeapManager.hpp"

#ifdef __cplusplus

SCPPRT_NAMESPACE_START

namespace Containers
{
    template< typename _T >
    class Stack;
}

template< typename _T >
class Containers::Stack
{
public:
    Stack() : m_HeapManager()
    {
    }

    ~Stack()
    {
    }

    void Push(_T Value)
    {
        if(m_HeapManager.GetBase() == nullptr || m_HeapManager.GetSize() <= (m_Size * sizeof(_T)))
        {
            m_HeapManager.Resize(
                ((m_Size != 0 ? m_Size : 1) * 2) * sizeof(_T)
            );
        }

        ((_T *)(m_HeapManager.GetBase()))[m_Size] = Value;
        ++m_Size;
    }

    void Pop(size_t ToPop = 1)
    {
        while(m_Size > 0 && ToPop != 0)
        {
            --m_Size;
            --ToPop;
        }
    }

    const _T &GetTop() const
    {
        return ((_T *)(m_HeapManager.GetBase()))[m_Size - 1];
    }
private:
    Memory::HeapManager m_HeapManager;
    size_t              m_Size;
};

SCPPRT_NAMESPACE_END

#endif

#endif