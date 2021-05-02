#include <iostream>
#include "Stack.h"
#include "LinkedList.h"

Stack::Stack()
{
    //Default constructor of LinkedList class is called
}

Stack::~Stack()
{
    //Distructor of LinkedList class is called
}

void Stack::Push(int Data)
{
    StackList.InsertHead(Data);
}

void Stack::Pop()
{
    StackList.RemoveHead();
}

void Stack::Display()
{
    StackList.DisplayList();
}