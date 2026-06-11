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

public:
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
    void addAtPos(int data, int pos)
    {
        if (pos < 1)
        {
            addHead(data);
            return;
        }
        else if (pos >= length())
        {
            addTail(data);
            return;
        }
        Node *temp = head;
        int count = 0;
        while (count < pos - 1)
        {
            count++;
            temp = temp->next;
        }
        Node *node = getNode(data);
        node->next = temp->next;
        temp->next = node;
        increaseSize();
    }
    void addAtPos(Node *node, int pos)
    {
        if (node == nullptr)
            return;
        if (pos < 1)
        {
            addHead(node);
            return;
        }
        else if (pos >= length())
        {
            addTail(node);
            return;
        }
        Node *temp = head;
        int count = 0;
        while (count < pos - 1 && temp != nullptr)
        {
            count++;
            temp = temp->next;
        }
        node->next = temp->next;
        temp->next = node;
        increaseSize();
    }
    void clear()
    {
        while (head != nullptr)
        {
            Node *del = head;
            head = head->next;
            delete del;
        }
        this->n = 0;
    }
    void printList()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main()
{

    LinkList list;
    for (int i = 0; i < 5; i++)
    {
        list.addTail(i);
    }
    for (int i = 6; i < 10; i++)
    {
        list.addTail(i);
    }
    list.printList();
    list.clear();
    list.printList();
    for (int i = 10; i < 15; i++)
    {
        Node *node = list.getNode(i);
        list.addTail(node);
    }
    for (int i = 15; i < 20; i++)
    {
        Node *node = list.getNode(i);
        list.addHead(node);
    }
    for (int i = 2; i < 10; i++)
    {
        list.addAtPos(90009, i);
    }
    for (int i = 3; i < 10; i++)
    {
        Node *node = list.getNode(1111);
        list.addAtPos(node, i);
    }
    list.printList();
    return 0;
}