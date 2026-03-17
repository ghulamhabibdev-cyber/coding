#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *prev;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
    ~node()
    {
        int val = this->data;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
    }
};
void printNode(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;

        /* code */
    }
    cout << "\n";
}
int getLengthofLinkedList(node *head)
{
    int len = 0;
    node *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
        /* code */
    }
    cout << endl;
    return len;
}
void InsertAtHead(node *&head, int d)
{
    if (head == NULL)
    {
        node *temp = new node(d);
        head = temp;
    }
    else
    {
        node *temp = new node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}
void insertAtTail(node *&tail, int d)
{

    node *temp = new node(d);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}
void insertAtPosition(node *&tail, node *&head, int pos, int d)
{
    // inseting at head
    if (pos == 1)
    {
        InsertAtHead(head, d);
        return;
    }
    node *temp = head;

    int cnt = 1;
    while (cnt < pos - 1)
    {
        temp = temp->next;
        cnt++;
    }
    if (temp->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }
    node *nodeToInset = new node(d);
    nodeToInset->next = temp->next;
    temp->next->prev = nodeToInset;
    temp->next = nodeToInset;
    nodeToInset->prev = temp;
}
void deleteAtPost(node *&head, int pos)
{
    if (head == NULL)
    {
        return;
    }
    if (pos == 1)
    {
        node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
        return;
    }
    else
    {
        node *prev = NULL;
        node *cur = head;
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
        cur->prev = NULL;
        prev->next = cur->next;
        cur->next = NULL;
        delete cur;
    }
}
int main()
{
    node *node1 = new node(5);
    node1->next = new node(10);
    node *head = node1;
    node *tail = node1;
    printNode(head);
    cout << getLengthofLinkedList(head) << endl;
    InsertAtHead(head, 21);
    cout << "Head data : " << head->data << endl;
    cout << "tail Data : " << tail->data << endl;
    InsertAtHead(head, 24);

    insertAtTail(tail, 250);
    printNode(head);
    cout << "Head data : " << head->data << endl;
    cout << "tail Data : " << tail->data << endl;
    insertAtPosition(tail, head, 3, 34);
    // head = NULL;
    InsertAtHead(head, 2450);
    printNode(head);
    deleteAtPost(head, 1);
    printNode(head);
    deleteAtPost(head, 5);
    deleteAtPost(head, 3);
    printNode(head);
    return 0;
}
