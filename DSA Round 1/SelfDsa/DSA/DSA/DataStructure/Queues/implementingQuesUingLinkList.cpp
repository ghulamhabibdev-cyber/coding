#include <bits/stdc++.h>
using namespace std;
class ListNode
{
public:
    int data;
    ListNode *next;
    ListNode(int data)
    {
        this->data = data;
        next = NULL;
    }
    ~ListNode()
    {
    }
};
void insertAtHead(ListNode *&head, ListNode *&tail, int data)
{

    ListNode *newNode = new ListNode(data);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}
void printList(ListNode *head)
{
    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void insertAtTail(ListNode *&tail, ListNode *&head, int data)
{
    ListNode *newNode = new ListNode(data);
    if (tail == NULL)
    {
        tail = newNode;
        head = newNode;
        return;
    }
    tail->next = newNode;
    tail = tail->next;
}
void insertAtPos(ListNode *&head, ListNode *&Tail, int pos, int data)
{
    if (pos == 1)
    {
        insertAtHead(head, Tail, data);
        return;
    }
    int cnt = 1;
    ListNode *temp = head;
    while (cnt < pos)
    {
        temp = temp->next;
        cnt++;
    }
    if (temp->next == NULL)
    {
        insertAtTail(Tail, head, data);
        return;
    }
    if (temp == NULL)
    {
        return;
    }

    ListNode *newNode = new ListNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
}
void deletePos(ListNode *&head, int pos)
{
    if (pos == 1)
    {
        ListNode *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }
    else
    {
        ListNode *prev = NULL;
        ListNode *cur = head;
        int cnt = 1;
        while (cnt < pos && cur != NULL)
        {
            prev = cur;
            cur = cur->next;
            cnt++;
            /* code */
        }
        if (cur == NULL)
        {
            return;
        }
        prev->next = cur->next;
        cur->next = NULL;
        delete cur;
    }
}
int deleteHead(ListNode *&head)
{
    if (head == NULL)
    {
        cout << "List is Null \n";
        return -1;
    }
    ListNode *temp = head;
    head = head->next;
    int ans=temp->data;
    temp->next = NULL;
    
    delete temp;
    return ans;
}
class Queue
{

    ListNode *head;
    ListNode *tail;

public:
    Queue()
    {
        head = NULL;
        tail = NULL;
    }
    void push(int x)
    {
        insertAtTail(tail, head, x);
    }
    int pop()
    {
        return deleteHead(head);
    }
    bool isEmpty()
    {
        if (head == NULL)
        {
            return true;
        }
        return false;
    }
    void printQue()
    {
        printList(head);
    }
};
int main()
{
    
    // ListNode *head = node;
    // ListNode *tail = node;
    // insertAtHead(head, 20);
    // insertAtHead(head, 30);
    // insertAtHead(head, 40);
    // insertAtHead(head, 50);
    // insertAtTail(tail, 100);
    // insertAtTail(tail, 200);
    // insertAtTail(tail, 300);
    // insertAtTail(tail, 400);
    // insertAtTail(tail, 500);
    // insertAtTail(tail, 600);
    // printList(head);
    // insertAtPos(head, tail, 2, 4);
    // deleteHead(head);
    // printList(head);
    Queue q;
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);
    q.push(90);
    q.printQue();
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    q.printQue();

    return 0;
}