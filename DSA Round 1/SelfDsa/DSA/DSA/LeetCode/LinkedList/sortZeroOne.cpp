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

    ~node()
    {
        int val = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Memory free for node with data " << val << endl;
    }
};

void insertNodeAtTail(node *&tail, int d)
{
    node *temp = new node(d);
    tail->next = temp;
    tail = temp;
}

void sortZeroOnetwo2(node *&head)
{
    // Create dummy heads and tails for 0s, 1s, 2s
    node *zeroNode = new node(-1);
    node *zeroTail = zeroNode;

    node *oneNode = new node(-1);
    node *oneTail = oneNode;

    node *twoNode = new node(-1);
    node *twoTail = twoNode;

    // Traverse original list and segregate nodes
    node *curr = head;
    while (curr != NULL)
    {
        int value = curr->data;
        if (value == 0)
        {
            insertNodeAtTail(zeroTail, value);
        }
        else if (value == 1)
        {
            insertNodeAtTail(oneTail, value);
        }
        else
        {
            insertNodeAtTail(twoTail, value);
        }
        curr = curr->next;
    }

    // Merge lists properly
    if (zeroNode->next != NULL)
    {
        head = zeroNode->next;
        if (oneNode->next != NULL)
        {
            zeroTail->next = oneNode->next;
            oneTail->next = twoNode->next;
        }
        else
        {
            zeroTail->next = twoNode->next;
        }
    }
    else if (oneNode->next != NULL)
    {
        head = oneNode->next;
        oneTail->next = twoNode->next;
    }
    else
    {
        head = twoNode->next;
    }

    // Delete dummy nodes
    delete zeroNode;
    delete oneNode;
    delete twoNode;
}

void printList(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Test case
int main()
{
    node *head = new node(1);
    node *tail = head;

    insertNodeAtTail(tail, 0);
    insertNodeAtTail(tail, 2);
    insertNodeAtTail(tail, 1);
    insertNodeAtTail(tail, 0);

    cout << "Before sorting: ";
    printList(head);

    sortZeroOnetwo2(head);

    cout << "After sorting: ";
    printList(head);

    return 0;
}
