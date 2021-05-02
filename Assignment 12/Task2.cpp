#include <iostream>
#include <queue>

template<typename Type>
class MyQueue
{
    private:
        std::queue<Type> Queue;
    public:
        void Enqueue(Type Data);
        void Dequeue();
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
                MyQueue<int> Queue;
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
                            Queue.Enqueue(Data);
                            Queue.Print();
                            break;
                        }
                        case 2:
                        {
                            Queue.Dequeue();
                            Queue.Print();
                            break;
                        }
                        case 3:
                        {
                            Queue.Print();
                            break;
                        }
                    }
                } 
                break;               
            }
            case 2:
            {
                MyQueue<double> Queue;
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
                            Queue.Enqueue(Data);
                            Queue.Print();
                            break;
                        }
                        case 2:
                        {
                            Queue.Dequeue();
                            Queue.Print();
                            break;
                        }
                        case 3:
                        {
                            Queue.Print();
                            break;
                        }
                    }
                }
                break;
            }
            case 3:
            {
                MyQueue<char> Queue;
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
                            Queue.Enqueue(Data);
                            Queue.Print();
                            break;
                        }
                        case 2:
                        {
                            Queue.Dequeue();
                            Queue.Print();
                            break;
                        }
                        case 3:
                        {
                            Queue.Print();
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
void MyQueue<Type>::Enqueue(Type Data)
{
    Queue.push(Data);
}

template<typename Type>
void MyQueue<Type>::Dequeue()
{
    Queue.pop();
}

template<typename Type>
void MyQueue<Type>::Print()
{
    std::cout << "Queue: " << std::endl;
    std::queue<Type> QueueTemp = Queue;
    if(QueueTemp.empty())
    {
        std::cout << "Queue is empty.";
    }
    while(!QueueTemp.empty())
    {
        std::cout << QueueTemp.front() << " ";
        QueueTemp.pop();
    }
    std::cout << std::endl;
    system("pause");
}

void MainMenu(int &Choice)
{
    std::cout << "1. Integer Queue" << std::endl;
    std::cout << "2. Double Queue" << std::endl;
    std::cout << "3. Character Queue" << std::endl;
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
    std::cout << "1. Enqueue" << std::endl;
    std::cout << "2. Dequeue" << std::endl;
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

