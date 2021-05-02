#include <iostream>

struct Tree
{
    int Data;
    Tree *Right;
    Tree *Left;
    Tree *Parent;
};

void Insert(Tree *&root, int data);
void Delete(Tree *root, int data);
void InorderTraversal(Tree *root);
void MainMenu(int &choice);
void InputValidation(int &number);
void Deallocate(Tree *root);

int main()
{
    int data = 0;
    Tree *root = NULL;
    int choice = 0;
    while(choice != 4)
    {
        system("cls");
        MainMenu(choice);
        switch(choice)
        {
            case 1:
            {
                std::cout << "Enter data you want to insert: ";
                std::cin >> data;
                InputValidation(data);
                Insert(root, data);
                break;
            }
            case 2:
            {
                std::cout << "Enter data you want to delete: ";
                std::cin >> data;
                Delete(root, data);
                break;
            }
            case 3:
            {
                InorderTraversal(root);
                std::cin.ignore();
                std::cout << std::endl << "Press enter to continue...";
                std::cin.get();
                break;
            }
        }
    }
    Deallocate(root);
    return 0;
}

void MainMenu(int &choice)
{
    std::cout << "1. Insert" << std::endl;
    std::cout << "2. Delete" << std::endl;
    std::cout << "3. Inorder Traversal" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << "Choice: ";
    std::cin >> choice;
    InputValidation(choice);
    while(choice < 1 && choice > 4)
    {
        std::cout << "Wrong entry. Enter again: ";
        std::cin >> choice;
        InputValidation(choice);
    }
}

void InputValidation(int &number)
{
    while(std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Wrong entry. Enter again: ";
        std::cin >> number;
    }
}

void Deallocate(Tree *root)
{
    if(root == NULL)
    {
        return;
    }
    else
    {
        Deallocate(root->Left);
        Deallocate(root->Right);
        delete root;
    }
}

void Insert(Tree *&root, int data)
{
    if(root == NULL)
    {
        root = new Tree;
        root->Data = data;
        root->Left = NULL;
        root->Right = NULL;
        root->Parent = NULL;
    }
    else
    {
        if(data <= root->Data)
        {
            if(root->Left == NULL)
            {
                root->Left = new Tree;
                root->Left->Data = data;
                root->Left->Left = NULL;
                root->Left->Right = NULL;
                root->Left->Parent = root;
            }
            else
            {
                Insert(root->Left, data);
            }
        }
        else
        {
            if(root->Right == NULL)
            {
                root->Right = new Tree;
                root->Right->Data = data;
                root->Right->Left = NULL;
                root->Right->Right = NULL;
                root->Right->Parent = root;
            }
            else
            {
                Insert(root->Right, data);
            }
        }
    }
}

void Delete(Tree *root, int data)
{
    if(root == NULL)
    {
        return;
    }
    Tree *DeleteNode = root;
    while(DeleteNode->Data != data)
    {
        if(data <= DeleteNode->Data)
        {
            DeleteNode = DeleteNode->Left;
        }
        else
        {
            DeleteNode = DeleteNode->Right;
        }
        if(DeleteNode == NULL)
        {
            break;
        }
    }
    if(DeleteNode == NULL)
    {
        return;
    }
    if(DeleteNode->Left == NULL && DeleteNode->Right == NULL)
    {
        if(DeleteNode == root)
        {
            delete root;
            root = NULL;
        }
        else
        {
            if(DeleteNode->Parent->Left == DeleteNode)
            {
                DeleteNode->Parent->Left = NULL;
                delete DeleteNode;
            }
            else
            {
                DeleteNode->Parent->Right = NULL;
                delete DeleteNode;
            }
        }
    }
    else if(DeleteNode->Left == NULL || DeleteNode->Right == NULL)
    {
        if(DeleteNode == root)
        {
            root->Data = DeleteNode->Data;
            if(root->Left != NULL)
            {
                delete root->Left;
                root->Left = NULL;
            }
            else
            {
                delete root->Right;
                root->Right = NULL;
            }
        }
        else
        {
            if(DeleteNode->Parent->Left == DeleteNode)
            {
                if(DeleteNode->Left != NULL)
                {
                    DeleteNode->Data = DeleteNode->Left->Data;
                    delete DeleteNode->Left;
                    DeleteNode->Left = NULL;
                }
                else
                {
                    DeleteNode->Data = DeleteNode->Right->Data;
                    delete DeleteNode->Right;
                    DeleteNode->Right = NULL;
                }
            }
        }
    }
    else
    {
        Tree *SuccessorNode = DeleteNode->Right;
        while(SuccessorNode->Left != NULL)
        {
            SuccessorNode = SuccessorNode->Left;
        }
        DeleteNode->Data = SuccessorNode->Data;
        if(SuccessorNode->Parent->Left == SuccessorNode)
        {
            SuccessorNode->Parent->Left = NULL;
            delete SuccessorNode;
        }
        else
        {
            SuccessorNode->Parent->Right = NULL;
            delete SuccessorNode;
        }
    }
}

void InorderTraversal(Tree *root)
{
    if(root != NULL)
    {
        InorderTraversal(root->Left);
        std::cout << root->Data << " ";
        InorderTraversal(root->Right);
    }
}

