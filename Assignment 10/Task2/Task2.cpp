#include <iostream>
#include <cmath>
#include <ctime>

class Shape
{
    protected:
        int NumberOfParameters;  
    public:
        /*If we donot make virtual destructor the destructor for the derived classes will not be called
        and only the destructor for base class will be called. This can be demonstrated by uncommenting 
        the non-virtual destructor and commenting the virtual distructor. This will result in memory
        leak as the dynamic array won't be deleted. If we make the virtual destructor for the base class 
        then the destructor for the derived class will be called and then the destructor for the base call 
        will be called.*/
        //~Shape();
        virtual ~Shape();
        virtual void Area() = 0;
        virtual void Perimeter() = 0;
};

class Circle : public Shape
{
    public:
        int *Parameters[3];
        Circle(int x, int y, int Radius);
        ~Circle();
        void Area();
        void Perimeter();
};

class Triangle : public Shape
{
    public:
        int *Parameters[6];
        Triangle(int x1, int y1, int x2, int y2, int x3, int y3);
        ~Triangle();
        void Area();
        void Perimeter();
        double Distance(int x1, int y1, int x2, int y2);
};

class Square : public Shape
{
    public:
        int *Parameters[4];
        Square(int x1, int y1, int x2, int y2);
        ~Square();
        void Area();
        void Perimeter();
        double Distance(int x1, int y1, int x2, int y2);
};

int main()
{
    Shape *Ptr[1000];
    srand(time(NULL));
    for(int i = 0; i < 1000; ++i)
    {
        int Check = rand()%3;
        if(Check == 0)
        {
            Ptr[i] = new Circle(rand()%10+1, rand()%10+1, rand()%20+1);
        }
        else if(Check == 1)
        {
            Ptr[i] = new Square(rand()%20+1, rand()%20+1, rand()%20+1, rand()%20+1);
        }
        else
        {
            int x1 = rand()%10+1;
            int y1 = rand()%10+1;
            int Difference = rand()%10+1;
            Ptr[i] = new Triangle(x1, y1, x1, y1 + Difference, x1 + Difference, y1);
        }
    }
    std::cout << "RANDOM OBJECT AREA AND PERIMETER TO DEMONSTRATE POLYMORPHISM:" << std::endl;
    for(int i = 0; i < 10; ++i)
    {
        int RandomOutput = rand()%999;
        Ptr[RandomOutput]->Area();
        Ptr[RandomOutput]->Perimeter();
    }
    std::cout << std::endl << "THE DESTRUCTOR WILL OUTPUT WHICH DESTRUCTOR WILL BE CALLED:" << std::endl;
    for(int i = 0; i < 1000; ++i)
    {
        delete Ptr[i];
    }
    return 0;   
}

Shape::~Shape()
{
    std::cout << "Distructor of base class 'Shape' is called" << std::endl;
}

Circle::Circle(int x, int y, int Radius)
{
    NumberOfParameters = 3;
    for(int i = 0; i < NumberOfParameters; ++i)
    {
        Parameters[i] = new int;    
    }
    *Parameters[0] = x;
    *Parameters[1] = y;
    *Parameters[2] = Radius;
}

Circle::~Circle()
{
    for(int i = 0; i < NumberOfParameters; ++i)
    {
        delete Parameters[i];
    }
    std::cout << "Distructor of derived class 'Circle' is called" << std::endl;
}

void Circle::Area()
{
    const double PI = 2*acos(0.0);
    std::cout << "Shape: Circle" << std::endl;
    std::cout << "Area:" << PI * (*Parameters[2]) * (*Parameters[2]) << std::endl;
}

void Circle::Perimeter()
{
    const double PI = 2*acos(0.0);
    std::cout << "Shape: Circle" << std::endl;
    std::cout << "Parimeter: " << 2 * PI * (*Parameters[2]) << std::endl;
}

double Triangle::Distance(int x1, int y1, int x2, int y2)
{
    return sqrt(pow((y2 - y1), 2) + pow((x2 - x1), 2));
}

Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3)
{
    NumberOfParameters = 6;
    for(int i = 0; i < NumberOfParameters; ++i)
    {
        Parameters[i] = new int;
    }
    *Parameters[0] = x1;
    *Parameters[1] = y1;
    *Parameters[2] = x2;
    *Parameters[3] = y2;
    *Parameters[4] = x3;
    *Parameters[5] = y3;
}

Triangle::~Triangle()
{
    for(int i = 0; i < NumberOfParameters; ++i)
    {
        delete Parameters[i];
    }
    std::cout << "Distructor of derived class 'Triangle' is called" << std::endl;
}

void Triangle::Area()
{
    std::cout << "Shape: Triangle" << std::endl;
    std::cout << "Area: ";
    double Length1 = Distance(*Parameters[0], *Parameters[1], *Parameters[2], *Parameters[3]);
    double Length2 = Distance(*Parameters[0], *Parameters[1], *Parameters[4], *Parameters[5]);
    double Length3 = Distance(*Parameters[2], *Parameters[3], *Parameters[4], *Parameters[5]);
    if(Length1 == Length2)
    {
        std::cout << (Length1 * Length2)/2 << std::endl;
    }
    else if(Length1 == Length3)
    {
        std::cout << (Length1 * Length3)/2 << std::endl;
    }
    else
    {
        std::cout << (Length2 * Length3)/2 << std::endl;
    }
}

void Triangle::Perimeter()
{
    std::cout << "Shape: Triangle" << std::endl;
    std::cout << "Perimeter: ";
    double Length1 = Distance(*Parameters[0], *Parameters[1], *Parameters[2], *Parameters[3]);
    double Length2 = Distance(*Parameters[0], *Parameters[1], *Parameters[4], *Parameters[5]);
    double Length3 = Distance(*Parameters[2], *Parameters[3], *Parameters[4], *Parameters[5]);
    std::cout << Length1 + Length2 + Length3 << std::endl;
}

double Square::Distance(int x1, int y1, int x2, int y2)
{
    return sqrt(pow((y2 - y1), 2) + pow((x2 - x1), 2));
}

Square::Square(int x1, int y1, int x2, int y2)
{
    NumberOfParameters = 4;
    for(int i = 0; i < NumberOfParameters; ++i)
    {
        Parameters[i] = new int;
    }
    *Parameters[0] = x1;
    *Parameters[1] = y1;
    *Parameters[2] = x2;
    *Parameters[3] = y2;
}

Square::~Square()
{
    for(int i = 0; i < NumberOfParameters; ++i)
    {
        delete Parameters[i];
    }
    std::cout << "Distructor of derived class 'Square' is called" << std::endl;
}

void Square::Area()
{
    std::cout << "Shape: Square" << std::endl;
    std::cout << "Area: ";
    double Diagonal = Distance(*Parameters[0], *Parameters[1], *Parameters[2], *Parameters[3]);
    double Length = sqrt(pow(Diagonal, 2)/2);
    std::cout << Length * Length << std::endl;
}

void Square::Perimeter()
{
    std::cout << "Shape: Square" << std::endl;
    std::cout << "Perimeter: ";
    double Diagonal = Distance(*Parameters[0], *Parameters[1], *Parameters[2], *Parameters[3]);
    double Length = sqrt(pow(Diagonal, 2)/2);
    std::cout << 4 * Length << std::endl;
}

