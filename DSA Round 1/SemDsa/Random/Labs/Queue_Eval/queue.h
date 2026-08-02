#ifndef H_queue
#define H -queue
#include <iostream>
#include "node.h"
using namespace std;
class queue
{
private:
    node *front;
    node *rear;
    int count = 0;

public:
    queue()
    {
        this->front = NULL;
        this->rear = NULL;
        this->count = 0;
    }
    void enqueue(int tokenNo, string name, string service)
    {
        node *newNode = new node();
        newNode->setToken(tokenNo);
        newNode->setName(name);
        newNode->setService(service);
        newNode->setNext(NULL);
        if (front == NULL)
        {
            this->front = newNode;
            this->rear = newNode;
        }
        else
        {
            rear->setNext(newNode);
            rear = newNode;
        }
    }
    void diplayQueue()
    {
        node *curr = front;
        int i = 1;
        while (curr != NULL)
        {
            cout << "[" << i << "] " << curr->getTokenNO() << " - " << curr->getName() << " - " << curr->getServic() << endl;
            curr = curr->getNext();
            i++;
        }
    }
    void dequeue()
    {
        node *temp = front;
        front = front->getNext();
        delete temp;
    }
};
#endif
