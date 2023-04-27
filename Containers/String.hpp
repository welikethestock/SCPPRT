#ifndef __SCPPRT_CONTAINERS_STRING__
#define __SCPPRT_CONTAINERS_STRING__

#include "../Config.hpp"
#include "../Types/Int.hpp"
#include "../Memory/HeapManager.hpp"

#ifdef __cplusplus

SCPPRT_NAMESPACE_START

namespace Containers
{
    template< typename _T >
    class String;

    typedef String< char >      CString;
    typedef String< wchar_t >   WString;
}

template< typename _T >
class Containers::String
{
public:
    String() : m_HeapManager(), m_ConstPtr(nullptr), m_Length(0)
    {        
    }

    ~String() 
    {
    }

    template< size_t Length >
    constexpr String(const _T (&String)[Length]) : m_ConstPtr(String), m_HeapManager(), m_Length(Length)
    {
    }

    template< size_t Length >
    String(_T (&String)[Length]) : m_HeapManager(), m_ConstPtr(nullptr), m_Length(Length)
    {
        m_HeapManager.Copy(String, Length * sizeof(_T));
    }

    const _T *Get() const
    {
        return (m_ConstPtr != nullptr) ? m_ConstPtr : (_T *)(m_HeapManager.GetBase());
    }

    size_t GetSize() const
    {
        return (m_Length != 0) ? m_Length - 1 : 0;
    }

    void operator +=(const String< _T > &Other)
    {
        m_Length += Other.GetSize();
        m_HeapManager.Resize(
            m_Length * sizeof(_T)
        );
    }
private:
    const _T            *m_ConstPtr;
    Memory::HeapManager m_HeapManager;
    size_t              m_Length;
};

SCPPRT_NAMESPACE_END

#endif

#endif