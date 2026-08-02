#ifndef H_doublyLinkList
#define H_doublyLinkList
#include <bits/stdc++.h>
#include <cassert>
using namespace std;
template <class Type>
class node
{
public:
    Type info;
    node<Type> *next;
    node<Type> *back;
    node();
    node(Type item);
};
// implementing the node
template <class Type>
node<Type>::node(Type item)
{
    this->info = item;
    this->next = NULL;
    this->back = NULL;
}
template <class Type>
node<Type>::node()
{
    this->info = NULL;
    this->next = NULL;
    this->back = NULL;
}
template <class Type>
class doublyLinkList
{
protected:
    node<Type> *first;
    node<Type> *last;
    int count;

public:
    // constructor
    doublyLinkList();
    doublyLinkList(const doublyLinkList<Type> &otherList);
    ~doublyLinkList();
    // methods
    const doublyLinkList<Type> &operator=(const doublyLinkList<Type> &);
    bool isEmpty();
    void destroy();
    void inlizeList();
    void print();
    void reversePrint();
    int length();
    Type front();
    Type back();
    bool search(const Type &item);
    void insert(const Type &item);
    void deleteNode(const Type &item);

private:
    void copyList(const doublyLinkList<Type> &otherLit);
};
template <class Type>
doublyLinkList<Type>::doublyLinkList()
{
    this->first = NULL;
    this->last = NULL;
    count = 0;
}
template <class Type>
bool doublyLinkList<Type>::isEmpty()
{
    return (count == 0);
}
template <class Type>
void doublyLinkList<Type>::destroy()
{
    node<Type> *temp;
    while (first != NULL)
    {
        temp = first;
        first = first->next;
        delete temp;
    }
    last = NULL;
    count = 0;
}
template <class Type>
doublyLinkList<Type>::~doublyLinkList()
{
    destroy();
}
template <class Type>
void doublyLinkList<Type>::inlizeList()
{
    destroy();
}
template <class Type>
void doublyLinkList<Type>::print()
{
    node<Type> *temp = first;
    while (temp != NULL)
    {
        cout << temp->info << " ";
        temp = temp->next;
    }
    cout << endl;
}
template <class Type>
void doublyLinkList<Type>::reversePrint()
{
    node<Type> *temp = last;
    while (temp != NULL)
    {
        cout << temp->info << " ";
        temp = temp->back;
    }
    cout << endl;
}
template <class Type>
int doublyLinkList<Type>::length()
{
    return this->count;
}
template <class Type>
Type doublyLinkList<Type>::front()
{
    return this->first->info;
}
template <class Type>
Type doublyLinkList<Type>::back()
{
    return this->last->info;
}
template <class Type>
bool doublyLinkList<Type>::search(const Type &item)
{
    node<Type> *temp;
    bool found;
    assert(this->first != NULL);
    temp = first;
    found = false;
    while (temp != NULL && !found)
    {
        if (temp->info == item)
        {
            found = true;
        }
        else
        {
            temp = temp->next;
        }
    }
    if (found)
    {
        found = (temp->info == item);
        return found;
    }
    return found;
}
template <class Type>
void doublyLinkList<Type>::insert(const Type &item)
{
    node<Type> *temp = new node<Type>(item);
    bool found;
    node<Type> *prev;
    node<Type> *curr;
    if (this->first == NULL)
    {
        first = temp;
        last = temp;
        count++;
    }
    else
    {
        found = false;
        curr = first;
        while (curr != NULL && !found)
        {
            if (curr->info >= item)
            {
                found = true;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
        if (curr == first)
        {
            first->back = temp;
            temp->next = first;
            first = temp;
        }
        else
        {
            if (curr != NULL)
            {
                prev->next = temp;
                temp->back = prev;
                temp->next = curr;
                curr->back = temp;
            }
            else
            {
                prev->next = temp;
                temp->back = prev;
                last = temp;
            }
        }
        count++;
    }
}

template <class Type>
void doublyLinkList<Type>::deleteNode(const Type &item)
{
    node<Type> *temp;
    node<Type> *prev;
    node<Type> *curr;
    bool found;
    assert(first != NULL);
    if (first->info == item)
    {
        temp = first;
        first = first->next;
        if (first != NULL)
        {
            first->back = NULL;
        }
        else
        {
            last = NULL;
        }
        delete temp;
        count--;
    }
    else
    {
        found = false;
        curr = first;
        while (curr != NULL && !found)
        {
            if (curr->info >= item)
            {
                found = true;
            }
            else
            {
                curr = curr->next;
            }
        }
        if (curr == NULL)
        {
            cout << "Not Present In List \n";
        }
        else if (curr->info == item)
        {
            prev = curr->back;
            prev->next = curr->next;
            if (curr->next != NULL)
            {
                curr->next->back = prev;
            }
            if (curr == last)
            {
                last = prev;
            }
            count--;
            delete curr;
        }
        else
        {
            cout << "Not in List \n";
        }
    }
}
#endif
