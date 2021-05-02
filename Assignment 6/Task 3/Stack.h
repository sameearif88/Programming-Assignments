#ifndef Stack_h
#define Stack_h
#include "LinkedList.h"

class Stack
{
    private:
        LinkedList StackList;
    public:
        Stack();
        ~Stack();
        void Push(int Data);
        void Pop();
        void Display();
};

#endif