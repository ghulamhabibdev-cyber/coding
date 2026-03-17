#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int info;
    node* next;
    node(int info)
    {
        this->info=info;
        this->next=0;
    }
    ~node()
    {

    }
};
void insertAtHead(node * &head,node * &tail,int info)
{
    node*temp=new node(info);
    if(head==NULL)
    {
        head=temp;
        tail=temp;
    }
    else{
        temp->next=head;
        head=temp;
    }

}
void insertAtTail(node * &head,node * &tail, int info)
{
    node* newNode=new node(info);
    if(head==NULL)
    {
        head=newNode;
        tail=newNode;
    }
    else{
        tail->next=newNode;
        tail=newNode;
    }
}
void print(node * head)
{
    node* temp=head;
    while (temp!=NULL)
    {
        cout<<temp->info<<" ";
        /* code */
        temp=temp->next;
    }
    cout<<endl;  
}
int main()
{
    node * nod=new node(10);
    node * head=nod;
    node * tail=nod;
    insertAtHead(head,tail,20);
    insertAtHead(head,tail,30);
    insertAtHead(head,tail,40);
    insertAtTail(head,tail,22);
    insertAtTail(head,tail,33);
    insertAtTail(head,tail,44);
    insertAtTail(head,tail,55);