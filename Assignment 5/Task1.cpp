#include <iostream>

char ConvertToUpperCase(char Alphabet);
char ConvertToLowerCase(char Alphabet);
void ConvertString(char *UserString, char (*Function)(char));

int main()
{
    int StringSize;
    //Enter and validate the size of the string
    std::cout << "Enter the size of the string you want to enter: ";
    std::cin >> StringSize;
    while(std::cin.fail() ||StringSize < 1)
    {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Wrong entry. Enter size of the string you want to enter: ";
        std::cin >> StringSize;
    }
    system("cls");

    //Declare char array of the size entered and input the string. Size + 1 for NULL character
    char UserString[StringSize + 1];
    std::cin.ignore(1000, '\n');
    std::cout << "Enter string: ";
    std::cin.get(UserString, StringSize + 1);
    system("cls");

    //Declare the function pointer array and store the addresses in the index
    char (*FunctionPointer[2])(char) = {&ConvertToUpperCase, &ConvertToLowerCase};
    
    //Ask if the user wants to convert to upper or lower case
    int choice = 0;
    std::cout << "1. Convert to upper case." << std::endl;
    std::cout << "2. Convert to lower case." << std::endl;
    std::cout << "Choice: ";
    std::cin >> choice;
    while(std::cin.fail() || choice < 1 && choice > 2)
    {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Wrong entry. Choice: ";
        std::cin >> choice;
    }
    system("cls");
    
    //Call the function StringConvert function for conversion
    std::cout << "Old string: ";
    std::cout << UserString << std::endl;
    ConvertString(UserString, FunctionPointer[choice - 1]);
    std::cout << "---------------------------------" << std::endl;
    std::cout << "Converted string: ";
    std::cout << UserString;
    return 0;
}

void ConvertString(char *UserString, char (*Function)(char))
{
    int count = 0;
    //Go through each character in the array and call the function to convert to upper or lower case
    while(*(UserString + count) != '\0')
    {
        *(UserString + count) = (*Function)(UserString[count]);
        count++;
    }
}

char ConvertToUpperCase(char Alphabet)
{
    //Convert only the uppercase letters to lowercase. Dont change other symbols
    if(Alphabet > 96 && Alphabet < 122)
    {
        return (Alphabet - 32);
    }
    return Alphabet;
}

char ConvertToLowerCase(char Alphabet)
{
    //Convert only the lowercase letters to uppercase. Dont change other symbols
    if(Alphabet > 64 && Alphabet < 90)
    {
        return (Alphabet + 32);
    }
    return Alphabet;
}

