#include <iostream>
using namespace std;
class node
{
    int data;
    node *next;

public:
    int getData();
    node *getNext();
    void setData(int data);
    void setNext(node *next);
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
    return this->data;
}
node *node::getNext()
{
    return next;
}
class LinkList
{
    node *first;

public:
    LinkList();
    void insertFirst(int data);
    void sortList();
    void print();
    void swap(int data, int data2);
    bool search(int data);
    void insertInsortedList(int data);
};
void LinkList::insertInsortedList(int data)
{
    sortList();
    node *prev;
    node *curr = first;
    node *newnode = new node();
    bool found = false;
    newnode->setData(data);
    if (first == NULL)
    {
        first = newnode;
    }
    else
    {
        if (data < first->getData())
        {
            newnode->setNext(first);
            first = newnode;
        }
        else
        {
            while (curr != NULL && !found)
            {
                if (curr->getData() >= data)
                {
                    found = true;
                }
                else
                {
                    prev = curr;
                    curr = curr->getNext();
                }
            }
            if (found)
            {
                prev->setNext(newnode);
                newnode->setNext(curr);
            }
        }
    }
}
void LinkList::swap(int data1, int data2)
{
    bool firstFound = search(data1);
    bool secondFound = search(data2);
    if (firstFound && secondFound)
    {
        node *temp = first;
        node *nexty = first->getNext();
        while (temp != NULL)
        {
            if (data1 == temp->getData())
            {
                break;
            }
            else
            {
                temp = temp->getNext();
            }
        }
        while (nexty != NULL)
        {
            if (data2 == nexty->getData())
            {
                break;
            }
            else
            {
                nexty = nexty->getNext();
            }
        }
        nexty->setData(data1);
        temp->setData(data2);
        return;
    }
    else
    {
        cout << "Data is Not present in list\n";
    }
}
bool LinkList::search(int data)
{
    if (first == NULL)
    {
        return false;
    }
    if (data == first->getData())
    {
        return true;
    }
    node *temp = first;
    bool found = false;
    while (temp != NULL && !found)
    {
        if (temp->getData() == data)
        {
            found = true;
        }
        else
        {
            temp = temp->getNext();
        }
    }
    return found;
}
void LinkList::sortList()
{
    if (first == NULL || first->getNext() == NULL)
    {
        return;
    }

    node *temp = this->first;
    while (temp != NULL)
    {
        node *prev = first;
        node *nexy = first->getNext();
        while (nexy != NULL)
        {
            if (prev->getData() > nexy->getData())
            {
                int temp = prev->getData();
                int nexyTemp = nexy->getData();
                nexy->setData(temp);
                prev->setData(nexyTemp);
                prev = nexy;
                nexy = nexy->getNext();
            }
            else
            {
                prev = nexy;
                nexy = nexy->getNext();
            }
        }
        temp = temp->getNext();
    }
}
LinkList::LinkList()
{
    this->first = NULL;
}
void LinkList::insertFirst(int data)
{
    node *temp = new node();
    temp->setData(data);
    if (this->first == NULL)
    {
        first = temp;
    }
    else
    {
        temp->setNext(this->first);
        first = temp;
    }
}
void LinkList::print()
{
    node *temp = first;
    while (temp != NULL)
    {
        cout << temp->getData() << " ";
        temp = temp->getNext();
    }
    cout << endl;
}
int main()
{
    LinkList listy;
    listy.insertFirst(10);
    listy.insertFirst(20);
    listy.insertFirst(30);
    listy.insertFirst(40);
    listy.insertFirst(50);

    listy.print();
    listy.sortList();
    listy.swap(10, 50);
    listy.print();
    listy.sortList();
    listy.print();
    listy.insertInsortedList(40);
    listy.print();

    return 0;
}
