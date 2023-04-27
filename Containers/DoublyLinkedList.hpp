#ifndef __SCPPRT_CONTAINERS_DOUBLYLINKEDLIST_INT__
#define __SCPPRT_CONTAINERS_DOUBLYLINKEDLIST_INT__

#include "../Config.hpp"
#include "../Types/Int.hpp"
#include "../Memory/Alloc.hpp"

#ifdef __cplusplus

SCPPRT_NAMESPACE_START

namespace Containers
{
    template< typename _T >
    class DoublyLinkedList;
}

template< typename _T >
class Containers::DoublyLinkedList
{
public:
    struct Node
    {
        _T      Value;
        Node    *Previous;
        Node    *Next;
    };

    DoublyLinkedList()
    {
        m_Root.Next = m_Root.Previous = nullptr;
    }

    template< typename _V, typename ..._R >
    DoublyLinkedList(_V Value, _R ...Rest) : DoublyLinkedList(Rest...)
    {
        AddValue(Value, true);
    }

    Node *GetFirstNode()
    {
        return &m_Root;
    }

    Node *GetLastNode()
    {
        auto Node = GetFirstNode();
        while(Node->Next != nullptr)
        {
            Node = Node->Next;
        }

        return Node;
    }

    Node *AddValue(_T Value, bool Front = false)
    {
        Node *NewNode  = (Node *)(Memory::Heap::Allocate(sizeof(Node)));
        NewNode->Value = Value;
        NewNode->Next  = NewNode->Previous = nullptr;

        if(Front)
        {
            InsertFront(NewNode);
        }
        else
        {
            InsertBack(NewNode);
        }

        return NewNode;
    }
private:
    void InsertBack(Node *Node)
    {
        Node->Previous          = GetLastNode();
        Node->Previous->Next    = Node;
        Node->Next              = nullptr;
    }

    void InsertFront(Node *Node)
    {
        Node->Next      = GetFirstNode()->Next;
        Node->Previous  = GetFirstNode();
        
        if(GetFirstNode()->Next != nullptr)
        {
            GetFirstNode()->Next->Previous = Node;
        }

        GetFirstNode()->Next = Node;
    }

    void RemoveNode(Node *Node)
    {
        if(Node->Next)
        {
            Node->Next->Previous = Node->Previous;
        }

        Node->Previous->Next = Node->Next;
        Node->Previous = Node->Next = nullptr;
    }
public:
    void PushToFront(Node *Node)
    {
        if(Node == m_Root.Next)
        {
            return;
        }

        RemoveNode(Node);
        InsertFront(Node);
    }

    void PushToBack(Node *Node)
    {
        RemoveNode(Node);
        InsertBack(Node);
    }

    void DeleteNode(Node *Node)
    {
        RemoveNode(Node);
        
        Memory::Heap::Free(Node);
    }
private:
    Node    m_Root;
};

SCPPRT_NAMESPACE_END

#endif

#endif