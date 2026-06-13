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

class A
{
};
class Node
{
public:
    Node *next;
    int data;
    Node(int data)
    {
        this->next = NULL;
        this->data = data;
    }
};
class circularList
{
    Node *head;
    Node *tail;
    int n = 0;

public:
    circularList(int data)
    {
        head = tail = getNode(data);
        tail->next = head;
        n++;
    }
    circularList()
    {
        head = tail = NULL;
        n = 0;
    }
    void makeCirular()
    {
        if (head != nullptr)
        {
            tail->next = head;
        }
    }
    bool isHeadNull()
    {
        return head == NULL;
    }
    void NullHeadAdd(int data)
    {
        if (head == NULL)
        {
            head = tail = getNode(data);
            makeCirular();
            n++;
        }
    }
    void addNodeTail(int data)
    {
        if (isHeadNull())
        {

            NullHeadAdd(data);
            return;
        }
        Node *newNode = getNode(data);
        newNode->next = head;
        tail->next = newNode;
        tail = newNode;
        n++;
    }
    void addHead(int data)
    {

        if (isHeadNull())
        {
            NullHeadAdd(data);
            return;
        }
        Node *newNode = getNode(data);
        newNode->next = head;
        head = newNode;
        n++;
        tail->next = head;
    }
    Node *getNode(int data)
    {
        return new Node(data);
    }
    void print()
    {
        Node *temp = head;
        int len = n;
        while (len)
        {
            cout << temp->data << " ";
            len--;
            temp = temp->next;
        }
    }
};
int main()
{
    circularList list;
    for (int i = 0; i < 5; i++)
    {
        list.addNodeTail(i);
    }
    list.print();

    return 0;
}