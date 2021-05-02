#include <iostream>
#include <iomanip>

class Person
{
    protected:
        std::string Name;
        std::string CNICNumber;
    public:
        Person();
        Person(std::string Name, std::string CNICNumber);
        std::string GetCNIC();
        virtual void Display();
};

class Employe : virtual public Person
{
    protected:
        std::string EmployeID;
        double Salary;
    public:
        Employe();
        Employe(std::string EmployeID, double Salary, std::string Name, std::string CNICNumber);
        std::string GetEmployeID();
        virtual void Display();
};

class Student : virtual public Person
{
    protected:
        std::string StudentID;
        double CGPA;
    public:
        Student();
        Student(std::string StudentID, double CGPA, std::string Name, std::string CNICNumber);
        std::string GetStudentID();
        virtual void Display();
};

class TeachingAssistant : public Employe, public Student
{
    public:
        TeachingAssistant();
        TeachingAssistant(std::string EmployeID, double Salary, std::string StudentID, double CGPA, 
                          std::string Name, std::string CNICNumber);
        void Display();
};

void MainMenu(int &Choice);
void SubMenu(int & SubChoice);
void ValidateInt(int &Number);
void ValidateDouble(double &Number);
bool ValidateCNIC(std::string &CNICNumber, Person *Ptr[], int &Tail);
bool ValidateEmployeID(std::string &EmployeID, Person *Ptr[], int &Tail);
bool ValidateStudentID(std::string &StudentID, Person *Ptr[], int &Tail);
void InputPersonData(std::string &Name, std::string &CNICNumber, Person *Ptr[], int &Tail);
void InputEmployeData(std::string &Name, std::string &CNICNumber, std::string &EmployeID, double &Salary, Person *Ptr[], int &Tail);
void InputStudentData(std::string &Name, std::string &CNICNumber, std::string &StudentID, double &CGPA, Person *Ptr[], int &Tail);
void InputTAData(std::string &Name, std::string &CNICNumber, std::string &StudentID, double &CGPA, std::string &EmployeID, double &Salary,
                 Person *Ptr[], int &Tail);

int main()
{
    Person *Ptr[1000];
    int End = 999;
    int Tail = 999;
    int Choice = 0;
    int SubChoice = 0;
    //Initialize the pointers with NULL
    for(int i = 0; i < 1000; ++i)
    {
        Ptr[i] = NULL;
    }
    //Main loop
    while(Choice != 3)
    {
        system("cls");
        MainMenu(Choice);
        switch(Choice)
        {
            case 1:
            {
                SubChoice = 0;
                while(SubChoice != 5)
                {
                    system("cls");
                    SubMenu(SubChoice);
                    system("cls");
                    switch(SubChoice)
                    {
                        case 1:
                        {
                            if(Tail < 0)
                            {
                                std::cout << "The array is full. Cannot enter more data." << std::endl;
                            }
                            else
                            {
                                std::string Name;
                                std::string CNICNumber;
                                InputPersonData(Name, CNICNumber, Ptr, Tail);
                                Ptr[Tail] = new Person(Name, CNICNumber);
                                Tail--;
                            }
                            break;
                        }
                        case 2:
                        {
                            if(Tail < 0)
                            {
                                std::cout << "The array is full. Cannot enter more data." << std::endl;
                            }
                            else
                            {
                                std::string Name;
                                std::string CNICNumber;
                                std::string EmployeID;
                                double Salary;
                                InputEmployeData(Name, CNICNumber, EmployeID, Salary, Ptr, Tail);
                                Ptr[Tail] = new Employe(EmployeID, Salary, Name, CNICNumber);
                                Tail--;
                            }
                            break;
                        }
                        case 3:
                        {
                            if(Tail < 0)
                            {
                                std::cout << "The array is full. Cannot enter more data." << std::endl;
                            }
                            else
                            {
                                std::string Name;
                                std::string CNICNumber;
                                std::string EmployeID;
                                double Salary;
                                std::string StudentID;
                                double CGPA;
                                InputTAData(Name, CNICNumber, StudentID, CGPA, EmployeID, Salary, Ptr, Tail);
                                Ptr[Tail] = new TeachingAssistant(EmployeID, Salary, StudentID, CGPA, Name, CNICNumber);
                                Tail--;
                            }
                            break;
                        }
                        case 4:
                        {
                            if(Tail < 0)
                            {
                                std::cout << "The array is full. Cannot enter more data." << std::endl;
                            }
                            else
                            {
                                std::string Name;
                                std::string CNICNumber;
                                std::string StudentID;
                                double CGPA;
                                InputStudentData(Name, CNICNumber, StudentID, CGPA, Ptr, Tail);
                                Ptr[Tail] = new Student(StudentID, CGPA, Name, CNICNumber);
                                Tail--;
                            }                       
                            break;
                        }
                    }
                }
                break;
            }
            case 2:
            {
                if(Tail == End)
                {
                    std::cout << "The array has no data." << std::endl;
                }
                else
                {
                    for(int i = End; i > Tail; --i)
                    {
                        Ptr[i]->Display();
                        std::cout << "--------------------" << std::endl;
                    }   
                }
                system("pause");
                break;
            }
        }
    }
    //Delete the array
    for(int i = Tail; i < 1000; ++i)
    {
        delete Ptr[i];
        Ptr[i] = NULL;
        Tail++;
    }
    return 0;
}

