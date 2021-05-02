#include <iostream>
#include "DoubleLinkedList.h"

Node* DoubleLinkedList::GetNode(int index) const
{
    /*Check if the index is not greater than equal to the length of the linked list
    or if the Head pointer is NULL. Then return NULL*/
    if(index >= Length)
    {
        return NULL;
    }
    else
    {
        //If the index is in range return the pointer
        Node *Temp = Head;
        //Run the loop until we get to the index for which we want the pointer
        for(int i = 0; i < index; ++i)
        {
            Temp = Temp->GetNextPointer();
        }
        return Temp;
    }
} 

DoubleLinkedList::DoubleLinkedList()
{
    Head = NULL;
    Length = 0;
}

DoubleLinkedList::~DoubleLinkedList()
{
    //Traverse through the linkedlist and delete each node
    Node *Temp = Head;
    Node *Temp1 = Head;
    Node *TempHead = Head;
    while(Head != NULL)
    {
        Head = Temp->GetNextPointer();
        TempHead = Temp->GetPreviousPointer();
        delete Temp;
        delete Temp1;
        Temp = Head;
        Temp1 = TempHead;
    }
}

DoubleLinkedList::DoubleLinkedList(DoubleLinkedList &OldLinkedList)
{
    int data = 0;
    int *d_ptr = &data;
    bool Check;
    //Loop until the end of the old list
    for(int i = OldLinkedList.GetLength() - 1; i >= 0; --i)
    {
        //Store the data at index i in d_ptr
        Check = OldLinkedList.GetData(i, d_ptr);
        //If we are running it for first time we allocate memory for head
        if(i == OldLinkedList.GetLength() - 1)
        {
            Head = new Node(*d_ptr);
        }
        //Store the data
        else
        {
            Node *Temp = new Node(*d_ptr);
            Temp->SetNextPointer(Head);
            Head->SetPreviousPointer(Temp);
            Head = Temp;
        }   
    }
}

bool DoubleLinkedList::InsertAt(int data, int index)
{
    //Call the function to see if we can insert or not
    Node *Temp = GetNode(index - 1);
    //If the function returns NULL we cannot insert but we can insert if the head pointer is NULL
    if(Temp == NULL && index != 0)
    {
        return false;
    }
    else
    {
        //Check if the head pointer is NULL which means linkedlist is empty or the index is 0
        if(Head == NULL || index == 0)
        {
            //Just set the head pointer to the new node
            return InsertHead(data);
        }
        //Check if the index we want to insert at is tail
        else if(index == Length)
        {
            //Just set the head pointer to the new node
            return InsertEnd(data);
        }
        //Insert at the given index
        else
        {
            //Create a new node
            Node *Temp1 = new Node(data);
            //Traverse though the linkedlist and go to the index 
            Node *Temp2 = Head;
            for(int i = 0; i < index; ++i)
            {
                Temp2 = Temp2->GetNextPointer();
            }
            //Set the next pointer of the new node to next node
            Temp1->SetNextPointer(Temp2->GetNextPointer());
            //Point the end node to the next new node
            Temp2->SetNextPointer(Temp1);
            //Set the next pointer of the new node to next node
            Temp1->SetPreviousPointer(Temp2);
            //Traverse through the linked list to get index + 1
            Temp2 = Head;
            for(int i = 0; i <= index; ++i)
            {
                Temp2 = Temp2->GetNextPointer();
            }
            //Set the previous pointer of index + 1 to the new node
            Temp2->SetPreviousPointer(Temp1);
            //Increment the length
            Length++;
            return true;
        }
    }
}

bool DoubleLinkedList::InsertHead(int data)
{
    //Create a new node
    Node *Temp = new Node(data);
    //Check if the head pointer is NULL which means the list is empty
    if(Head == NULL)
    {
        Head = Temp;
    }
    //If the list is not empty
    else
    {
        //Set the pointer of the new node to the starting node
        Temp->SetNextPointer(Head);
        //Set the pointer of the new node to the starting node
        Head->SetPreviousPointer(Temp);
        //Set the head pointer to the new node
        Head = Temp;
    }
    //Increment the lenght of the linked list
    Length++;
    return true;
}

bool DoubleLinkedList::InsertEnd(int data)
{
    //Create a new node
    Node *Temp1 = new Node(data);
    //Check if the head pointer is NULL which means the list is empty so end is the start
    if(Head == NULL)
    {
        Head = Temp1;
    }
    //If the list is not empty
    else
    {
        //Traverse though the linkedlist and go to the end 
        Node *Temp2 = Head;
        while(Temp2->GetNextPointer() != NULL)
        {
            Temp2 = Temp2->GetNextPointer();
        }
        //Point the end node to the new node
        Temp2->SetNextPointer(Temp1);
        //Set the pointer of the new node to NULL to indicate the end of the linkedlist
        Temp1->SetNextPointer(NULL);
        //Set previous pointer
        Temp1->SetPreviousPointer(Temp2);
    }
    //Increment the length of the list
    Length++;
    return true;
}

