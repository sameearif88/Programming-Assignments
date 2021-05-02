#include <iostream>
#include "LinkedList.h"
#include "Node.h"

void MainMenu(int &Choice);
void InputChoice(int &Choice);
void InputIndex(int &Index);
void InputData(int &Data);

int main()
{
    LinkedList LinkedList1;
    int Choice = 0, Data, Index;
    bool Success;
    while(Choice != 12)
    {
        system("cls");
        MainMenu(Choice);
        switch(Choice)
        {
            case 1:
            {
                std::cout << "Enter data element: ";
                InputData(Data);
                std::cout << "Enter index on which you want to store the data: ";
                InputIndex(Index);
                Success = LinkedList1.InsertAt(Data, Index);
                if(Success)
                {
                    std::cout << "Data " << Data << " was successfull added at index " << Index << std::endl;
                    std::cin.ignore();
                    std::cout << "Press enter to continue...";
                    std::cin.get(); 
                }
                else
                {
                    std::cout << "Data " << Data << " was not added at index " << Index << std::endl;
                    std::cin.ignore();
                    std::cout << "Press enter to continue...";
                    std::cin.get();
                }
                break;
            }
            case 2:
            {
                std::cout << "Enter data element: ";
                InputData(Data);
                Success = LinkedList1.InsertHead(Data);
                std::cout << "Data " << Data << " was successfull added at the head" << std::endl;
                std::cin.ignore();
                std::cout << "Press enter to continue...";
                std::cin.get(); 
                break;
            }
            case 3:
            {
                std::cout << "Enter data element: ";
                InputData(Data);
                Success = LinkedList1.InsertEnd(Data);
                std::cout << "Data " << Data << " was successfull added at the end" << std::endl;
                std::cin.ignore();
                std::cout << "Press enter to continue...";
                std::cin.get(); 
                break;
            }
            case 4:
            {
                std::cout << "Enter index on you want to remove: ";
                InputIndex(Index);
                Success = LinkedList1.RemoveAt(Index);
                if(Success)
                {
                    std::cout << "Data was successfull removed from index " << Index << std::endl;
                    std::cin.ignore();
                    std::cout << "Press enter to continue...";
                    std::cin.get(); 
                }
                else
                {
                    std::cout << "Data was not remove from index " << Index << std::endl;
                    std::cin.ignore();
                    std::cout << "Press enter to continue...";
                    std::cin.get();
                }
                break;
            }
            case 5:
            {
                Success = LinkedList1.RemoveHead();
                if(Success)
                {
                    std::cout << "Data was successfull removed from head" << std::endl;
                    std::cin.ignore();
                    std::cout << "Press enter to continue...";
                    std::cin.get(); 
                }
                else
                {
                    std::cout << "Data was not remove from head" << std::endl;
                    std::cin.ignore();
                    std::cout << "Press enter to continue...";
                    std::cin.get();
                }
                break;
            }
            case 6:
            {
                Success = LinkedList1.RemoveEnd();
                if(Success)
                {
                    std::cout << "Data was successfull removed from end" << std::endl;
                    std::cin.ignore();
                    std::cout << "Press enter to continue...";
                    std::cin.get(); 
                }
                else
                {
                    std::cout << "Data was not remove from end" << std::endl;
                    std::cin.ignore();
                    std::cout << "Press enter to continue...";
                    std::cin.get();
                }
                break;
            }
            case 7:
            {
                LinkedList1.DisplayList();
                std::cin.ignore();
                std::cout << "Press enter to continue...";
                std::cin.get();
                break;
            }
            case 8:
            {
                int *d_ptr;
                std::cout << "Enter index on you want to get data from: ";
                InputIndex(Index);
                Success = LinkedList1.GetData(Index, d_ptr);
                if(Success)
                {
                    std::cout << "Data element at index " << Index << " : " << *d_ptr << std::endl;
                    std::cin.ignore();
                    std::cout << "Press enter to continue...";
                    std::cin.get();
                }
                else
                {
                    std::cout << "Element does not exits at index " << Index << std::endl;
                    std::cin.ignore();
                    std::cout << "Press enter to continue...";
                    std::cin.get();
                }
                break;
            }
            case 9:
            {
                std::cout << "Enter data element: ";
                InputData(Data);
                std::cout << "Enter index on which you want to store the data: ";
                InputIndex(Index);
                Success = LinkedList1.SetData(Index, Data);
                if(Success)
                {
                    std::cout << "Data element " << Data << " was stored at index " << Index << std::endl;
                    std::cin.ignore();
                    std::cout << "Press enter to continue...";
                    std::cin.get();
                }
                else
                {
                    std::cout << "Data element " << Data << " was not stored at index " << Index << std::endl;
                    std::cin.ignore();
                    std::cout << "Press enter to continue...";
                    std::cin.get();
                }
                break;  
            }
            case 10:
            {
                std::cout << "Length of the linkedlist: ";
                std::cout << LinkedList1.GetLength() << std::endl;
                std::cin.ignore();
                std::cout << "Press enter to continue...";
                std::cin.get();
                break;
            }
            case 11:
            {
                Success = LinkedList1.Empty();
                if(Success)
                {
                    std::cout << "Linkedlist was deleted" << std::endl;
                    std::cin.ignore();
                    std::cout << "Press enter to continue...";
                    std::cin.get();
                }
                else
                {
                    std::cout << "Linkedlist is already empty" << std::endl;
                    std::cin.ignore();
                    std::cout << "Press enter to continue...";
                    std::cin.get();
                }
            }
        }
    }
    system("cls");
    std::cout << "Copy linked list using constructor and display: " << std::endl;
    LinkedList CopyLinkedList(LinkedList1);
    CopyLinkedList.DisplayList();
    std::cin.ignore();
    std::cin.get();
    return 0;
}

void MainMenu(int &Choice)
{
    std::cout << "1. Insert At" << std::endl;
    std::cout << "2. Insert Head" << std::endl;
    std::cout << "3. Insert End" << std::endl;
    std::cout << "4. Remove At" << std::endl;
    std::cout << "5. Remove Head" << std::endl;
    std::cout << "6. Remove End" << std::endl;
    std::cout << "7. Display List" << std::endl;
    std::cout << "8. Get Data" << std::endl;
    std::cout << "9. Set Data" << std::endl;
    std::cout << "10. Get Length" << std::endl;
    std::cout << "11. Empty" << std::endl;
    std::cout << "12. Exit" << std::endl;
    std::cout << "Enter choice: ";
    InputChoice(Choice);
}

void InputChoice(int &Choice)
{
    std::cin >> Choice;
    //If the user enters charater or string or out of range choice
    while(std::cin.fail() || Choice < 1 || Choice > 12)
    {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Wrong entry. Enter again: ";
    }
}

void InputIndex(int &Index)
{
    std::cin >> Index;
    //If the user enters charater or string or out of range index
    while(std::cin.fail() || Index < 0)
    {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Wrong entery enter again: ";
        std::cin >> Index;
    }
}

void InputData(int &Data)
{
    std::cin >> Data;
    //If the user enters charater or string
    while(std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "wrong entry. Enter again: ";
        std::cin >> Data;
    }
}

