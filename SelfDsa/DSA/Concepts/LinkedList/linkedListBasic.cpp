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
};
void insertHead(node *&head, int d)
{

    node *tempt = new node(d);
    tempt->next = head;
    head = tempt;
}
void insertAtTail(node *&t, int d)
{
    node *tempt = new node(d);
    t->next=tempt;
    t=t->next;
}
void inserAtPos(node* & head,int pos,int d)
{
    
    if(pos==1)
    {
        insertHead(head,d);
        return;
    }
    node* temp=head;
    int cnt=1;
    while(cnt<pos-1)
    {
        temp=temp->next;
        cnt++;
    }
    node* nodeToInsert=new node(d);
    nodeToInsert->next=temp->next;
    temp->next=nodeToInsert;

}
// how to travous link list
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

int main()
{
    node *node1 = new node(10);
    node *tail = node1;
    // cout << node1->data << endl;
    // cout << node1->next << endl;
    node *head = node1;
    insertAtTail(tail, 12);
    insertHead(head,12);
    printLinkList(head);
    inserAtPos(head,10,15);
    printLinkList(head);
    return 0;
}
