#include <iostream>

template<typename Type>

class MyStack
{
    private:
        Type Array[100];
        int Head;
    public:
        MyStack();
        void Push(Type Data);
        void Pop();
        void Print();
};

void MainMenu(int &Choice);
void SubMenu(int &SubChoice);
template<typename TypeValidate>
void NumberValidate(TypeValidate &Number);
template<typename TypeValidate>
void InputData(TypeValidate &Data);
void InputDataC(char &Data);

int main()
{
    int Choice = 0;
    int SubChoice = 0;
    while(Choice != 4)
    {
        system("cls");
        MainMenu(Choice);
        SubChoice = 0;
        switch(Choice)
        {
            case 1:
            {   
                MyStack<int> Stack;
                while(SubChoice != 4)
                {
                    system("cls");
                    SubMenu(SubChoice);
                    switch(SubChoice)
                    {
                        case 1:
                        {   
                            int Data;
                            InputData(Data);
                            Stack.Push(Data);
                            Stack.Print();
                            break;
                        }
                        case 2:
                        {
                            Stack.Pop();
                            Stack.Print();
                            break;
                        }
                        case 3:
                        {
                            Stack.Print();
                            break;
                        }
                    }
                } 
                break;               
            }
            case 2:
            {
                MyStack<double> Stack;
                while(SubChoice != 4)
                {
                    system("cls");
                    SubMenu(SubChoice);
                    switch(SubChoice)
                    {
                        case 1:
                        {   
                            double Data;
                            InputData(Data);
                            Stack.Push(Data);
                            Stack.Print();
                            break;
                        }
                        case 2:
                        {
                            Stack.Pop();
                            Stack.Print();
                            break;
                        }
                        case 3:
                        {
                            Stack.Print();
                            break;
                        }
                    }
                }
                break;
            }
            case 3:
            {
                MyStack<char> Stack;
                while(SubChoice != 4)
                {
                    system("cls");
                    SubMenu(SubChoice);
                    switch(SubChoice)
                    {
                        case 1:
                        {   
                            char Data;
                            InputDataC(Data);
                            Stack.Push(Data);
                            Stack.Print();
                            break;
                        }
                        case 2:
                        {
                            Stack.Pop();
                            Stack.Print();
                            break;
                        }
                        case 3:
                        {
                            Stack.Print();
                            break;
                        }
                    }
                }
                break;
            }
        }
    }
    return 0;
}

template<typename Type>
MyStack<Type>::MyStack()
{
    Head = -1;
}

template<typename Type>
void MyStack<Type>::Push(Type Data)
{
    if(Head == 99)
    {
        std::cout << "Stack overflow." << std::endl;
        system("pause");
    }
    else
    {
        Head++;
        Array[Head] = Data; 
    }
}

template<typename Type>
void MyStack<Type>::Pop()
{
    if(Head == -1)
    {
        std::cout << "Stack underflow." << std::endl;
        system("pause");
    }
    else
    {
        Head--;
    }
}

template<typename Type>
void MyStack<Type>::Print()
{
    std::cout << "Stack:" << std::endl;
    for(int i = Head; i >= 0; --i)
    {
        std::cout << Array[i] << " ";
    }
    if(Head == -1)
    {
        std::cout << "Stack is empty.";
    }
    std::cout << std::endl;
    system("pause");
}

void MainMenu(int &Choice)
{
    std::cout << "1. Integer Stack" << std::endl;
    std::cout << "2. Double Stack" << std::endl;
    std::cout << "3. Character Stack" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << "Choice: ";
    std::cin >> Choice;
    NumberValidate(Choice);
    while(Choice < 0 || Choice > 4)
    {
        std::cout << "Wrong entry. Enter again: ";
        std::cin >> Choice;
        NumberValidate(Choice);
    }
}

void SubMenu(int &SubChoice)
{
    std::cin.ignore(1000, '\n');
    std::cout << "1. Push" << std::endl;
    std::cout << "2. Pop" << std::endl;
    std::cout << "3. Display" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << "Choice: ";
    std::cin >> SubChoice;
    NumberValidate(SubChoice);
    while(SubChoice < 0 || SubChoice > 4)
    {
        std::cout << "Wrong entry. Enter again: ";
        std::cin >> SubChoice;
        NumberValidate(SubChoice);
    }
}

template<typename TypeValidate>
void NumberValidate(TypeValidate &Number)
{
    while(std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Invalid input. Enter again: ";
        std::cin >> Number;
    }
}

template<typename TypeValidate>
void InputData(TypeValidate &Data)
{
    std::cin.ignore(1000, '\n');
    std::cout << "Enter data: ";
    std::cin >> Data;
    NumberValidate(Data);
}

void InputDataC(char &Data)
{
    std::cin.ignore(1000, '\n');
    std::cout << "Enter data: ";
    std::cin >> Data;
}

