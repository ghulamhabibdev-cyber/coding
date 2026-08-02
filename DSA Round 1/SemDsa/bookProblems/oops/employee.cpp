#include<bits/stdc++.h>
#include "hello.h"
#include "../HeaderFiles/test.h"
using namespace std;
class  PartTimeEmployee:public person
{

    private:
    double rate;
    int noOfHours;
    public:
    PartTimeEmployee(string name,int age,double rate,int noOfHours);
    double calculateSalry();
    void setRate(double rate);
    void setNoHours(int noOfHours);
    void setName(string name);
    void print();
};
PartTimeEmployee::PartTimeEmployee(string name,int  age,double rate,int noOfHours):person(name,age)
{
    this->rate=rate;
    this->noOfHours=noOfHours;
}
double PartTimeEmployee::calculateSalry()
{
    return rate*noOfHours;
}
void PartTimeEmployee::setRate(double rate)
{
    this->rate=rate;
}
void PartTimeEmployee::setNoHours(int noOfHours)
{
    this->noOfHours=noOfHours;
}
void PartTimeEmployee::setName(string name)
{
    person::setName(name);
}
void PartTimeEmployee::print()
{
    person::print();
    cout<<"Salary : "<<calculateSalry()<<endl;
}
int main()
{
    // PartTimeEmployee ali("Ali",20,10.4,100);
    // ali.print();
    print(4);
    return 0;
}
