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
    List l;
    cout << "Inserting the Data i List \n";
    l.Insert(30);
    l.Insert(31);
    l.Insert(32);
    l.Insert(33);
    l.Insert(34);
    l.Insert(35);
    l.Insert(36);
    l.Insert(37);
    l.Insert(39);
    l.Insert(40);
    l.Insert(41);
    l.Insert(42);
    l.Insert(43);
    l.Insert(44);
    l.Insert(45);

    cout << "Printing the Data \n";
    l.Print();
    cout << "Deleting the Data \n";
    l.Delete(32);
    l.Delete(33);
    l.Delete(34);
    l.Delete(35);
    l.Delete(36);
    l.Delete(37);
    cout<<"Printing After the Deletion \n";
    l.Print();
    cout<<"Inseting Between \n";
    l.addbetween(1220);
    l.addbetween(1321);
    l.addbetween(1322);
    l.addbetween(1323);
    l.addbetween(1324);
    cout<<"Printing the List after the Insertion \n";
    l.Print();

    return 0;
}
