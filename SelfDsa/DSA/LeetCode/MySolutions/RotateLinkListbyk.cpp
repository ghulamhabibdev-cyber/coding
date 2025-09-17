#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~node()
    {
    }
};
void insertAtHead(node *&head, int d)
{
    node *temp = new node(d);
    temp->next = head;
    head = temp;
}
void insertAtTail(node *&tail, int d)
{
    node *temp = new node(d);
    tail->next = temp;
    tail = tail->next;
}
void insertAtPosition(node *&tail, node *&head, int pos, int d)
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
    while (cnt < pos - 1)
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
    node *nodeToInsert = new node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}
void deleteAtPost(node *&head, int pos)
{

    if (pos == 1)
    {
        node *temp = head;
        head = head->next;
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
        prev->next = cur->next;
        cur->next = NULL;
        delete cur;
    }
}
void printLinkedList(node *&head)
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
int getLin(node *head)
{
    node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
node *tailNode(node *&head)
{

    node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    node *tailNode = temp->next;
    temp->next = NULL;
    return tailNode;
}
void rotateByK(node *&head, int k)
{
    int count = 0;
    int totalNode = getLin(head);
    if (k > totalNode)
    {
        for (int i = 0; i < totalNode; i++)
        {
            node *newHead = tailNode(head);
            newHead->next = head;
            head = newHead;
            count++;
        }
        int remain = k % totalNode;
        for (int i = 0; i < remain; i++)
        {
            node *newHead = tailNode(head);
            newHead->next = head;
            head = newHead;
            count++;
        }
    }
    else
    {
        for (int i = 0; i < k; i++)
        {
            node *newHead = tailNode(head);
            newHead->next = head;
            head = newHead;
            count++;
        }
    }
    cout << "Total Loop : " << count << endl;
}
int main()
{
    node *node1 = new node(10);
    node *head = node1;
    insertAtHead(head, 20);
    insertAtHead(head, 30);
    // insertAtHead(head, 40);
    node *tail = node1;
    // insertAtTail(tail, 50);

    printLinkedList(head);
    // cout<<tailNode(head)->data<<endl;
    rotateByK(head, 100);
    printLinkedList(head);
    // cout << getLin(head) << endl;
    // cout << 101 % 3 << endl;

    return 0;
}