#define SCRT_USE_CUSTOM_MALLOC

#include <stdlib.h>
#include <stdio.h>

#include "Containers/DoublyLinkedList.hpp"
#include "Containers/Vector.hpp"
#include "Containers/String.hpp"
#include "Containers/Stack.hpp"
#include <stdio.h>

extern "C"
void *__cpprt_malloc(cpprt::size_t Size)
{
    printf("ALLOC %llu\n", Size);

    return malloc(Size);
}

extern "C"
void *__cpprt_realloc(void *Address, cpprt::size_t Size)
{
    printf("REALLOC %p %llu\n", Address, Size);

    return realloc(Address, Size);
}

extern "C"
void __cpprt_free(void *Address)
{
    printf("FREE %p\n", Address);

    return free(Address);
}

int main()
{
    cpprt::Containers::DoublyLinkedList< int > Test = cpprt::Containers::DoublyLinkedList< int >(1, 2, 3, 4, 5, 6);

    {
        auto Node = Test.GetFirstNode();
        while(Node)
        {
            printf("%d %p\n", Node->Value, (void *)Node);

            Node = Node->Next;
        }
    }

    printf("=======================\n");

    cpprt::Containers::Vector< int > Vector = cpprt::Containers::Vector< int >();
    Vector.Add(1);
    Vector.Add(2);
    Vector.Add(3);
    for(size_t Index = 0; Index < Vector.GetSize(); ++Index)
    {
        printf("%d\n", ++Vector[Index]);
    }

    printf("=======================\n");

    cpprt::Containers::CString CString = cpprt::Containers::CString("hello");
    CString += cpprt::Containers::CString("hi");
    cpprt::Containers::WString WString = cpprt::Containers::WString(L"hello");
    printf("%llu %s %llu %S\n", CString.GetSize(), CString.Get(), WString.GetSize(), WString.Get());

    printf("=======================\n");

    cpprt::Containers::Stack< int > Stack = cpprt::Containers::Stack< int >();
    Stack.Push(1);
    Stack.Push(2);

    printf("%d\n", Stack.GetTop());
    Stack.Pop();
    printf("%d\n", Stack.GetTop());
    Stack.Pop();

    printf("=======================\n");

    return 0;
}