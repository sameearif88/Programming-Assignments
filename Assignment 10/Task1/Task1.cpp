#include <iostream>
#include <cmath>
#include <ctime>

class Shape
{
    public:
        virtual void Area() = 0;
    protected:
        int parameter;
};

class Circle : public Shape
{
    public:
        Circle(int parameter);
        void Area() override;
};

class Triangle : public Shape
{
    public:
        Triangle(int parameter);
        void Area() override;
};

class Square : public Shape
{
    public:
        Square(int parameter);
        void Area() override;
};

int main()
{
    Shape *Ptr[1000];
    srand(time(0));
    for(int i = 0; i < 1000; ++i)
    {
        if((rand()%3) == 0)
        {
            Ptr[i] = new Circle(rand()%20+1);
        }
        if((rand()%3) == 1)
        {
            Ptr[i] = new Square(rand()%20+1);
        }
        else
        {
            Ptr[i] = new Triangle(rand()%10+1);
        }
    }
    for(int i = 0; i < 1000; ++i)
    {
        delete Ptr[i];
    }
    return 0;
}

Circle::Circle(int parameter)
{
    this->parameter = parameter;
}

Triangle::Triangle(int parameter)
{
    this->parameter = parameter;
}

Square::Square(int parameter)
{
    this->parameter = parameter;
}

void Circle::Area()
{
    const double PI = 2*acos(0.0);
    std::cout << "Shape: " << "Circle" << std::endl;
    std::cout << "Parameter: " << parameter << std::endl;
    std::cout << "Area: " << PI * parameter * parameter;
}

void Triangle::Area()
{
    std::cout << "Shape: " << "Triangle" << std::endl;
    std::cout << "Parameter: " << parameter << std::endl;
    std::cout << "Area: " << (parameter * parameter)/2;
}

void Square::Area()
{
    std::cout << "Shape: " << "Square" << std::endl;
    std::cout << "Parameter: " << parameter << std::endl;
    std::cout << "Area: " << parameter * parameter;
}

