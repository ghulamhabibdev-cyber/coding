#ifndef H_LinkList
#define H_LinkList
#include <bits/stdc++.h>
using namespace std;
template <class Type>
class node
{
public:
    Type info;
    node<Type> *link;
    node(Type info);
    ~node();
};
// Implementing the node for generic
template <class Type>
node<Type>::node(Type info)
{
    this->info = info;
    link = NULL;
}
template <class Type>
node<Type>::~node()
{
}

template <class Type>
class LinkListItereator
{
public:
    LinkListItereator();
    LinkListItereator(node<Type> *nody);
    // Type operator[]();
    LinkListItereator<Type> operator++();
    Type operator*();
    bool operator==(const LinkListItereator<Type> &right);
    bool operator!=(const LinkListItereator<Type> &right);

private:
    node<Type> *current;
};
template <class Type>
bool LinkListItereator<Type>::operator!=(const LinkListItereator<Type> &right)
{
    return (current != right.current);
}
template <class Type>
bool LinkListItereator<Type>::operator==(const LinkListItereator<Type> &right)
{
    return (current == right.current);
}
template <class Type>
LinkListItereator<Type> LinkListItereator<Type>::operator++()
{
    current = current->link;
    return *this;
}
template <class Type>
Type LinkListItereator<Type>::operator*()
{
    return current->info;
}
template <class Type>
LinkListItereator<Type>::LinkListItereator()
{
    this->current = 0;
}
template <class Type>
LinkListItereator<Type>::LinkListItereator(node<Type> *curr)
{
    this->current = curr;
}
template <class Type>
class LinkList
{
public:
    void intializeList();
    bool isEmpty();
    void print();
    int length();
    void destroyList();
    Type front();
    Type back();
    LinkListItereator<Type> begin();
    LinkListItereator<Type> end();
    LinkList();
    LinkList(const LinkList<Type> &otherList);
    ~LinkList();
    // LinkList(const LinkList<Type> &OtherList);
    virtual bool search(const Type &item) = 0;
    virtual void insertFirst(const Type &item) = 0;
    virtual void insertLast(const Type &item) = 0;
    virtual void deleteNode(const Type &delItem) = 0;
    const LinkList<Type> &operator=(const LinkList<Type> &otherList);

private:
    void copyList(const LinkList<Type> &other);

protected:
    int count;
    node<Type> *first;
    node<Type> *last;
};

// implement the generic iteraor for Linkk list
template <class Type>
bool LinkList<Type>::isEmpty()
{
    if (first == NULL && last == NULL && count == 0)
    {
        return true;
    }
    return false;
}
template <class Type>
const LinkList<Type> &LinkList<Type>::operator=(const LinkList<Type> &otherList)
{
    if (this != &otherList)
    {
        copyList(otherList);
    }

    return *this;
}
template <class Type>
LinkList<Type>::LinkList(const LinkList<Type> &otherList)
{
    first = NULL;
    last = NULL;
    count = 0;
    copy(otherList);
}
template <class Type>
LinkList<Type>::~LinkList()
{
    destroyList();
}
template <class Type>
void LinkList<Type>::copyList(const LinkList<Type> &otherList)
{
    node<Type> *newNode;
    node<Type> *current;
    if (first != NULL)
    {
        destroyList();
    }
    if (otherList.first == NULL)
    {
        first = nullptr;
        last = nullptr;
        length = 0;
    }
    else
    {
        current = otherList.first;
        count = otherList.count;
        first = new node<Type>;
        first->info = current->info;
        first->link = nullptr;
        current = current->link;
        while (current != NULL)
        {
            newNode = new node<Type>;
            newNode->info = current->info;
            newNode->link = NULL;
            last->link = newNode;
            last = newNode;
            current = current->link;
        }
    }
}
template <class Type>
LinkListItereator<Type> LinkList<Type>::end()
{
    LinkListItereator<Type> temp(last);
    return temp;
}
template <class Type>
LinkListItereator<Type> LinkList<Type>::begin()
{
    LinkListItereator<Type> temp(first);
    return temp;
}
template <class Type>
Type LinkList<Type>::back()
{
    assert(last != nullptr);
    return last->info;
}
template <class Type>
Type LinkList<Type>::front()
{
    assert(first != NULL);
    return first->info;
}
template <class Type>
int LinkList<Type>::length()
{
    return count;
}
template <class Type>
void LinkList<Type>::print()
{

    node<Type> *temp = first;
    while (temp != NULL)
    {
        cout << temp->info << " ";
        temp = temp->link;
    }
    cout << endl;
}
template <class Type>
void LinkList<Type>::intializeList()
{
    destroyList();
}
template <class Type>
void LinkList<Type>::destroyList()
{
    node<Type> *temp;
    while (first != NULL)
    {
        temp = first;
        first = first->link;
        delete temp;
        /* code */
    }
    last = 0;
    count = 0;
}
template <class Type>
LinkList<Type>::LinkList()
{
    this->first = NULL;
    this->last = 0;
    count = 0;
}
#endif
