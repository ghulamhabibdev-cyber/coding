#ifndef  H_queue
#define H_queue
#include <iostream>
#include "Node.h"
using namespace std;
class queque
{
    node * front;
    node * rear;
    int count;

public:
    queque();
    void enqueue(int);
    void dequeue();
    void printQueue();
    bool isEmpty();
    int getFront();
};
int queque::getFront()
{
    if(front!=NULL)
    {
        return front->getData();
    }
    return -1;
}
bool queque::isEmpty()
{
    return front==NULL;
}
void queque::printQueue()
{
    node * curr=front;
    while(curr!=NULL)
    {
        cout<<curr->getData()<<" ";
        curr=curr->getNext();
    }
    cout<<endl;
}
void queque::dequeue()
{
    if(front!=NULL)
    {
        node *temp=front;
        front=front->getNext();
        delete temp;
        count--;
    }
    else{
        cout<<"Empty queque\n";
    }
}
queque::queque()
{
    front=NULL;
    rear=NULL;
    count=0;
}
void queque::enqueue(int data)
{
    node *newNode=new node();
    newNode->setData(data);
    newNode->setNext(NULL);
    if(front==NULL)
    {
        front=newNode;
        rear=newNode;
        count++;
    }
    else{
        rear->setNext(newNode);
        rear=newNode;
        count++;
    }
}

#endif
