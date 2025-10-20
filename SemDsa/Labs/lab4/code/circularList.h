#include <iostream>
using namespace std;
#ifndef H_circularList
#define H_circularList
#include "2doublyList.h"
#include "1node.h"
class circularList : public doublyLinkList
{
public:
    circularList() : doublyLinkList()
    {
        // this->first=last;
        this->first = nullptr;
        this->last = nullptr;
    }
    void insertNode(int);
    void print();
};
void circularList::print()
{
    if (first == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    node *temp = first;

    do
    {
        cout << temp->getData() << " ";
        temp = temp->getNext();
    } while (temp != first); // stop when we come back to head

    cout << endl;
}
void circularList::insertNode(int data)
{
    node *newNode = new node();
    newNode->setData(data);
    if (this->first == NULL)
    {
        first = newNode;
        last = newNode;
        last->setNext(first);
    }
    else
    {
        newNode->setNext(first);
        first->setPrev(newNode);
        last->setNext(newNode);
        last = newNode;
    }
}
#endif
