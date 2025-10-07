#ifndef H_LinkedList
#define H_LinkedList

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

class LinkedList
{
private:
    ListNode *head;

public:
    LinkedList() : head(nullptr) {}

    // insert functions
    void insertFirst(int value)
    {
        ListNode *newNode = new ListNode(value);
        newNode->next = head;
        head = newNode;
    }

    void insertLast(int value)
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

    // delete by value
    void deleteNode(int value)
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

    // print the linked list
    void printList()
    {
        ListNode *temp = head;
        while (temp != nullptr)
        {
            cout << temp->val << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // reverse iterative
    void reverseIterative()
    {
        ListNode *prev = nullptr, *curr = head, *next = nullptr;
        while (curr != nullptr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    // reverse recursive
    ListNode *reverseRecursiveHelper(ListNode *node)
    {
        if (node == nullptr || node->next == nullptr)
            return node;

        ListNode *rest = reverseRecursiveHelper(node->next);
        node->next->next = node;
        node->next = nullptr;
        return rest;
    }

    void reverseRecursive()
    {
        head = reverseRecursiveHelper(head);
    }

    // reverse print (without reversing)
    void printReverseHelper(ListNode *node)
    {
        if (node == nullptr)
            return;
        printReverseHelper(node->next);
        cout << node->val << " -> ";
    }

    void printReverse()
    {
        printReverseHelper(head);
        cout << "NULL\n";
    }
};

#endif
