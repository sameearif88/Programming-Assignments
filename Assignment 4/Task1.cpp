#include <iostream>

class Set
{
    private:
        int *set;
        int length;
        int getSizeUnion(Set s2);
        int getSizeIntersection(Set s2);
        int getSizeDifference(Set s2);
    public:
        Set();
        Set(int array[], int size);
        ~Set();
        void OutputSet();
        Set Union(Set s2);
        Set Intersection(Set s2);
        Set Difference(Set s2);
        bool Compare(Set s2);
};

int main()
{
    int num[8] = {1, 2, 3, 5, 11, 22, -4 , -5};
    int num2[6] = {4, -4, 5, 1, 3, 2};
    //Change these parameters if you change array length
    Set set1(num, 8);
    Set set2(num2, 6);
    Set Union = set1.Union(set2);
    std::cout << "SET ONE:";
    set1.OutputSet();
    std::cout << "SET TWO:";
    set2.OutputSet();
    std::cout << "---------------------------------" << std::endl;
    std::cout << "UNION: ";
    Union.OutputSet();
    std::cout << "---------------------------------" << std::endl;
    Set Intersection = set1.Intersection(set2);
    std::cout << "INTERSECTION: ";
    Intersection.OutputSet();
    std::cout << "---------------------------------" << std::endl;
    Set Difference = set1.Difference(set2);
    std::cout << "DIFFERENCE: ";
    Difference.OutputSet();
    std::cout << "---------------------------------" << std::endl;
    bool Compare = set1.Compare(set2);
    if(Compare)
    {
        std::cout << "SETS ARE EQUAL" << std::endl;
    }
    else
    {
        std::cout << "SETS ARE NOT EQUAL" << std::endl;
    }
    
    return 0;
}

Set::Set()
{
    set = NULL;
    length = 0;
}

Set::Set(int array[], int size)
{
    //Allocate memory to the set
    set = new int[size];
    length = 0;
    int *ptr = set;
    bool elementFound = false;
    //Loop till the last element of the function
    for(int i = 0; i < size; ++i)
    {
        //Check if the element is already stored
        for(int* p = ptr; p > set; --p)
        {
            if(array[i] == *(p - 1))
            {
                elementFound = true;
                break;
            }
        }
        //Store the element in memory if it is distinct
        if(!elementFound || ptr == set)
        {
            *ptr = array[i];
            ptr++;
            length++;
        }
        elementFound = false;
    }
}

Set::~Set()
{
    delete [] set;
    set = NULL;
}

void Set::OutputSet()
{
    int count = 0;
    std::cout << "{";
    //Go through the whole lenght of the set and output elements
    while(count < length)
    {
        if(count == length - 1)
        {
            std::cout << *(set + count);  
            count++; 
        }
        else
        {
            std::cout << *(set + count) << ", ";
            count++;
        }
    }
    std::cout << "}" << std::endl;
}

int Set::getSizeUnion(Set s2)
{
    //Set the size of memory to be allocated to the length of function 1
    int size = length;
    bool found;
    //Loop through each item of set 2
    for(int *i = s2.set; i < (s2.set + s2.length); ++i)
    {
        found = false;
        //Loop through each item of set 1
        for(int *j = set; j < (set + length); ++j)
        {
            //If the item in both set is equal then set found to true
            if(*i == *j)
            {
                found = true;
                break;
            }
        }
        //If found is false we will increment the size we need
        if(!found)
        {
            size++;
        }
    }
    return size;
}

Set Set::Union(Set s2)
{
    Set Union;
    Union.length = getSizeUnion(s2);
    Union.set = new int[Union.length];
    bool alreadyStored = false;
    int count = 0;
    //Store all elements of the 1st set in the union set
    for(int *i = set; i < (set + length); ++i)
    {
        *(Union.set + count) = *i;
        count++;
    }
    int *check = (Union.set + count);
    //Store all the elements from 2nd set that are not already stored in the union set 
    for(int *i = s2.set; i < (s2.set + s2.length); ++i)
    {
        //Check if the element in the 2nd set is already stored in union set
        for(int *j = check; j >= Union.set; --j)
        {
            if(*i == *j)
            {
                alreadyStored = true;
                break;
            }
        }
        //If the element is not already stored then store it in union set
        if(!alreadyStored)
        {
            *(Union.set + count) = *i;
            count++;
        }
        alreadyStored = false;
    }
    return Union;
}

int Set::getSizeIntersection(Set s2)
{
    int size = 0;
    //Loop through 1st set
    for(int *i = set; i < (set + length); ++i)
    {
        //Loop through 2nd set
        for(int *j = s2.set; j < (s2.set + s2.length); ++j)
        {
            //If the element in both set is equal increment size
            if(*i == *j)
            {
                size++;
                break;
            }
        }
    }
    return size;
}

Set Set::Intersection(Set s2)
{
    Set Intersection;
    Intersection.length = getSizeIntersection(s2);
    Intersection.set = new int[Intersection.length];
    int count = 0;
    //Go through the elements of the 1st set
    for(int *i = set; i < (set + length); ++i)
    {
        //Check if the element of 1st set exisits in set 2
        for(int *j = s2.set; j < (s2.set + s2.length); ++j)
        {
            //If the element exisits in both sets store it in intersection set
            if(*i == *j)
            {
                *(Intersection.set + count) = *i;
                count++;
                break;
            }
        }
    }
    return Intersection;
}

int Set::getSizeDifference(Set s2)
{
    //Subtract the length of set 1 from length of intersection
    int size = length - getSizeIntersection(s2);
    return size;
}

Set Set::Difference(Set s2)
{
    Set Difference;
    Difference.length = getSizeDifference(s2);
    Difference.set = new int[Difference.length];
    bool found = false;
    int count = 0;
    //Go through the elements of the 1st set
    for(int *i = set; i < (set + length); ++i)
    {
        //Check if the element of 1st set exisits in set 2
        for(int *j = s2.set; j < (s2.set + s2.length); ++j)
        {
            //If the element exisits in both sets found varaible is set to true
            if(*i == *j)
            {
                found = true;
                break;
            }
        }
        //If the element of set 1 was not found in set 2 store it in difference set
        if(!found)
        {
            *(Difference.set + count) = *i;
            count++;
        }
        found = false;
    }
    return Difference;
}

bool Set::Compare(Set s2)
{
    bool found = false;
    //Check if the lengths of the two sets are equal
    if(length = s2.length)
    {
        //Go through the elements of the 1st set
        for(int *i = set; i < (set + length); ++i)
        {
            found = false;
            //Check if the element in 1st set is found in 2nd set
            for(int *j = s2.set; j < (s2.set + s2.length); ++j)
            {
                //If the element is found then set found to true
                if(*i == *j)
                {
                    found = true;
                    break;
                }
            }
        }
    }
    //If the length of the two sets are not equal then sets are not equal
    else
    {
        return false;
    }
    //If all elements in set 1 exists in set 2 the sets are equal
    if(found)
    {    
        return true;
    }
    //If all elements in set 1 don't exist in set 2 the sets are not equal 
    else
    {
        return false;
    }
}

