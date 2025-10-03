#include <bits/stdc++.h>
using namespace std;
class a
{
public:
};
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
    }
};
int countTotalNode(ListNode *head)
{
    ListNode *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
void insertAtHead(ListNode *&head, int d)
{
    ListNode *temp = new ListNode(d);
    temp->next = head;
    head = temp;
}
void insertAtTail(ListNode *&tail, int d)
{
    ListNode *temp = new ListNode(d);
    tail->next = temp;
    tail = tail->next;
}
void printLinkedList(ListNode *head)
{
    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

ListNode *removeNthFromEnd(ListNode *head, int n)
{

    int totalNodes = countTotalNode(head);
    if (totalNodes - n == 0)
    {
        ListNode *temp = head->next;
        delete head;
        head = NULL;
        head = temp;
        return head;
    }
    else
    {
        int count = 1;
        ListNode *temp = head;
        while (count != totalNodes - n)
        {
            count++;
            temp = temp->next;
        }
        ListNode *del = temp->next;
        ListNode *conti = NULL;
        if (temp->next->next == NULL)
        {
            delete del;
            temp->next = NULL;
            return head;
        }
        else
        {
            conti = temp->next->next;
            temp->next = NULL;
            temp->next = conti;
            return head;
        }
    }
}
// ListNode *deleteDuplicates(ListNode *head)
// {
//     if (head == NULL)
//     {
//         return head;
//     }
//     ListNode *temp = head;
//     while (temp != NULL)
//     {
//         ListNode *next = temp->next;
//         if (next != NULL && temp->data == next->data)
//         {
//             ListNode *join = next->next;
//             delete next;
//             temp->next = join;
//         }
//         else
//         {
//             temp = temp->next;
//         }
//     }
//     return head;
// }
ListNode *deleteDuplicates(ListNode *head)
{

    if (head == NULL)
    {
        return head;
    }
    ListNode *temp = head;
    ListNode* prev=head;
    while (temp != NULL)
    {

        if (temp->next != NULL && temp->data == temp->next->data)
        {
            ListNode *del1 = temp;
            ListNode *del2 = temp->next;
            ListNode *join = temp->next->next;

            delete del1;
            delete del2;
            
           
            prev->next=join;
            temp=join;
            
        }
        else
        {
            prev=prev->next;
            temp = temp->next;
        }
    }
    return head;
}
int main()
{
   ListNode *node=new ListNode(1);
    ListNode *head = node;
    ListNode *tail = node;
    insertAtTail(tail, 1);
    insertAtTail(tail, 2);
    insertAtTail(tail, 3);
    insertAtTail(tail, 3);
    insertAtTail(tail, 4);
    insertAtTail(tail, 4);
    insertAtTail(tail, 5);

    // cout << "Toal node are : " << countTotalNode(head) << endl;
    // printLinkedList(head);
    // cout << removeNthFromEnd(head, 1) << endl;
    // insertAtTail(tail,2);
    ListNode *ans = deleteDuplicates(head);
    printLinkedList(ans);
    return 0;
}