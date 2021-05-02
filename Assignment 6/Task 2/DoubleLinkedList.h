#ifndef DoubleLinkedList_H
#define DoubleLinkedList_H
#include "DoubleNode.h"

class DoubleLinkedList
{
    private:
        Node* Head;
        int Length;
        Node* GetNode(int index) const;
    public:
        DoubleLinkedList();
        DoubleLinkedList(DoubleLinkedList &);
        ~DoubleLinkedList();
        bool InsertAt(int data, int index);
        bool InsertHead(int data);
        bool InsertEnd(int data);
        bool RemoveAt(int index);
        bool RemoveHead();
        bool RemoveEnd();
        bool GetData(int index, int *d_ptr) const;
        bool SetData(int index, int d);
        int GetLength() const;
        bool Empty();
        void DisplayList() const;
};

#endif