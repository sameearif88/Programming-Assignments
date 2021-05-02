#include <iostream>

bool validateString(std::string name);
std::string capitalize(std::string name);

int main()
{
    int n;
    std::string name;
    bool invalidString = false;

    //Enter the number of strings you want to enter
    system("cls");
    std::cout << "Enter a value for n: ";
    std::cin >> n;
    //Validate the input n
    while(std::cin.fail() || n < 0)
    {
        system("cls");
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Wrong entry!" << std::endl;
        std::cout << "Enter a value for n: ";
        std::cin >> n;
    }
    system("cls");

    //Declare an array with n elements
    std::string nameArray[n];
    std::string capitalizedNameArray[n];

    //Input n number of strings
    for(int i = 0; i < n; ++i)
    {
        //Enter string
        std::cout << "Enter string " << i + 1 << " : ";
        std::cin >> name;
        //Valide the string
        invalidString = validateString(name);
        while(invalidString == true)
        {
            system("cls");
            std::cout << "Wrong entry!" << std::endl;
            std::cout << "Enter string " << i + 1 << " : ";
            std::cin >> name;
            invalidString = validateString(name);   
        }
        //Store the string in the array
        nameArray[i] = name;
        capitalizedNameArray[i] = capitalize(name);
    }

    //Sort the array
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            //We will compare the elements of capitalized array
            if(capitalizedNameArray[j] > capitalizedNameArray[j + 1])
            {
                //Sort the capitalized array elements
                std::string temp;
                temp = capitalizedNameArray[j];
                capitalizedNameArray[j] = capitalizedNameArray[j + 1];
                capitalizedNameArray[j + 1] = temp;
                //Sort the original array elements
                temp = nameArray[j];
                nameArray[j] = nameArray[j + 1];
                nameArray[j + 1] = temp;
            }
        }
    }

    //Print the array
    if(n != 0)
    {
        std::cout << std::endl << "THE CORRECT ORDER OF STRING IS:" << std::endl;
        for(int i = 0; i < n; ++i)
        {
            std::cout << nameArray[i] << std::endl;
        }
    }
    else
    {
        std::cout << "N = 0 so no string was entered";
    }
    
}

bool validateString(std::string name)
{
    bool check = false;
    //Check each character of the string
    for(int j = 0; j < name.length(); ++j)
    {
        //Compare the ascii value of each character
        if((int(name[j]) < 65 || int(name[j]) > 90) && (int(name[j]) < 97 || int(name[j]) > 122))
        {
            //If the character is not an English alphabet then we return true
            check = true;
            break;
        }
    }
    return check;
}

std::string capitalize(std::string name)
{
    std::string temp = "";
    for(int i = 0; i < name.length(); ++i)
    {
        //If the character is small letter we convert it to capital letter
        if(int(name[i]) >= 97 && int(name[i]) <= 122)
        {
            temp += char(int(name[i]) - 32);
        }
        //Else we add it to the string as it is
        else
        {
            temp += name[i];
        }
    }
    return temp;
}