Person::Person()
{
    Name = "";
    CNICNumber = "";
}

Person::Person(std::string Name, std::string CNICNumber)
{
    this->Name = Name;
    this->CNICNumber = CNICNumber;
}

std::string Person::GetCNIC()
{
    return CNICNumber;
}

void Person::Display()
{
    std::cout << "Name: " << Name << std::endl;;
    std::cout << "CNIC Number: " << CNICNumber << std::endl;
}

Employe::Employe()
{
    EmployeID = "";
    Salary = 0;
}

Employe::Employe(std::string EmployeID, double Salary, std::string Name, std::string CNICNumber) : 
         Person(Name, CNICNumber)
{
    this->EmployeID = EmployeID;
    this->Salary = Salary;
}

std::string Employe::GetEmployeID()
{
    return EmployeID;
}

void Employe::Display()
{
    std::cout << "Name: " << Name << std::endl;;
    std::cout << "CNIC Number: " << CNICNumber << std::endl;
    std::cout << "Employe ID: " << EmployeID << std::endl;
    std::cout << "Salary: " << Salary << std::endl;
}

Student::Student()
{
    StudentID = "";
    CGPA = 0;
}

Student::Student(std::string StudentID, double CGPA, std::string Name, std::string CNICNumber) : 
         Person(Name, CNICNumber)
{
    this->StudentID = StudentID;
    this->CGPA = CGPA;
}

std::string Student::GetStudentID()
{
    return StudentID;
}

void Student::Display()
{
    std::cout << "Name: " << Name << std::endl;;
    std::cout << "CNIC Number: " << CNICNumber << std::endl;
    std::cout << "Student ID: " << StudentID << std::endl;
    std::cout << std::setprecision(4) <<"CGPA: " << CGPA << std::endl;
}

TeachingAssistant::TeachingAssistant()
{

}

TeachingAssistant::TeachingAssistant(std::string EmployeID, double Salary, std::string StudentID, double CGPA, 
                                     std::string Name, std::string CNICNumber) : 
                                     Employe(EmployeID, Salary, Name, CNICNumber), Student(StudentID, CGPA, Name, CNICNumber)
{
    
}

void TeachingAssistant::Display()
{
    std::cout << "Name: " << Name << std::endl;;
    std::cout << "CNIC Number: " << CNICNumber << std::endl;
    std::cout << "Employe ID: " << EmployeID << std::endl;
    std::cout << "Salary: " << Salary << std::endl;
    std::cout << "Student ID: " << StudentID << std::endl;
    std::cout << std::setprecision(4) << "CGPA: " << CGPA << std::endl;
}

void MainMenu(int &Choice)
{
    std::cout << "1. Add a record" << std::endl;
    std::cout << "2. Display the records" << std::endl;
    std::cout << "3. Exit" << std::endl;
    std::cout << "Option: ";
    std::cin >> Choice;
    ValidateInt(Choice);
    while(Choice < 1 || Choice > 3)
    {
        std::cout << "Wrong entry. Option: ";
        std::cin >> Choice;
        ValidateInt(Choice);
    }
}

void ValidateInt(int &Number)
{
    while(std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Wrong entery. Option: ";
        std::cin >> Number;
    }
}

void SubMenu(int & SubChoice)
{
    std::cout << "1. Add Person" << std::endl;
    std::cout << "2. Add Employe" << std::endl;
    std::cout << "3. Add Teaching Assistant" << std::endl;
    std::cout << "4. Add Student" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << "Option: ";
    std::cin >> SubChoice;
    ValidateInt(SubChoice);
    while(SubChoice < 1 || SubChoice > 5)
    {
        std::cout << "Wrong entry. Option: ";
        std::cin >> SubChoice;
        ValidateInt(SubChoice);
    } 
}

void InputPersonData(std::string &Name, std::string &CNICNumber, Person *Ptr[], int &Tail)
{
    std::cin.ignore();
    std::cout << "Enter name: ";
    getline(std::cin, Name);
    std::cout << "Enter CNIC Number: ";
    getline(std::cin, CNICNumber);
    while(!ValidateCNIC(CNICNumber, Ptr, Tail))
    {
        getline(std::cin, CNICNumber);
    }
}