bool DoubleLinkedList::RemoveAt(int index)
{
    if(index >= Length || Head == NULL)
    {
        return false;
    }
    else
    {
        //If the index is 0 we have to remove head
        if(index == 0)
        {
            return RemoveHead();
        }
        //If the index is lenth - 1 then we have to remove end
        else if(index == Length - 1)
        {
            return RemoveEnd();
        }
        //Else the index is in between head and the end
        else
        {
            //Traverse till index - 1
            Node *Temp = Head;
            for(int i = 0; i < index - 1; ++i)
            {
                Temp = Temp->GetNextPointer();
            }
            //Traverse till index + 1
            Node *Temp1 = Head;
            for(int i = 0; i < index; ++i)
            {
                Temp1 = Temp1->GetNextPointer();
            }
            //Set the next pointer of index - 1 to the address of index + 1
            Temp->SetNextPointer(Temp1->GetNextPointer());
            //Delete the node
            delete Temp1;
            //Set the previous pointer of index + 1 to index - 1
            Temp1 = Head;
            for(int i = 0; i < index; ++i)
            {
                Temp1 = Temp1->GetNextPointer();
            }
            Temp1->SetPreviousPointer(Temp);
            //Decrement the length of the list
            Length--;
            return true;
        }
    }
}

bool DoubleLinkedList::RemoveHead()
{
    //Check if the linkedlist is empty
    if(Head == NULL)
    {
        return false;
    }
    //If the linkedlist is not empty delete the element
    else
    {
        Node *Temp = Head;
        //Assign head pointer the address of the 2nd element
        Head = Head->GetNextPointer();
        //Set the previous pointer of the new 1st element to NULL
        Head->SetPreviousPointer(NULL);
        //Decrement the length
        Length--;
        //Delete the node
        delete Temp;
        return true;
    }
}

bool DoubleLinkedList::RemoveEnd()
{
    //Check if the linkedlist is empty
    if(Head == NULL)
    {
        return false;
    }
    //If the linkedlist is not empty delete the element
    else
    {
        //Traverse through the linkedlist until you get the 2nd last element
        Node *Temp = Head;
        if(Length > 1)
        {
            while((Temp->GetNextPointer())->GetNextPointer() != NULL)
            {
                Temp = Temp->GetNextPointer();
            }
            //Delete the last node
            Node* Temp1 = Temp->GetNextPointer();
            delete Temp1;
            //Set the next pointer to NULL
            Temp->SetNextPointer(NULL);
            //Decrement the length
            Length--;
        }
        else
        {
            //Deallocate memory for the last index
            Node *Temp = Head->GetNextPointer();
            delete Temp;
            //Deallocate memory for head pointer
            delete Head;
            //Set the head pointer to NULL and decrement the length
            Head = NULL;
            Length--;
        }
        
        return true;
    }
}

bool DoubleLinkedList::GetData(int index, int *d_ptr) const
{
    //If the index is greater than or equal to the length we cannot find the data
    if(index >= Length)
    {
        return false;
    }
    //Find the data if index is smaller than length
    else
    {
        //Traverse to the index you want data of
        Node *Temp = Head;
        for(int i = 0; i < index; ++i)
        {
            Temp = Temp->GetNextPointer();
        }
        //Store the data in the address the pointer points to
        *d_ptr = Temp->GetData();
        return true;
    }
}

bool DoubleLinkedList::SetData(int index, int d)
{
    //If the index is greater than or equal to the length we cannot find the data
    if(index >= Length)
    {
        return false;
    }
    //Find the data if index is smaller than length
    else
    {
        //Traverse to the index you want data of
        Node *Temp = Head;
        for(int i = 0; i < index; ++i)
        {
            Temp = Temp->GetNextPointer();
        }
        //Store the data in the index
        Temp->SetData(d);
        return true;
    }
}

int DoubleLinkedList::GetLength() const
{
    return Length;
}

bool DoubleLinkedList::Empty()
{
    //If the head pointer is NULL no need to delete
    if(Head == NULL)
    {
        return false;
    }
    else
    {
        //Traverse through the linkedlist and delete each node
        Node *Temp = Head;
        while(Head != NULL)
        {
            Head = Temp->GetNextPointer();
            delete Temp;
            Temp = Head;
        }
        //Set the head pointer to NULL and length to 0
        Head = NULL;
        Length = 0;
        return true;
    }
}

void DoubleLinkedList::DisplayList() const
{
    //If the head pointer is NULL then the linkedlist is emply
    if(Head == NULL)
    {
        std::cout << "Linkedlist is empty" << std::endl;
    }
    //Output the linkedlist if the head pointer is not NULL
    else
    {
        Node *Temp = Head;
        std::cout << Head << "-->";
        while (Temp->GetNextPointer() != NULL)
        {
            std::cout << "[" << Temp->GetPreviousPointer() << "]" << "[" << Temp->GetData() << "]" << "[" << Temp->GetNextPointer() << "]" << "<-->";
            Temp = Temp->GetNextPointer();
        }
        std::cout << "[" << Temp->GetPreviousPointer() << "]" << "[" << Temp->GetData() << "]" << "[" << Temp->GetNextPointer() << "]";
        std::cout << std::endl;
    }
}

