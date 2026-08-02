
#ifndef H_node
#define H_node
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
#endif
