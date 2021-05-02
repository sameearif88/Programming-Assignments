#include <iostream>
#include "Node.h"

Node *Treesearch(Node *root, int search_key);

int main()
{
    //Node 50, 25, 75
    Node *root = new Node;
    Node *left25 = new Node;
    Node *right75 = new Node;
    root->data = 50;
    root->parent = NULL;
    root->left = left25;
    root->right = right75;
    left25->data = 25;
    left25->parent = root;
    right75->data = 75;
    right75->parent = root;
    
    //Node 12, 37
    Node *left12 = new Node;
    Node *right37 = new Node;
    left25->left = left12;
    left25->right = right37;
    left12->data = 12;
    right37->data = 37;
    left12->parent = left25;
    right37->parent = left25;

    //Node 62, 88
    Node *left62 = new Node;
    Node *right88 = new Node;
    right75->left = left62;
    right75->right = right88;
    left62->data = 62;
    right88->data = 88;
    left62->parent = right75;
    right88->parent = right75;

    //Node 6, 17
    Node *left6 = new Node;
    Node *right17 = new Node;
    left12->left = left6;
    left12->right = right17;
    left6->data = 6;
    right17->data = 17;
    left6->parent = left12;
    right17->parent = left12;
    left6->left = NULL;
    left6->right = NULL;

    //Node 30, 43
    Node *left30 = new Node;
    Node *right43 = new Node;
    right37->left = left30;
    right37->right = right43;
    left30->data = 30;
    right43->data = 43;
    left30->parent = right37;
    right43->parent = right37;
    left30->left = NULL;
    left30->right = NULL;
    right43->left = NULL;
    right43->right = NULL;

    //Node 56, 69
    Node *left56 = new Node;
    Node *right69 = new Node;
    left62->left = left56;
    left62->right = right69;
    left56->data = 56;
    right69->data = 69;
    left56->parent = left62;
    right69->parent = left62;
    left56->left = NULL;
    left56->right = NULL;
    right69->left = NULL;
    right69->right = NULL;

    //Node 81, 94
    Node *left81 = new Node;
    Node *right94 = new Node;
    right88->left = left81;
    right88->right = right94;
    left81->data = 81;
    right94->data = 94;
    left81->parent = right88;
    right94->parent = right88;
    right94->left = NULL;
    right94->right = NULL;

    //Node 21
    Node *right21 = new Node;
    right17->right = right21;
    right17->left = NULL;
    right21->data = 21;
    right21->parent = right17;
    right21->left = NULL;
    right21->right = NULL;

    //Node 85
    Node *right85 = new Node;
    left81->right = right85;
    left81->left = NULL;
    right85->data = 85;
    right85->parent = left81;
    right85->left = NULL;
    right85->right = NULL;

    //Make an array
    int Array[19] = {50, 25, 75, 12, 37, 62, 88, 6, 17, 30, 43, 56, 69, 81, 94, 21, 85, 0, 100};;

    //Search node
    for(int i = 0; i < 19; ++i)
    {
        std::cout << "Search Key: " << Array[i] << '\t';
        if(Treesearch(root, Array[i]) == NULL)
        {
            std::cout << "Data: " << "Not found" << std::endl;
        }
        else
        {
            std::cout << "Data: " << Treesearch(root, Array[i])->data << std::endl;
        }  
    }

    //Delete the nodes
    delete root;
    delete left25;
    delete right75;
    delete left12;
    delete right37;
    delete left62;
    delete right88;
    delete left6;
    delete right17;
    delete left30;
    delete right43;
    delete left56;
    delete right69;
    delete left81;
    delete right94;
    delete right21;
    return 0;
}

Node *Treesearch(Node *root, int search_key)
{
    if(root == NULL)
    {
        return NULL;
    }
    if(root->data == search_key)
    {
        return root;
    }
    else 
    {
        if(root->data < search_key)
        {
            return Treesearch(root->right, search_key);
        }
        else
        {
            return Treesearch(root->left, search_key);
        }    
    }
}