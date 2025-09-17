#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *rand;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->rand = NULL;
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
void setRandomPointerPos(node *&head, int pos)
{
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
node *reverLinkList(node *&head)
{
    if (head == NULL)
    {
        return NULL;
    }
    node *curr = head;
    node *prev = NULL;
    node *nextNode = NULL;
    while (curr != NULL)
    {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;

        /* code */
    }
    return prev;
}
void printLinkList(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int getLengthfoLinkedList(node *head)
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
void apend(node *&head, node *app)
{
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
        /* code */
    }
    temp->next = app;
    // head=temp;
}
node *reversPartTwo(node *head, int left, int right)
{
    node *leftNode = new node(0);
    node *rightNode = NULL;
    node *temp = head;
    // get pos where right side start
    while (right != 0)
    {
        temp = temp->next;
        right--;
    }
    rightNode = temp;
    printLinkList(rightNode);
    cout << "\n right print ;\n";
    temp=head;
    while (left!=0)
    {
        leftNode->next=temp;
        leftNode=temp;
        
        temp=temp->next;
        left--;
    }
    printLinkList(leftNode);
    
    return NULL;
}

int main()
{
    cout << endl;
    node *node1 = new node(1);
    node *head = node1;
    node *tail = node1;
    insertNodeAtTail(tail, 2);
    insertNodeAtTail(tail, 3);
    insertNodeAtTail(tail, 4);
    insertNodeAtTail(tail, 5);
    insertNodeAtTail(tail, 6);
    insertNodeAtTail(tail, 7);
    insertNodeAtTail(tail, 8);
    // printLinkList(head);
    node *nf = new node(43);
    node *nf1 = new node(43);
    apend(head, nf);
    apend(head, nf1);
    //  printLinkList(head);
    cout<<reversPartTwo(head, 2, 5)->data;
    // node * clone1=clone(head);
}