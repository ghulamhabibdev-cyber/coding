#include <bits/stdc++.h>
#include "LinkList.h"
void printList(ListNode *head)
{
    ListNode *temp = head;
    while (temp != nullptr)
    {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}
int countTotalNode(ListNode *list)
{
    ListNode *temp = list;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
void insertFirst(ListNode *&head, int value)
{
    ListNode *newNode = new ListNode(value);
    newNode->next = head;
    head = newNode;
}

// Insert at the end
void insertLast(ListNode *&head, int value)
{
    ListNode *newNode = new ListNode(value);
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    ListNode *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}
void reorderList(ListNode *head)
{
    int totalNode = countTotalNode(head);
    stack<ListNode *> st;
    int rem = totalNode % 2;
    if (rem == 0)
    {
        ListNode *putInStack = head;
        int count = 0;
        while (count != totalNode / 2)
        {
            count++;
            putInStack = putInStack->next;
        }
        while (putInStack != NULL)
        {
            ListNode *temp = putInStack;
            putInStack = putInStack->next;
            temp->next = NULL;
            st.push(temp);
        }
        ListNode* newList=head;
        ListNode*tail=head;
        count=0;
        ListNode *temp=head->next;
        while(count!=totalNode/2)
        {
            ListNode *newNode = new ListNode(temp->val);
            tail->next = newNode;
            tail=newNode;
            temp=temp->next;
            count++;
        }
        printList(newList);

    }
    else
    {
    }
}
int main()
{
    ListNode *head = nullptr;

    insertLast(head, 1);
    insertLast(head, 2);
    insertLast(head, 3);
    insertLast(head, 3);
    // insertLast(head, 50);

    // cout << "Original List: ";
    // printList(head);
    reorderList(head);
    return 0;
}
