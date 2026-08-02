#include <bits/stdc++.h>
#include<iostream>
#include<math.h>
#define  pi 3.1459
using namespace std;

class cylinderType
{
private:
    double height;
    double radius;

public:
    // Default + parameterized constructor
    cylinderType(double r = 0, double h = 0)
    {
        radius = r;
        height = h;
    }

    // Setters
    void setRadius(double r)
    {
        if (r > 0)
            radius = r;
        else
            cout << "Radius must be positive!" << endl;
    }

    void setHeight(double h)
    {
        if (h > 0)
            height = h;
        else
            cout << "Height must be positive!" << endl;
    }

    // Getters
    double getRadius() { return radius; }
    double getHeight() { return height; }

    // Volume of cylinder
    double getVolume()
    {
        return pi * radius * radius * height; // πr²h
    }

    // Curved Surface Area (CSA = 2πrh)
    double getCurvedSurfaceArea()
    {
        return 2 * pi * radius * height;
    }

    // Total Surface Area (TSA = 2πrh + 2πr²)
    double getSurfaceArea()
    {
        return 2 * pi * radius * height + 2 * pi * radius * radius;
    }

    // Print cylinder details
    void printDetails()
    {
        cout << "Cylinder Details:\n";
        cout << "Radius: " << radius << " units\n";
        cout << "Height: " << height << " units\n";
        cout << "Volume: " << getVolume() << " cubic units\n";
        cout << "Curved Surface Area: " << getCurvedSurfaceArea() << " square units\n";
        cout << "Total Surface Area: " << getSurfaceArea() << " square units\n";
    }
};

// ----------------- MAIN -----------------
int main()
{
    cylinderType c1;   // default cylinder
    c1.setRadius(3);   // set radius
    c1.setHeight(5);   // set height
    c1.printDetails(); // print all properties

    cout << "\nAnother Cylinder:\n";
    cylinderType c2(7, 10); // using constructor
    c2.printDetails();

    return 0;
}
