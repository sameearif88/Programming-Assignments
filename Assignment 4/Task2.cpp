#include <iostream>

class MyString
{
    private:
        char *str;
        int length;
        int findLength(char *ptr);
    public:
        MyString();
        MyString(char *ptr);
        ~MyString();
        int GetLength();
        void SetString(char *ptr);
        void SetString(MyString *ptr);
        bool IsEqualTo(char *ptr);
        bool IsEqualTo(MyString *ptr);
        void Concatenate(char *ptr);
        void Concatenate(MyString *ptr);
        int FindSubString(char *ptr);
        int FindSubString(MyString *ptr);
        void OutputString();
};

int main()
{
    //Declare character arrays and pass to MyString
    char CharArrayOne[4] = {'b', 'o', '3', '\0'};
    char CharArrayTwo[4] = {'o', '3', '\0'};
    MyString StringOne(CharArrayOne);
    MyString StringTwo(CharArrayTwo);
    
    //Compare
    std::cout << "STRING COMPARE:" << std::endl;
    bool Equal = StringOne.IsEqualTo(CharArrayTwo);
    if(Equal)
    {
        std::cout << "STRINGS ARE EQUAL!" << std::endl;
    }
    else
    {
        std::cout << "STRINGS ARE NOT EQUAL!" << std::endl;
    }
    std::cout << "---------------------------------" << std::endl;

    //Concatenate
    std::cout << "CONCATENATE:" << std::endl;
    StringOne.Concatenate(CharArrayTwo);
    StringOne.OutputString();
    std::cout << "---------------------------------" << std::endl;

    //Substring
    std::cout << "FIND SUBSTRING:" << std::endl;
    int Index = StringOne.FindSubString(CharArrayTwo);
    if(Index == -1)
    {
        std::cout << "SUBSTRING NOT FOUND!" << std::endl;
    }
    else
    {
        std::cout << "SUBSTRING STARTS FROM INDEX: " << Index << std::endl;
    }    
    return 0;
}

MyString::MyString()
{
    str = NULL;
    length = 0;
}

int MyString::findLength(char *ptr)
{
    int size = 0;
    //Increment size until we hit NULL character
    while(*(ptr + size) != '\0')
    {
        size++;
    }
    return size;
}

MyString::MyString(char *ptr)
{
    //Find the length of the character string
    length = findLength(ptr);
    str = new char[length + 1];
    //Store the characters in memory until we have NULL character
    for(int i = 0; i < length; ++i)
    {
        *(str + i) = *(ptr + i);
    }
    //Store the NULL character
    *(str + length) = '\0';
}

MyString::~MyString()
{
    delete [] str;
}

int MyString::GetLength()
{
    return length;
}

void MyString::SetString(char *ptr)
{
    //Delete the previous pointer
    delete [] str;
    //Find the length of the new character string
    length = findLength(ptr);
    str = new char[length + 1];
    //Store the characters in memory until we have NULL character
    for(int i = 0; i < length; ++i)
    {
        *(str + i) = *(ptr + i);
    }
    //Store the NULL character
    *(str + length) = '\0'; 
}

void MyString::SetString(MyString *ptr)
{
    SetString(ptr->str);
}

bool MyString::IsEqualTo(char *ptr)
{
    //Check if the length of the strings is equal
    if(*(str + length) == '\0' && *(ptr + length) == '\0')
    {
        //Loop thorugh each character
        for(int i = 0; i < length; ++i)
        {
            //Compare each character
            if(*(str + i) != *(ptr + i))
            {
                //Return false if a single character is different
                return false;
            }
        }
    }
    else
    {
        //Return false if length in not equal
        return false;
    }
    //Return true if both strings are equal
    return true;
}

bool MyString::IsEqualTo(MyString *ptr)
{
    return IsEqualTo(ptr->str);
}

void MyString::Concatenate(char *ptr)
{
    //Store the data in temp varaible
    MyString temp(str);
    //Deallocate the memory
    delete [] str;
    //Find the new length and allocate the memory
    length = temp.length + findLength(ptr);
    str = new char[length + 1];
    //Store the first character string in the memory
    for(int i = 0; i < temp.length; ++i)
    {
        *(str + i) = *(temp.str + i);
    }
    //Store the second character string in the memory
    int count = findLength(ptr);
    for(int i = temp.length; i < temp.length + count; ++i)
    {
        *(str + i) = *(ptr + i - temp.length);
    }
    //Store the NULL character
    *(str + length) = '\0';
}

void MyString::Concatenate(MyString *ptr)
{
    Concatenate(ptr->str);
}

int MyString::FindSubString(char *ptr)
{
    int count;
    int lengthTwo = 1;
    bool found;
    //Find the length of string 2
    while(*(ptr + lengthTwo) != '\0')
    {
        lengthTwo++;
    }
    //Loop thorgh each character of the string
    for(int i = 0; i < length - lengthTwo; ++i)
    {
        found = true;
        count = 0;
        //Check if we can find the substring until we hit the NULL character
        while(*(ptr + count) != '\0')
        {
            //If even a single character is different we set found to False and break the loop
            if(*(str + count + i) != *(ptr + count))
            {
                found = false;
                break;
            }
            count++;
        }
        //If found is still true after the loop we return the starting index
        if(found)
        {
            return i;
        }
    }
    //If substring was not found we return -1
    return -1;
}

int MyString::FindSubString(MyString *ptr)
{
    return FindSubString(ptr->str);
}

void MyString::OutputString()
{
    std::cout << str << std::endl;
}

