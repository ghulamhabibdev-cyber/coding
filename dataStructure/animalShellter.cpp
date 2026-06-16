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
    Animal(string name, int age, string type)
    {
        this->age = age;
        this->name = name;
        this->type;
    }
    string getName()
    {
        return name;
    }
    string getType()
    {
        return type;
    }
    int getAge()
    {
        return age;
    }
};
class Dog : public Animal
{
public:
    Dog(string name, int age, string type) : Animal(name, age, type)
    {
    }
};
class Cat : public Animal
{
public:
    Cat(string name, int age, string type) : Animal(name, age, type)
    {
    }
};
class doptionQueue
{
private:
    class Node
    {
        Animal *ane;
        Node *next;

    public:
        Node(string name, int age, string type)
        {
            if (type == "dog")
            {
                Animal *dog = new Dog(name, age, type);
                this->ane = dog;
            }
            else
            {
                Animal *cat = new Cat(name, age, type);
                this->ane = cat;
            }
            this->next = NULL;
        }
    };
    Node *getNode(string name, int age, string type)
    {
        return
    }
} int main()
{

    return 0;
}