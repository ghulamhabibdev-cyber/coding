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
        prev = NULL;
        next = NULL;
    }
};
void insertAtHead(node *&head, int d)
{
    node *nodeToHead = new node(d);
    nodeToHead->next = head;
    head = nodeToHead;
}
void insertAtTail(node *&tail, int d)
{
    node *temp = new node(d);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}
void inserAtPos(node *&head, node *&tail, int pos, int d)
{
    if (head == NULL)
    {
        return;
    }
    if (pos == 1)
    {
        insertAtHead(head, d);
        return;
    }
    node *temp = head;
    int cnt = 1;
    while (cnt < pos)
    {
        temp = temp->next;
        cnt++;
        /* code */
    }
    if (temp->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }
    if(temp==NULL)
    {
        return;
    }
     node *nodeToInset = new node(d);
    nodeToInset->next = temp->next;
    temp->next->prev = nodeToInset;
    temp->next = nodeToInset;
    nodeToInset->prev = temp;
}

void printDoubleLinkList(node *&head)
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
    insertAtHead(head, 20);
    insertAtHead(head, 30);
    insertAtHead(head, 40);
    printDoubleLinkList(head);
    node *tail = node1;
    insertAtTail(tail, 100);
    printDoubleLinkList(head);
    inserAtPos(head, tail, 1, 1500);

    inserAtPos(head, tail, 3, 3500);
    printDoubleLinkList(head);

    return 0;
}
