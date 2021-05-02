#ifndef DoubleNode_h
#define DoubleNode_h

class Node
{
    private:
        int Data;
        Node* Next;
        Node* Previous;
    public:
        Node(int a);
        Node* GetNextPointer() const;
        Node* GetPreviousPointer() const;
        void SetNextPointer(Node *ptr);
        void SetPreviousPointer(Node *ptr);
        void SetData(int a);
        int GetData() const;
};

#endif