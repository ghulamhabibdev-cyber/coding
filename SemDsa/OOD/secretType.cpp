#include<bits/stdc++.h>
using namespace std;
class  secretType
{
    private:
    int age;
    string name;
    int weight;
    double height;
    public:
        void setName(string name);
        void setAge(int age);
        void setWeight(int weigt);
        void setHeight(double height);
        string getName();
        int getAge();
        int getWeight();
        double getHeight();
        secretType();
};
void secretType::setName(string name)
{
    this->name=name;
}
void secretType::setAge(int age)
{
    this->age=age;
}
void secretType::setWeight(int weight)
{
    this->weight=weight;
}
void secretType::setHeight(double height)
{
    this->height=height;
}
string secretType::getName()
{
    return name;
}
int secretType::getAge()
{
    return  age;
}
int secretType::getWeight()
{
    return weight;
}
double secretType::getHeight()
{
    return height;
}

int main()
{



    return 0;
}
