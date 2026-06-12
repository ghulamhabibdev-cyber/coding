#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits>
#include <list>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
class LinkList
{
private:
    Node *head;
    Node *tail;
    int n;

    LinkList()
    {
        this->head = tail = NULL;
    }
    LinkList(int data)
    {
        addHead(data);
    }
    LinkList(LinkList *list)
    {
        this->head = list->getHead();
        this->tail = list->getTail();
        this->n = length();
    }
    int length()
    {
        return n;
    }
    Node *getTail()
    {
        return tail;
    }
    Node *getHead()
    {
        return head;
    }
    Node *getNode(int data)
    {
        return new Node(data);
    }
    void increaseSize()
    {
        n++;
    }
    void decreaseSize()
    {
        if (n != 0)
        {
            n--;
        }
    }
    void addHead(int data)
    {
        if (head == NULL)
        {
            this->head = tail = getNode(data);
            increaseSize();
            return;
        }
        Node *node = getNode(data);
        node->next = head;
        head = node;
        increaseSize();
    }
    void addHead(Node *node)
    {
        if (head == NULL)
        {
            this->head = tail = node;
            increaseSize();
            return;
        }
        node->next = head;
        head = node;
        increaseSize();
    }
    void addTail(int data)
    {
        if (head == NULL)
        {
            this->head = tail = getNode(data);
            increaseSize();
            return;
        }
        Node *node = getNode(data);
        this->tail->next = node;
        tail = node;
        increaseSize();
    }
    void addTail(Node *node)
    {
        if (head == NULL)
        {
            this->head = tail = node;
            increaseSize();
            return;
        }
        this->tail->next = node;
        tail = node;
        increaseSize();
    }
    void DelNode(Node *&node)
    {
        delete node;
    }
    void addAtPos(int data,int pos)
    {
       
        
    }
    void addAtPos(Node * node,int pos)
    {
        
    }
    void clear()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            Node *del = temp;
            DelNode(del);
            temp = temp->next;
        }
        this->n = 0;
    }
};
int main()
{

    return 0;
}