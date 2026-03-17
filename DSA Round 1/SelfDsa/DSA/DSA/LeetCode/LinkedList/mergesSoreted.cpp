#include <bits/stdc++.h>
using namespace std;
class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int data)
    {
        val = data;
        next = NULL;
    }
};
void insertAtHead(ListNode *&head, ListNode *&tail, int data)
{
    ListNode *temp = new ListNode(data);
    if (head == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }
    temp->next = head;
    head = temp;
}
void insertAtTail(ListNode *&head, ListNode *&tail, int data)
{
    ListNode *temp = new ListNode(data);
    if (head == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }
    tail->next = temp;
    tail = tail->next;
}
void printlList(ListNode *head)
{
    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    if (list1 == NULL && list2 == NULL)
    {
        return NULL;
    }
    if ((list1 == NULL && list2 != NULL))
    {
        return list2;
    }
    if ((list1 != NULL && list2 == NULL))
    {
        return list1;
    }
    ListNode *curr = list1;
    ListNode *prev = NULL;
    ListNode *next = list1->next;
    ListNode *temp = list1;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    ListNode* end=temp;
    ListNode* tempy=list1;
    ListNode *two=list2;
    ListNode * save;
    while (tempy!=NULL)
    {
       if(curr->val>=two->val)
       {
            save=two;
            two->next=curr;
       }
    }
    string name="ak";
    name.length();

    printlList(list1);

    return NULL;
}
int main()
{
    // ListNode *node = new ListNode(1);
    // ListNode *head = node;
    // ListNode *tail = node;
    // // insertAtHead(head, tail, 2);
    // // insertAtHead(head, tail, 3);
    // // insertAtHead(head, tail, 4);
    // insertAtTail(head, tail, 2);
    // insertAtTail(head, tail, 4);
    //  printlList(head);
    // // insertAtTail(head,tail,5);
    // ListNode *node1 = new ListNode(1);
    // ListNode *head2 = node1;
    // ListNode *tail2 = node1;
    // insertAtTail(head2, tail2, 3);
    // insertAtTail(head2, tail2, 4);
    // printlList(head2);
    // ListNode * ans=mergeTwoLists(head,head2);
   
    return 0;
}
