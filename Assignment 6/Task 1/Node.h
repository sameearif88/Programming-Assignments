#ifndef Node_h
#define Node_h

class Node
{
    private:
        int Data;
        Node* Next;
    public:
        Node(int a);
        Node* GetNextPointer() const;
        void SetNextPointer(Node *ptr);
        void SetData(int a);
        int GetData() const;
};

#endif