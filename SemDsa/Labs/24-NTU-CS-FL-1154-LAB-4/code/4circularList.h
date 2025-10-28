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
        this->first = nullptr;
        this->last = nullptr;
    }
    void insertNode(int);
    void print();
    int josephus(int);
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
    } while (temp != first);

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
        last->setPrev(first);
        first->setPrev(last);
    }
    else
    {
        newNode->setNext(first);
        newNode->setPrev(last);
        first->setPrev(newNode);
        last->setNext(newNode);
        last = newNode;
    }
}
int circularList::josephus(int k)
{
    if (first == NULL || k <= 0)
    {
        return -1;
    }

    node *curr = first;
    node *prev = last;

    while (curr->getNext() != curr)
    {
        for (int i = 1; i < k; i++)
        {
            prev = curr;
            curr = curr->getNext();
        }

        prev->setNext(curr->getNext());
        curr->getNext()->setPrev(prev);

        if (curr == first)
            first = curr->getNext();

        if (curr == last)
            last = prev;

        delete curr;
        curr = prev->getNext();
    }

    return curr->getData();
}
#endif
