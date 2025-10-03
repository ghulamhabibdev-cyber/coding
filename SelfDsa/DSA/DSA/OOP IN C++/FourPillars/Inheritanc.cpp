#include <bits/stdc++.h>
using namespace std;
class human
{
protected:
    string name;
    int age;
    double height;

public:
    human(string name, int age, double height)
    {
        this->name = name;
        this->age = age;
        this->height = height;
    }
    string getName()
    {
        return this->name;
    }
    int getAge()
    {
        return age;
    }
    double getHeight()
    {
        return height;
    }
    void printInformation()
    {
        cout << "Name   : " << name << endl;
        cout << "age    : " << age << endl;
        cout << "Height : " << height << endl;
    }
};
class male : public human
{
    string color;

public:
    male(string name, int age, double height, string color) : human(name, age, height)
    {
        this->color = color;
    }

    void printInformation()
    {
        // height++;
        // cout<<"Incree "<<(human::height)<<endl;
        human::printInformation();
        cout << "Color : " << color << endl;
        cout<<"New height : "<<height<<endl;
    }
};
int main()
{
    male m("Ali", 20, 5.4, "Glad");
    
    m.printInformation();
    return 0;
}
