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
        int val = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
    }
};
void inserNodeAtHead(node *&head, int d)
{
    node *temp = new node(d);
    temp->next = head;
    head = temp;
}
void insertNodeAtTail(node *&tail, int d)
{
    node *temp = new node(d);
    tail->next = temp;
    tail = tail->next;
}
void insertAtAnyPostion(node *&head, node *&tail, int pos, int d)
{
    if (pos == 1)
    {
        inserNodeAtHead(head, d);
        return;
    }
    node *temp = head;
    int cnt = 1;
    while (cnt < pos - 1)
    {
        temp = temp->next;
        cnt++;
    }
    if (temp == NULL)
    {
        insertNodeAtTail(tail, d);
        return;
    }
    node *nodeToInsert = new node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}
int getLengthfoLinkedList(node *&head)
{
    node *temp = head;
    int cnt = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        cnt++;
    }
    return cnt;
}
void deleteNodeAtPos(node *&head, int pos)
{

    if (head == NULL)
    {
        return;
    }
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
        int cnt = 1;
        node *prev = NULL;
        node *curr = head;

        while (cnt < pos)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
            /* code */
        }
        if (curr == NULL)
        {
            return;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
void reverse(node *&head, node *curr, node *prev)
{
    if (curr == NULL)
    {
        head = prev;
        return;
    }
    node *forward = curr->next;
    reverse(head, forward, curr);
    curr->next = prev;
}
node *revserlinkList(node *head)
{
    node *curr = head;
    node *prev = NULL;
    reverse(head, curr, prev);

    return head;
}
void printLinkList(node *&head)
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
node *kRevers(node *head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }
    node *next = NULL;
    node *curr = head;
    node *prev = NULL;
    int cont = 0;
    while (curr != NULL && cont < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        cont++;
    }
    if (next != NULL)
    {
        head->next = kRevers(next, k);
    }
    return prev;
}
bool CheckCircularList(node *&head)
{
    bool isCircular = false;
    node *temp = head->next;
    while (temp!=NULL&&temp!=head)
    {
        temp=temp->next;
        /* code */
    }
    if(temp==head)
    {
        return true;
    }
    else{
        return false;
    }
    
   
}
int main()
{
    node *node1 = new node(10);
    node *head = node1;
    inserNodeAtHead(head, 20);
    inserNodeAtHead(head, 30);
    inserNodeAtHead(head, 40);
    inserNodeAtHead(head, 50);
    printLinkList(head);
    node *tail = node1;
    insertNodeAtTail(tail, 30000);
    insertNodeAtTail(tail, 40000);
    insertNodeAtTail(tail, 50000);
    printLinkList(head);
    insertAtAnyPostion(head, tail, 1, 45000);
    insertAtAnyPostion(head, tail, 1, 55000);
    insertAtAnyPostion(head, tail, 3, 666);
    insertAtAnyPostion(head, tail, 3, 777);
    // printLinkList(head);
    cout << "length is : " << getLengthfoLinkedList(head) << endl;
    // deleteNodeAtPos(head, 1);
    // deleteNodeAtPos(head, 3);
    cout << "length is : " << getLengthfoLinkedList(head) << endl;
    // node * get=revserlinkList(head);
    printLinkList(head);
    node *krev = kRevers(head, 4);
    printLinkList(krev);
    cout << endl;
    cout << CheckCircularList(head);
    return 0;
}
