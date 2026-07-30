#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits>
#include <list>
using namespace std;

class Animal
{
protected:
    string type;
    int age;
    string name;

public:
    Animal(string type, int age, string name)
    {
        this->type = type;
        this->age = age;
        this->name = name;
    }
    string getType()
    {
        return type;
    }
    int getAge()
    {
        return age;
    }
    string getName()
    {
        return name;
    }
};
class Dog:public Animal
{
    public:
    Dog(string type,int age,string name):Animal(type,age,name)
    {

    }
};
class Cat : public Animal
{
public:
    Dog(string type, int age, string name) : Animal(type, age, name)
    {
    }
};
class AnimalShelter
{
    private:
    class Node{
        Node * next;
        Animal data;
    }
    
}
int main()
{

    return 0;
}