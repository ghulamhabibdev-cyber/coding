#include <iostream>
#ifndef H_Node
#define H_Node
using namespace std;
class node
{
private:
    int data;
    node *next;
    node *prev;

public:
    node()
    {
        data = 0;
        next = NULL;
        prev = nullptr;
    }
    void setData(int);
    void setNext(node*);
    void setPrev(node*);
    int getData();
    node * getNext();
    node * getPrev();
};
// implementing the node
void node::setData(int data)
{
    this->data=data;
}
void node::setNext(node * next)
{
    this->next=next;
}
void node::setPrev(node* prev)
{
    this->prev=prev;
}
int node::getData()
{
    return data;
}
node * node::getNext()
{
    return next;
}
node * node::getPrev()
{
    return prev;
}
#endif

// this is standard form to make header files
