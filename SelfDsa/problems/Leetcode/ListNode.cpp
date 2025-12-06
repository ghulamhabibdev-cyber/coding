#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;

    // constructors
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Insert at the beginning
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

// Delete a node by value
void deleteNode(ListNode *&head, int value)
{
    if (head == nullptr)
        return;

    if (head->val == value)
    {
        ListNode *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    ListNode *curr = head;
    while (curr->next != nullptr && curr->next->val != value)
    {
        curr = curr->next;
    }

    if (curr->next != nullptr)
    {
        ListNode *temp = curr->next;
        curr->next = curr->next->next;
        delete temp;
    }
    else
    {
        cout << "Value " << value << " not found!\n";
    }
}

// Print the linked list
void printList(ListNode *head)
{
    ListNode*temp=head;
    while (temp != nullptr)
    {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Reverse (iterative)
void reverseIterative(ListNode *&head)
{
    ListNode *prev = nullptr, *curr = head, *next = nullptr;
    while (curr != nullptr)
    {
        next = curr->next; // store next
        curr->next = prev; // reverse link
        prev = curr;       // move prev ahead
        curr = next;       // move curr ahead
    }
    head = prev; // new head
}

// Reverse (recursive)
ListNode *reverseRecursive(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode *rest = reverseRecursive(head->next);
    head->next->next = head;
    head->next = nullptr;
    return rest;
}

int main()
{
    ListNode *head = nullptr;

    insertLast(head, 10);
    insertLast(head, 20);
    insertLast(head, 30);
    insertLast(head, 40);
    insertLast(head, 50);

    cout << "Original List: ";
    printList(head);

    reverseIterative(head);
    cout << "Reversed Iterative: ";
    printList(head);

    head = reverseRecursive(head);
    cout << "Reversed Recursive: ";
    printList(head);

    return 0;
}
