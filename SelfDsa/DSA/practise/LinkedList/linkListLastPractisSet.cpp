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
        int val = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
    }
};
void insertAtHead(ListNode *&head, int data)
{
    ListNode *newNode = new ListNode(data);
    newNode->next = head;
    head = newNode;
}
void insertAtTail(ListNode *&tail, int data)
{
    ListNode *newNode = new ListNode(data);
    tail->next = newNode;
    tail = newNode;
}
void insertAtPos(ListNode *&head, ListNode *&tail, int pos, int data)
{
    if (pos == 0)
    {
        insertAtHead(head, data);
        return;
    }
    int cnt = 1;
    ListNode *temp = head;
    while (cnt < pos - 1)
    {
        temp = temp->next;
        cnt++;
        /* code */
    }
    if (temp == NULL)
    {
        insertAtTail(tail, data);
        return;
    }
    ListNode *newNode = new ListNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
}
void deleteAtPos(ListNode *&head, int pos)
{

    if (pos == 0)
    {
        ListNode *temp = head;
        head = temp->next;
        delete temp;
        return;
    }
    int cnt = 0;
    ListNode *prev = NULL;
    ListNode *curr = head;
    while (cnt < pos && curr != NULL)
    {
        prev = curr;
        curr = curr->next;
        cnt++;
    }
    if (curr == NULL)
    {
        return;
    }
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
}
void printLinkeList(ListNode *head)
{
    ListNode *temp = head;
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
    ListNode *startNode = new ListNode(2);
    ListNode *head = startNode;
    ListNode *tail = startNode;
    insertAtHead(head, 3);
    insertAtHead(head, 4);
    printLinkeList(head);
    insertAtTail(tail, 7);
    insertAtTail(tail, 8);
    insertAtTail(tail, 9);
    // printLinkeList(head);
    insertAtPos(head, tail, 0, 10);

    insertAtPos(head, tail, 4, 40);
    printLinkeList(head);

    // deleteAtPos(head, 0);
    deleteAtPos(head, 2);
    printLinkeList(head);

    return 0;
}