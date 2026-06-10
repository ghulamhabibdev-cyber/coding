#ifndef LinkList_H
#define LinkList_H

#include <string>
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data);
    Node();
};
Node::Node(int data)
{
    this->data = data;
    next = NULL;
}
Node::Node()
{
    this->next = NULL;
    data=0;
}
class LinkList
{
private:
    void incrementSize();
    void decrementSize();

protected:
    // member variables
public:
    // constructors
    Node *head;
    Node *tail;
    int size ;
    void addHead(int data);
    void addTail(int data);
    void addHead(Node *node);
    void addTail(Node *node);
    void printLinkList();
    void deleteHead();
    void printHead();
    void printTail();
    LinkList();
    int length();
};
int LinkList::length()
{
    return size;
}
void LinkList::incrementSize()
{
    this->size++;
}
void LinkList::addHead(int data)
{
    Node *node = new Node(data);
    if (head == NULL)
    {
        this->head = tail = node;
        incrementSize();
    }
    else
    {
        node->next = head;
        head = node;
        incrementSize();
    }
}
void LinkList::addTail(int data)
{
    Node *node = new Node(data);
    if (head == NULL)
    {
        this->head = tail = node;
        incrementSize();
    }
    else
    {
        tail->next = node;
        tail = node;
        incrementSize();
    }
}
void LinkList::printLinkList()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}
void LinkList::addHead(Node *node)
{
    if (head == NULL)
    {
        this->head = tail = node;
        incrementSize();
    }
    else
    {
        node->next = head;
        head = node;
        incrementSize();
    }
}
void LinkList::decrementSize()
{
    if (size != 0)
    {
        size--;
    }
}
void LinkList::deleteHead()
{
    if (this->head != NULL)
    {
        Node *temp = head;
        head = head->next;
        decrementSize();
        delete temp;
    }
}
void LinkList::addTail(Node *node)
{
    if (head == NULL)
    {
        this->head = tail = node;
        incrementSize();
    }
    else
    {
        this->tail->next = node;
        tail = node;
        incrementSize();
    }
}
void LinkList::printHead()
{
    if (this->head)
    {
        cout << head->data << endl;
    }
}
void LinkList::printTail()
{
    if (this->tail)
    {
        cout << tail->data << endl;
    }
}

LinkList::LinkList()
{
    
    size = 0;
    head=tail=NULL;
}

#endif // LinkList_H