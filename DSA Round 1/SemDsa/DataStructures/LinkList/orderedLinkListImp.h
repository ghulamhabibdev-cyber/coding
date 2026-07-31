#ifndef H_LinkListTypes
#define H_LinkListTypes
#include <bits/stdc++.h>
#include "ImplementGenericLinkList.h"
using namespace std;
template <class Type>
class orderedLinkList : public LinkList<Type>
{
public:
    bool search(const Type &item);
    void insert(const Type &item);
    void insertFirst(const Type &item);
    void insertLast(const Type &item);
    void deleteNode(const Type &delItem);
};

// Implementing unorederedLink List
template <class Type>
void orderedLinkList<Type>::deleteNode(const Type &delItem)
{
    if (this->first == NULL)
    {
        cout << "Error: list is empty\n";
        return;
    }

    node<Type> *current = this->first;
    node<Type> *prev = nullptr;
    bool found = false;

    while (current != NULL && !found)
    {
        if (current->info == delItem)
        {
            found = true;
        }
        else
        {
            prev = current;
            current = current->link;
        }
    }

    if (!found)
    {
        cout << "Item not in list\n";
        return;
    }

    // Delete the node
    if (current == this->first) // first node
    {
        this->first = this->first->link;
        if (current == this->last) // only one node
            this->last = nullptr;
    }
    else
    {
        prev->link = current->link;
        if (current == this->last)
            this->last = prev;
    }

    delete current;
    this->count--;
}

template <class Type>
void orderedLinkList<Type>::insert(const Type &item)
{
    node<Type> *current;
    node<Type> *prev;
    node<Type> *newNode = new node<Type>(item);
    bool found = false;
    if (this->first == NULL)
    {
        this->first = newNode;
        this->last = newNode;
        this->count++;
    }
    else
    {
        current = this->first;
        while (current != NULL && !found)
        {
            if (current->info >= item)
            {
                found = true;
            }
            else
            {
                prev = current;
                current = current->link;
            }
        }
        if (current == this->first)
        {
            newNode->link = this->first;
            this->first = newNode;
            this->count++;
        }
        else
        {
            prev->link = newNode;
            newNode->link = current;
            if (current == this->last)
            {
                this->last = newNode;
            }
            this->count++;
        }
    }
}
template <class Type>
void orderedLinkList<Type>::insertLast(const Type &item)
{
    insert(item);
}
template <class Type>
void orderedLinkList<Type>::insertFirst(const Type &item)
{
    insert(item);
}
template <class Type>
bool orderedLinkList<Type>::search(const Type &item)
{
    bool found = false;
    node<Type> *temp;
    temp = this->first;
    while (temp != NULL && !found)
    {
        if (temp->info == item)
        {
            found = true;
        }
        else
        {
            temp = temp->link;
        }
        /* code */
    }
    return found;
}

#endif