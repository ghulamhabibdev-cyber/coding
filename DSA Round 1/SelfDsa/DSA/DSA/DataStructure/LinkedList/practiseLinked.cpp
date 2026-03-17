#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};
void insetAtHead(node * &head,int d)
{
    node* temp=new node(d);
    temp->next=head;
    head=temp;

}
void InsetAtTail()
{

}
void PrintLinkList(node * & head)
{
    node * temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;

}
int main()
{
    node * node1=new node(16);
    node* head=node1;
    insetAtHead(head,12);
    PrintLinkList(head);


    return 0;
}
