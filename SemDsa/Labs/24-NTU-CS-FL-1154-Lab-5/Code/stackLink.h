
#ifndef H_stack
#define H_stack
#include <iostream>
using namespace std;
class node
{
    int data;
    node *next;

public:
    node()
    {
        next = NULL;
        data = 0;
    }
    void setData(int data)
    {
        this->data = data;
    }
    void setNext(node *next)
    {
        this->next = next;
    }
    int getData()
    {
        return data;
    }
    node *getNext()
    {
        return next;
    }
};
class stack
{
private:
    node *topNode;
    int count;

public:
    stack();
    void push(int data);
    void pop();
    int top();
    int size();
    void display();
    bool isEmpty();
    bool isFull();
};
int stack::size()
{
    return count;
}
bool stack::isFull()
{
    return true;
}
bool stack::isEmpty()
{
    if(topNode==NULL)
    {
        return true;
    }
    return false;
}
void stack::display()
{
    node * temp=topNode;
    while(temp!=NULL)
    {
        cout<<temp->getData()<<" ";
        temp=temp->getNext();
    }
    cout<<endl;
}
int stack::top()
{
    if(topNode!=NULL)
    {
        return topNode->getData();
    }
    else{
        return -1;
    }
}
stack::stack()
{
    count = 0;
    topNode = NULL;
}
void stack::push(int data)
{
    node *newNode = new node();
    newNode->setData(data);
    if (topNode == NULL)
    {
        topNode = newNode;
        count++;
    }
    else
    {
        newNode->setNext(topNode);
        topNode = newNode;
        count++;
    }
}
void stack::pop()
{
    if (topNode != NULL)
    {
        node *temp;
        temp = topNode;
        topNode = topNode->getNext();
        delete temp;
        count--;
    }
    else{
        cout<<"Empty Stack \n";
    }
}
#endif
