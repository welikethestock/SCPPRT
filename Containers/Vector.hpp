#ifndef __SCPPRT_CONTAINERS_VECTOR__
#define __SCPPRT_CONTAINERS_VECTOR__

#include "../Config.hpp"
#include "../Types/Int.hpp"
#include "../Memory/HeapManager.hpp"
#include <stdio.h>

#ifdef __cplusplus

SCPPRT_NAMESPACE_START

namespace Containers
{
    template< typename _T >
    class Vector;
}

template< typename _T >
class Containers::Vector
{
public:
    Vector()    = default;
    ~Vector()
    {
    }
    
    template< typename _V, typename ..._R >
    Vector(_V Value, _R ...Rest) : Vector(Rest...)
    {
        Add(Value);
    }

    size_t GetSize() const
    {
        return m_Size;
    }

    _T operator[](size_t Index) const
    {
        return ((_T *)(m_HeapManager.GetBase()))[Index];
    }

    _T &operator[](size_t Index)
    {
        return ((_T *)(m_HeapManager.GetBase()))[Index];
    }

    void Add(_T Value)
    {
        if(m_HeapManager.GetBase() == nullptr || m_HeapManager.GetSize() <= (m_Size * sizeof(_T)))
        {
            m_HeapManager.Resize(
                ((m_Size != 0 ? m_Size : 1) * 2) * sizeof(_T)
            );
        }

        (*this)[m_Size] = Value;
        ++m_Size;
    }
private:
    Memory::HeapManager m_HeapManager;
    size_t              m_Size;
};

SCPPRT_NAMESPACE_END

#endif

#endif