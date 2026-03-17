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
        this->prev = NULL;
        this->next = NULL;
    }
};
void insertNodeAtHead(node *&head, int d)
{
    node *temp = new node(d);
    temp->next = head;
    head->prev = temp;
    head = temp;
}
void insertAtTail(node *&tail, int d)
{
    node *temp = new node(d);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
}
void printDoubleLink(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
        /* code */
    }
    cout << endl;
}
int main()
{
    node *node1 = new node(10);
    node *head = node1;
    insertNodeAtHead(head, 20);
    insertNodeAtHead(head, 30);
    node * tail=node1;
    insertAtTail(tail,0);
    printDoubleLink(head);

    return 0;
}