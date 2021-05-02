#include <iostream>
#include "Node.h"

Node::Node(int a)
{
    Data = a;
    Next = NULL;
}

Node* Node::GetNextPointer() const
{
    return Next;
}

void Node::SetNextPointer(Node *ptr)
{
    Next = ptr;
}

void Node::SetData(int a)
{
    Data = a;
}

int Node::GetData() const
{
    return Data;
}

