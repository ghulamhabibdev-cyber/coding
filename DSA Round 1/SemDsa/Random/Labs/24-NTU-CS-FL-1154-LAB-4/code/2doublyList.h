#include <iostream>
#include "1node.h"
#ifndef H_DoublyList
#define H_DoublyList
using namespace std;
class doublyLinkList
{
protected:
    node *first;
    node *last;
    int count;

public:
    doublyLinkList();
    void insertNode(int);
    void deleteNode(int);
    bool search(int);
    void print();
};
void doublyLinkList::deleteNode(int data)
{
    node * prev;
    bool nodyFound = false;
    bool found = search(data);
    if(!found)
    {
        cout<<"Not in List\n";
        return;
    }
    if (first == NULL)
    {
        cout << "Empty list\n";
        return;
    }
    node * curr=first;
    while(curr!=NULL && curr->getData()!=data)
    {
        curr=curr->getNext();
    }
    if(curr==first)
    {
        first=first->getNext();
        if(first!=NULL)
        {
            first->setPrev(NULL);
        }

    }
    else{
        prev=curr->getPrev();
        prev->setNext(curr->getNext());
        if(curr->getNext()!=NULL)
        {
            curr->getNext()->setPrev(prev);
        }

    }
    if(curr==last)
    {
        last=curr->getPrev();
    }
    delete curr;
    count--;
}
bool doublyLinkList::search(int data)
{
    bool found = false;

    if (first == NULL)
    {
        return false;
    }
    if (first->getData() == data)
    {
        return true;
    }
    else
    {
        node *temp = first;
        found = false;
        while (temp != NULL && !found)
        {
            if (temp->getData() == data)
            {
                found = true;
                break;
            }
            else
            {
                temp = temp->getNext();
            }
        }
        if (found)
        {
            found = temp->getData() == data;
        }
        return found;
    }
}
doublyLinkList::doublyLinkList()
{
    this->first = NULL;
    this->last = NULL;
    this->count = 0;
}
void doublyLinkList::insertNode(int data)
{
    node *newNode = new node();
    newNode->setData(data);
    if (first == NULL)
    {
        this->first = newNode;
        this->last = newNode;
        count++;
    }
    else
    {
        last->setNext(newNode);
        newNode->setPrev(last);
        last = newNode;
        count++;
    }
}
void doublyLinkList::print()
{
    node *temp = first;
    while (temp != NULL)
    {
        cout << temp->getData() << " ";
        temp = temp->getNext();
    }
    cout << endl;
}

#endif


