#include <iostream>

bool compare(int arrayOne[], int lengthOne, int arrayTwo[], int lengthTwo);

int main()
{
    int lengthOne, lengthTwo;
    bool isEqual;
    std::cout << "Enter length of array one: ";
    std::cin >> lengthOne;
    std::cout << "Enter length of array two: ";
    std::cin >> lengthTwo;
    int arrayOne[lengthOne], arrayTwo[lengthTwo];
    std::cout << "Enter " << lengthOne << " numbers in array one: " << std::endl;
    for(int i = 0; i < lengthOne; ++i)
    {
        std::cin >> arrayOne[i];
    }
    std::cout << "Enter " << lengthTwo << " numbers in array two: " << std::endl;
    for(int i = 0; i < lengthTwo; ++i)
    {
        std::cin >> arrayTwo[i];
    }
    isEqual = compare(arrayOne, lengthOne, arrayTwo, lengthOne);
    if(isEqual == true)
    {
        std::cout << "Arrays are equal!";
    }
    else
    {
        std::cout << "Arrays are not equal!";
    }
    
    return 0;
}

bool compare(int arrayOne[], int lengthOne, int arrayTwo[], int lengthTwo)
{
    if(lengthOne == lengthTwo)
    {
        for(int i = 0; i < lengthOne; ++i)
        {
            if(arrayOne[i] != arrayTwo[i])
            {
                return false;
            }
        }
        return true;
    }
    else
    {
        return false;
    }
    
}