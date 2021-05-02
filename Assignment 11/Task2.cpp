#include <iostream>

double Divide(int *Ptr, int Length, int IndexOne, int IndexTwo);

int main()
{
    int Length;
    int *Array;
    std::cout << "Enter length of the array: ";
    std::cin >> Length;
    while(std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Wrong entry. Enter length of the array: ";
        std::cin >> Length;
    }

    if(Length <= 0)
    {
        Array = NULL;
    }
    else
    {
        Array = new int[Length];
    }
    
    if(Array != NULL)
    {
        for(int i = 0; i < Length; ++i)
        {
            std::cout << "Enter element " << i + 1 << " of the array: ";
            std::cin >> Array[i];
            while(std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout << "Wrong entry. Enter element " << i + 1 << " of the array: ";
                std::cin >> Array[i];
            }
        }
    }       

    int IndexOne, IndexTwo;
    std::cout << "Enter Index one: ";
    std::cin >> IndexOne;
    while(std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Wrong entry. Enter Index one: ";
        std::cin >> IndexOne;
    }
    std::cout << "Enter Index two: ";
    std::cin >> IndexTwo;
    while(std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Wrong entry. Enter Index two: ";
        std::cin >> IndexTwo;
    }

    try
    {
        if(Array == NULL)
        {
            throw Array;
        }
        else if(IndexOne < 0 || IndexOne >= Length)
        {
            throw IndexOne;
        }
        else if(IndexTwo < 0 || IndexTwo >= Length)
        {
            throw IndexTwo;
        }
        else if(Array[IndexTwo] == 0)
        {
            throw 0;
        }
        else
        {
            double Answer = Divide(Array, Length, IndexOne, IndexTwo);
            std::cout << "Answer: " << Answer << std::endl;
        }
    }
    catch(const int Index)
    {
        if(IndexOne == Index)
        {
            std::cout << "Index one is out of bounds." << std::endl;
        }
        else if(IndexTwo == Index)
        {
            std::cout << "Index two is out of bounds." << std::endl; 
        }
        else
        {
            std::cout << "Math error: Value at index two is 0." << std::endl;
        }
    }
    catch(const int *Ptr)
    {
        std::cout << "The pointer to array is NULL." << std::endl;
    }

    delete [] Array;
}
++,


  
double Divide(int *Ptr, int Length, int IndexOne, int IndexTwo)
{
    return ((double)Ptr[IndexOne])/((double)Ptr[IndexTwo]);
}

