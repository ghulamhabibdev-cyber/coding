#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int info;
    node *link;
    node(int info)
    {
        this->info = info;
        link = 0;
    }
    ~node()
    {
        
    }
};
void insertAtHead(node * &head, int data)
{
    node *newNode=new node(data);
    newNode->link =head;
    head=newNode;
    
}
void insertAtTail(node *&head, node *&tail, int data)
{
    node * newNode=new node(data);
    if(head==0)
    {
        head=newNode;
        tail=newNode;
    }
    else{
        tail->link=newNode;
        tail=newNode;
    }
}
void insertAtPos(node * &head,int pos, int data)
{
    node * newNode=new node(data);
    if(pos==0)
    {
        newNode->link=head;
        head=newNode;
        return;
    }

    int count=1;
    node *temp=head;
    while (count!=pos && temp!=NULL)
    {
        temp=temp->link;
        count++;
    }
    if(temp==0)
    {
        return;
    }
    newNode->link=temp->link;
    temp->link=newNode;
}
void printList( node *head)
{   
    node *temp=head;
    while (temp!=NULL)
    {
        cout<<temp->info<<" ";
        temp=temp->link;
        /* code */
    }    
}
void deleNode(node *&head, int pos)
{
    if(pos==0)
    {
        return;
    }
    int count=1;
    node * temp=head;
    while (count!=pos-1 && pos!=1)
    {
        // cout<<"!!!!\n";
        temp=temp->link;
        count++;
        /* code */
    }
    if(pos==1)
    {
        node * del=temp;
        head=del->link;
        delete del;
        return ;
    }
    if(temp==0)
    {
        return ;
    }
    node * del=temp->link;
    temp->link=del->link;
    delete del;
    
}
node *reverseList(node *&head)
{

}

int main()
{

    node *first;
    node *head = first;
    node *tail = first;
    insertAtHead(head,1);
    insertAtHead(head,3);
    insertAtHead(head,4);
    insertAtTail(head,tail,12);
    insertAtTail(head,tail,13);
    insertAtTail(head,tail,14);
    insertAtTail(head,tail,15);
    insertAtPos(head,0,2000);
    insertAtPos(head,1,3000);
    insertAtPos(head,4,2000);
    insertAtPos(head,6,324);
    printList(head);
    cout<<"\nDeleting \n";
    deleNode(head,1);
    printList(head);

    return 0;
}
