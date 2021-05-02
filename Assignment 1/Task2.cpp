#include <iostream>

int main()
{
    int length, temp, count = 1;
    std::cout << "Enter length of the array: ";
    std::cin >> length;
    int array[length];
    std::cout << "Enter " << length << " elements in the array:" << std::endl;
    for(int i = 0; i < length; ++i)
    {
        std::cin >> array[i];
    }
    std::cout << std::endl;

    for(int i = 0; i < length; ++i)
    {
        for(int k = 0; k < length - 1; ++k)
        {
            if(array[k] > array[k + 1])
            {
                temp = array[k + 1];
                array[k + 1] = array[k];
                array[k] = temp;
            }
        }
    }

    for(int i = 0; i < length; i += count)
    {
        count = 1;
        for(int k = i + 1; k < length; ++k)
        {
            if(array[i] == array[k])
            {
                count++;
            }
            else
            {
                break;
            }
        }
        std::cout << array[i] << ":" << count << std::endl;
    }
    return 0;
}