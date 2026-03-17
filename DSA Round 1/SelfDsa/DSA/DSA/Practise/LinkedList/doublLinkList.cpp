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
void printDLL(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    cout << "============================================================\n";
}
void insertAtHead(node *&head, int data)
{
    node *toInsert = new node(data);
    toInsert->next = head;
    head = toInsert;
}
void insertAtTail(node *&tail, int data)
{
    node *temp = new node(data);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}
void insertAtPostion(node *&head, node *&tail, int pos, int data)
{

    if (pos == 1)
    {
        insertAtHead(head, data);
        return;
    }
    int count = 0;
    node *temp = head;
    while (count < (pos))
    {
        temp = temp->next;
        count++;
        /* code */
    }
    if (temp->next == NULL)
    {
        insertAtTail(tail, data);
        return;
    }
    node *nodeToinsert = new node(data);
    nodeToinsert->next = temp->next;
    temp->next->prev = nodeToinsert;
    temp->next = nodeToinsert;
    nodeToinsert->prev = temp;
}
int main()
{
    node *node1 = new node(10);
    node *head = node1;
    insertAtHead(head, 20);
    insertAtHead(head, 30);
    insertAtHead(head, 40);
    node *tail = node1;
    insertAtTail(tail, 0);
    insertAtPostion(head, tail, 2, 12);

    printDLL(head);

    return 0;
}