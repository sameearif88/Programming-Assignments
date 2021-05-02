#include <iostream>
#include "Stack.h"

void MainMenu(int &Choice);
void InputChoice(int &Choice);
void InputData(int &Data);

int main()
{
    Stack Stack;
    int Choice = 0, Data;
    //Loop until user enters 4 to exit
    while(Choice != 4)
    {
        system("cls");
        MainMenu(Choice);
        switch(Choice)
        {
            case 1:
            {
                //Input data and pop
                InputData(Data);
                Stack.Push(Data);
                //Display the changes
                std::cout << "Stack after changes: ";
                Stack.Display();
                std::cout << "Press enter to continue...";
                std::cin.ignore();
                std::cin.get();
                break;
            }
            case 2:
            {
                //Pop
                Stack.Pop();
                //Display the changes
                std::cout << "Stack after changes: ";
                Stack.Display();
                std::cout << "Press enter to continue...";
                std::cin.ignore();
                std::cin.get();
                break;
            }
            case 3:
            {
                //Display
                Stack.Display();
                std::cout << "Press enter to continue...";
                std::cin.ignore();
                std::cin.get();
                break;
            }
        }
    }
    return 0;
}

void MainMenu(int &Choice)
{
    //Output the selections use can make
    std::cout << "1. Push" << std::endl;
    std::cout << "2. Pop" << std::endl;
    std::cout << "3. Display stack" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << "Enter choice: ";
    InputChoice(Choice);
}

void InputChoice(int &Choice)
{
    std::cin >> Choice;
    //If the user enters charater or string or out of range choice
    while(std::cin.fail() || Choice < 1 || Choice > 4)
    {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Wrong entry. Enter again: ";
    }
}

void InputData(int &Data)
{
    std::cout << "Enter data: ";
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