void InputEmployeData(std::string &Name, std::string &CNICNumber, std::string &EmployeID, double &Salary, Person *Ptr[], int &Tail)
{
    InputPersonData(Name, CNICNumber, Ptr, Tail);
    std::cout << "Enter employe ID: ";
    getline(std::cin, EmployeID);
    while(!ValidateEmployeID(EmployeID, Ptr, Tail))
    {
        getline(std::cin, EmployeID);

    }
    std::cout << "Enter salary of the employe: ";
    std::cin >> Salary;
    ValidateDouble(Salary);
    while(Salary < 0)
    {
        std::cout << "Salary must be positive. Enter salary of the employe: ";
        std::cin >> Salary;
        ValidateDouble(Salary);
    }
}

bool ValidateCNIC(std::string &CNICNumber, Person *Ptr[], int &Tail)
{
    if(CNICNumber.length() != 13)
    {
        std::cout << "CNIC number must be of length 13. Enter CNIC number: ";
        return false;
    }
    for(int i = 0; i < 13; ++i)
    {
        if(CNICNumber[i] > 57 || CNICNumber[i] < 48)
        {
            std::cout << "CNIC can only have numbers. Enter CNIC number: ";
            return false;
        }   
    }
    if(Tail != 999)
    {
        for(int i = Tail + 1; i < 1000; ++i)
        {
            if(CNICNumber == Ptr[i]->GetCNIC())
            {
                std::cout << "CNIC alreay exits. Enter CNIC number: ";
                return false;
            }
        }
    }
    return true;
}

bool ValidateEmployeID(std::string &EmployeID, Person *Ptr[], int &Tail)
{
    for(int i = 0; i < EmployeID.length() - 1; ++i)
    {
        if(EmployeID[i] > 57 || EmployeID[i] < 48)
        {
            std::cout << "Employe ID can only have numbers. Enter Employe ID: ";
            return false;
        }   
    }
    if(Tail != 999)
    {
        for(int i = Tail + 1; i < 1000; ++i)
        {
            if(dynamic_cast<Employe*>(Ptr[i]))
            {
                if(dynamic_cast<Employe*>(Ptr[i])->GetEmployeID() == EmployeID)
                {
                    std::cout << "Employe ID already exits. Enter employe ID: ";
                    return false;
                }
            }
        }
    }
    return true;
}

void ValidateDouble(double &Number)
{
    while(std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Wrong entery. Enter again: ";
        std::cin >> Number;
    }
}

void InputStudentData(std::string &Name, std::string &CNICNumber, std::string &StudentID, double &CGPA, Person *Ptr[], int &Tail)
{
    InputPersonData(Name, CNICNumber, Ptr, Tail);
    std::cout << "Enter student ID: ";
    getline(std::cin, StudentID);
    while(!ValidateStudentID(StudentID, Ptr, Tail))
    {
        getline(std::cin, StudentID);
    }
    std::cout << "Enter CGPA: ";
    std::cin >> CGPA;
    ValidateDouble(CGPA);
    while(CGPA < 0.0 || CGPA > 4.0)
    {
        std::cout << "CGPA must be between 0 and 4. Enter CGPA: ";
        std::cin >> CGPA;
        ValidateDouble(CGPA);
    }
}

bool ValidateStudentID(std::string &StudentID, Person *Ptr[], int &Tail)
{
    if(StudentID.length() != 10)
    {
        std::cout << "Student ID must be of 10 length. Enter student ID: ";
        return false;
    }
    for(int i = 0; i < 10; ++i)
    {
        if(StudentID[i] > 57 || StudentID[i] < 48)
        {
            std::cout << "Student ID can only have number. Enter student ID: ";
            return false;
        }
    }
    if(Tail != 999)
    {
        for(int i = Tail + 1; i < 1000; ++i)
        {
            if(dynamic_cast<Student*>(Ptr[i]))
            {
                if(dynamic_cast<Student*>(Ptr[i])->GetStudentID() == StudentID)
                {
                    std::cout << StudentID << std::endl;
                    system("pause");
                    std::cout << "Student ID already exits. Enter student ID: ";
                    return false;
                }
            }
        }
    }
    return true;
}

void InputTAData(std::string &Name, std::string &CNICNumber, std::string &StudentID, double &CGPA, std::string &EmployeID, double &Salary,
                 Person *Ptr[], int &Tail)
{
    InputStudentData(Name, CNICNumber, StudentID, CGPA, Ptr, Tail);
    std::cin.ignore(1000, '\n');
    std::cout << "Enter employe ID: ";
    getline(std::cin, EmployeID);
    while(!ValidateEmployeID(EmployeID, Ptr, Tail))
    {
        getline(std::cin, EmployeID);
    }
    std::cout << "Enter salary of the employe: ";
    std::cin >> Salary;
    ValidateDouble(Salary);
    while(Salary < 0)
    {
        std::cout << "Salary must be positive. Enter salary of the employe: ";
        std::cin >> Salary;
        ValidateDouble(Salary);
    }
}

