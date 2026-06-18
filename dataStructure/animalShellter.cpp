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
class AdoptionQueue
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
        return new Node(name, age, type);
    };
    Node * head;
    Node * tail;
    int n;
    void increase()
    {
        n++;
    }
    void decrease()
    {
        if(n>0)
        {
            n--;
        }
    }
    public:
    AdoptionQueue()
    {
        head=tail=NULL;
        n=0;
    }
    void enque(string name,int age,string type)
    {
        Node * newNode=getNode(name,age,type);
        if(head==NULL)
        {
            head=tail=newNode;
        }

    }
};
int main()
{

    return 0;
}