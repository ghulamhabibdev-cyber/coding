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

class Queue
{
private:
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            next = nullptr;
        }
    };
    Node *getNode(int data)
    {
        return new Node(data);
    }
    int n;
    void increase()
    {
        n++;
    }
    void decrease()
    {
        if (n > 0)
        {
            n--;
        }
    }

public:
    Node *head;
    Node *tail;
    Queue()
    {
        head = NULL;
        tail = NULL;
        n = 0;
    }
    void enque(int data)
    {
        Node *newNode = getNode(data);
        if (head == nullptr)
        {
            head = tail = newNode;
            increase();
            return;
        }
        tail->next = newNode;
        tail = newNode;
        increase();
    }
    void dequeu()
    {
        if (head == NULL)
        {
            return;
        }
        Node *temp = head->next;
        Node *delNode = head;
        delete delNode;
        head = temp;
        decrease();
    }
    bool empty()
    {
        return n == 0;
    }
    int front()
    {
        if (head)
        {
            return head->data;
        }
        return -1;
    }
    int size()
    {
        return n;
    }
    void print()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
void print(int n)
{
    cout << n << endl;
}
int main()
{
    Queue q;
    q.enque(102938);
    q.enque(20);
    q.enque(322);
    q.enque(32);
    print(q.front());
    q.print();
    print(q.size());
    while (!q.empty())
    {
        print(q.front());
        q.dequeu();
    }

    return 0;
}