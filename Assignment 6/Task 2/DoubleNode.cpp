#include <iostream>
#include "DoubleNode.h"

Node::Node(int a)
{
    Data = a;
    Next = NULL;
    Previous = NULL;
}

Node* Node::GetNextPointer() const
{
    return Next;
}

Node* Node::GetPreviousPointer() const
{
    return Previous;
}

void Node::SetNextPointer(Node *ptr)
{
    Next = ptr;
}

void Node::SetPreviousPointer(Node *ptr)
{
    Previous = ptr;
}

void Node::SetData(int a)
{
    Data = a;
}

int Node::GetData() const
{
    return Data;
}

