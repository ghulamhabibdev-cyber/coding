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
void apend(node * &head,node *app)
{
    node * temp=head;
    while (temp!=NULL)
    {
        temp=temp->next;
        /* code */
    }
    cout<<temp->data<<endl;
    
}
node *reverPartTwo(node *head, int left, int right)
{
    int rightCnt = 0;
    int leftCnt = 0;
    node *temp = head;

    while (right != 0)
    {
        temp = temp->next;
        right--;
        /* code */
    }
    cout << temp->data << endl;

    node *rightNode = temp;
    node *rightNext = temp->next;
    temp->next = NULL;
    temp = head;
    node *start;
    while (left != 0)
    {
        if (left == 1)
        {
            start = temp;
        }

        temp = temp->next;
        left--;
    }

    node *leftPosNode = NULL;
    cout << temp->data << endl;
    leftPosNode = temp;
    while (right != 0)
    {
        leftPosNode = temp->next;
        right--;
    }
    node * temp1=head;
    while(temp1!=NULL)
    {
        temp1=temp1->next;

    }
    while (start->next!=NULL)
    {
        cout<<">"<<start->data<< " ";
        start=start->next;
        /* code */
    }
    node * tempy=head;
    while (tempy->next!=NULL)
    {
        tempy=tempy->next;
        /* code */
    }
    
    
    cout<<endl;
    
    // node *lefty=leftPosNode;
    // temp1->next=leftPosNode->next;

    printLinkList(leftPosNode);
    leftPosNode = reverLinkList(leftPosNode);
    printLinkList(leftPosNode);
    // printLinkList(head);
    // printLinkList(rightNext);
    // tempy=leftPosNode;
    // cout<<"Printing tempy\n";
    // printLinkList(tempy);
    // head->next=tempy;
    // printLinkList(head);
    // head=rightNode;
    // printLinkList(head);
    // cout<<"Riaght\n";
    // printLinkList(rightNext);
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
    // node * headseve=head;
    // head=reverLinkList(head);
    // printLinkList(headseve);
    // printLinkList(head);
    // apend(headseve,head);
    // node *revList=reverLinkList(head);
    // printLinkList(revList);
    cout << reverPartTwo(head, 1, 3)->data << endl;

    return 0;
}