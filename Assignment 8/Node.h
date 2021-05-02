#ifndef Node_H
#define Node_H

struct Node
{
    int data;
    Node *parent;
    Node *left;
    Node *right;
};

#endif