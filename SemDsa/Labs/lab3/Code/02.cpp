#include <bits/stdc++.h>
using namespace std;
// class defination
class Node
{
private:
    int data;
    Node *next;

public:
    int getData();
    Node *getNext();
    void setData(int);
    void setNext(Node *);
};
// implementing the class Node method
// setter
void Node::setData(int data)
{
    this->data = data;
}
void Node::setNext(Node *next)
{
    this->next = next;
}
// getter
int Node::getData()
{
    return this->data;
}
Node *Node::getNext()
{
    return this->next;
}
class List
{
private:
    Node *currentLocation;

public:
    List();
    void Print();
    void Insert(int);
    void Delete(int);
    void addbetween(int);
};
List::List()
{
    this->currentLocation = NULL;
}
void List::addbetween(int data)
{
    Node *temp = new Node();
    temp->setData(data);
    if (currentLocation == NULL)
    {
        currentLocation = temp;
        return;
    }
    if (currentLocation->getNext() == NULL)
    {
        currentLocation->setNext(temp);
    }
    else
    {
        Node *nexy = currentLocation->getNext();
        temp->setNext(nexy);
        currentLocation->setNext(temp);
    }
}
void List::Insert(int data)
{
    Node *temp = new Node();
    temp->setData(data);

    if (this->currentLocation == NULL)
    {
        currentLocation = temp;
    }
    else
    {
        temp->setNext(this->currentLocation);
        currentLocation = temp;
    }
}
void List::Print()
{
    Node *temp = currentLocation;
    while (temp != NULL)
    {
        cout << temp->getData() << " ";
        temp = temp->getNext();
    }
    cout << endl;
}
void List::Delete(int data)
{
    Node *curr = currentLocation;
    Node *prev;
    bool found = false;
    if (currentLocation->getData() == data)
    {
        Node *temp = currentLocation;
        currentLocation = currentLocation->getNext();
        return;
    }
    else
    {
        while (curr != NULL && !found)
        {
            if (curr->getData() == data)
            {
                found = true;
            }
            else
            {
                prev = curr;
                curr = curr->getNext();
            }
        }
        if (curr == NULL)
        {
            cout << "Not Presnt In List \n";
        }
        else
        {
            if (found)
            {
                prev->setNext(curr->getNext());
                delete curr;
            }
        }
    }
}

int main()
{
    cout << "=================Insertion method and Deletion Method===================\n";
    List l;
    l.Insert(30);
    l.Insert(31);
    l.Insert(32);
    l.Insert(33);
    l.Insert(34);
    l.Insert(35);
    l.Insert(36);
    l.Insert(37);
    l.Insert(39);
    l.Print();
    l.Delete(39);
    l.addbetween(123);
    l.addbetween(1320);
    l.Print();
    return 0;
}
