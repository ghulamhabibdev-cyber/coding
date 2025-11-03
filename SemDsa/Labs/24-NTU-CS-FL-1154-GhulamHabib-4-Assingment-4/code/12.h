#ifndef H_queue
#define H_queue
#include<stack>
#include <iostream>
using namespace std;
class node
{
private:
    int data;
    node *next;

public:
    void setData(int data);
    int getData();
    void setNext(node *);
    node *getNext();
};
void node::setData(int data)
{
    this->data = data;
}
void node::setNext(node *next)
{
    this->next = next;
}
int node::getData()
{
    return data;
}
node *node::getNext()
{
    return next;
}
class linkyQueue
{
private:
    node *front;
    node *rear;
    int count;

public:
    linkyQueue();
    void enqueue(int);
    void dequeue();
    void print();
    int queueFront();
    int queueBack();
    bool isFull();
    bool isEmpty();
    void reverseQueue();
    int size();
};
//  enqueue and dequeue
void linkyQueue::reverseQueue()
{
    stack<int>st;
    node * curr=front;
    while(curr!=NULL)
    {
        st.push(curr->getData());
        curr=curr->getNext();
    }
    curr=front;
    while (!st.empty())
    {
        curr->setData(st.top());
        curr=curr->getNext();
        st.pop();

    }
    cout<<endl;
}
bool linkyQueue::isFull()
{
    return false;
}
bool linkyQueue::isEmpty()
{
    return front==NULL;
}
int linkyQueue::queueBack()
{
    if(rear!=NULL)
    {
        return rear->getData();
    }
    return -1;
}
int linkyQueue::queueFront()
{
    if(front!=NULL)
    {
        return front->getData();
    }
    return -1;
}
void linkyQueue::print()
{
    node* curr=front;
    while(curr!=NULL)
    {
        cout<<curr->getData()<<" ";
        curr=curr->getNext();
    }
    cout<<endl;
}
int linkyQueue::size()
{
    if(count<=0)
    {
        count=0;
    }
    return count;
}
void linkyQueue::dequeue()
{
    node * temp=front;
    front=front->getNext();
    if(front==NULL)
    {
        front=NULL;
        rear=NULL;
        count=0;
    }
    delete temp;
    count--;
}
void linkyQueue::enqueue(int data)
{
    node * newNode=new node();
    newNode->setData(data);
    newNode->setNext(NULL);
    if(front==NULL)
    {
        front=newNode;
        rear=newNode;
    }
    else{
        rear->setNext(newNode);
        rear=newNode;
    }
     count++;
}
linkyQueue::linkyQueue()
{
    front = NULL;
    rear = NULL;
    count = 0;
}
#endif
