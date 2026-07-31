#include <iostream>
#include<math.h>
using namespace std;
#define pi 3.1459
class point
{
private:
    double xCordinate;
    double yCordinate;

public:
    point(double x = 0, double y = 0);
    void printCordinate();
    void setCordinate(double xCord, double yCord);
    double getXCordinates();
    double getYCordinate();
    bool operator==(point &p);
    bool operator!=(point &p);
    point operator=(point &p);
    void operator++();
    void operator--();
    void operator++(int);
    void operator--(int);
};

class circleType
{
    point x;
    point y;
    double radius;

public:
    circleType(point &x, point &y);
    double getArea();
    double getCircumference();

private:
    double calculateArea();
    double calculateCircumFerence();
    double calculateRadius();
};
circleType::circleType(point &p1, point &p2)
{
    this->x = p1;
    this->y=p2;
}
double circleType::getCircumference()
{
    return calculateCircumFerence();
}
double circleType::getArea()
{
    return calculateArea();
}
double circleType::calculateCircumFerence()
{
    double radius = calculateRadius();
    return (2*pi * radius);
}
double circleType::calculateArea()
{
    double radius = calculateRadius();
    return (pi * radius * radius);
}
double circleType::calculateRadius()
{
    return sqrt(pow(x.getXCordinates() - y.getXCordinates(), 2) +
                pow(x.getYCordinate() - y.getYCordinate(), 2));
}
point point::operator=(point &p)
{
    this->xCordinate=p.xCordinate;
    this->yCordinate=p.yCordinate;
    return *this;
}
void point::operator--()
{
    xCordinate--;
    yCordinate--;
}

// Prefix ++
void point::operator++()
{
    xCordinate++;
    yCordinate++;
}

// Postfix --
void point::operator--(int)
{
    xCordinate--;
    yCordinate--;
}

// Postfix ++
void point::operator++(int)
{
    xCordinate++;
    yCordinate++;
}
bool point::operator!=(point &p)
{
    !(*this == p);
}
bool point::operator==(point &p)
{
    if (this->xCordinate == p.xCordinate && this->yCordinate == p.yCordinate)
    {
        return true;
    }
    return false;
}
double point::getYCordinate()
{
    return yCordinate;
}
double point::getXCordinates()
{
    return xCordinate;
}
void point::setCordinate(double xCord, double yCord)
{
    this->xCordinate = xCord;
    this->yCordinate = yCord;
}
void point::printCordinate()
{
    cout << "X-Axis : " << xCordinate << endl;
    cout << "Y-Axis : " << yCordinate << endl;
}
point::point(double xCord, double yCord)
{
    this->xCordinate = xCord;
    this->yCordinate = yCord;
}
int main()
{
    point p(10, 10);
    point p1(30, 20);
    bool yes = p == p1;
    cout
        << yes << endl;
    p++;
    p.printCordinate();
    circleType cir(p, p1);
    cout<<"Area : " <<cir.getArea();

    // cout << "helo\n";
}
