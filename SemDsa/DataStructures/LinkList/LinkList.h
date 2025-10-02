#ifndef H_linkList
#define H_linkList
#include <bits/stdc++.h>
#include <cassert>
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
// implementing the node
template <class Type>
node<Type>::node(Type info)
{
    this->info = info;
    this->link = 0;
}
// implementing the destructor
template <class Type>
node<Type>::~node()
{
}
template <class Type>
class linkListIterator
{
public:
    linkListIterator();
    linkListIterator(node<Type> *ptr);
    Type operator*();
    linkListIterator<Type> operator++();

    bool operator==(linkListIterator<Type> &right);
    bool operator!=(linkListIterator<Type> &right);

private:
    node<Type> *current;
};
// implement iterator
template <class Type>
linkListIterator<Type>::linkListIterator()
{
    this->current = 0;
}
template <class Type>
Type linkListIterator<Type>::operator*()
{
    return this->current->info;
}
template <class Type>
linkListIterator<Type> linkListIterator<Type>::operator++()
{
    current = current->link;
    return *this;
}
template <class Type>
bool linkListIterator<Type>::operator==(linkListIterator<Type> &rihgt)
{
    return (this->current == rihgt.current);
}
template <class Type>
bool linkListIterator<Type>::operator!=(linkListIterator<Type> &rihgt)
{
    return (this->current != rihgt.current);
}
// implementing the LinkList the we implemnt two list unorderedLinkList and OrderedLink List
template <class Type>
class linkList
{

public:
    // common in all
    linkList<Type> &operator=(const linkList<Type> &otherList);
    void inlizeList();
    bool isEmpty();
    void print();
    int Getlength();
    void destroyList();
    Type front();
    Type back();
    // must be implemented in derived classed
    virtual bool search(const Type &item) = 0;
    virtual void insertLast(const Type &item) = 0;
    virtual void insertFirst(const Type &item) = 0;
    virtual void deleteNode(const Type &item) = 0;
    // for itereator
    linkListIterator<Type> begin();
    linkListIterator<Type> end();
    linkList();
    linkList(const linkList<Type> &otherList);
    ~linkList();

protected:
    node<Type> *first;
    node<Type> *last;
    int count;

private:
    void copyList(const linkList<Type> &otherList);
};
template <class Type>
linkList<Type>::linkList()
{
    this->first = NULL;
    this->last = nullptr;
    count = 0;
}
template <class Type>
void linkList<Type>::destroyList()
{
    node<Type> *temp;
    while (first != nullptr)
    {
        temp = first;
        first = first->link;
        delete temp;
        /* code */
    }
    last = nullptr;
    count = 0;
}
template <class Type>
void linkList<Type>::inlizeList()
{
    destroyList();
}
template <class Type>
void linkList<Type>::print()
{
    node<Type> *temp = this->first;
    while (temp != NULL)
    {
        cout << temp->info << "-->" << "";
        temp = temp->link;
    }
    cout<<endl;
}
template <class Type>
bool linkList<Type>::isEmpty()
{
    return (count == 0);
}
template <class Type>
int linkList<Type>::Getlength()
{
    return this->count;
}
template <class Type>
Type linkList<Type>::front()
{
    assert(first != NULL);
    return this->first->info;
}
template <class Type>
Type linkList<Type>::back()
{
    return this->last->info;
}
template <class Type>
linkListIterator<Type> linkList<Type>::begin()
{
    // assert()
    linkListIterator<Type> temp(first);
    return temp;
}
template <class Type>
linkListIterator<Type> linkList<Type>::end()
{
    linkListIterator<Type> temp(NULL);
    return temp;
}
template <class Type>
void linkList<Type>::copyList(const linkList<Type> &other)
{
    node<Type> *temp;
    node<Type> *current;
    if (first != NULL)
    {
        destroyList();
    }
    if (other.first == NULL)
    {
        first = NULL;
        last = NULL;
        count = 0;
    }
    else
    {
        current = other.first;
        count = other.count;
        this->first = new node<Type>;
        this->first->info = current->info;
        this->first->link = NULL;
        current = current->link;
        while (current != NULL)
        {
            temp = new node<Type>();
            temp->info = current->info;
            temp->link = NULL;
            last->link = temp;
            last = temp;

            /* code */
        }
    }
}
template <class Type>
linkList<Type>::~linkList()
{
    destroyList();
}
template <class Type>
linkList<Type>::linkList(const linkList<Type> &other)
{
    destroyList();
    copyList(other);
}
// virtual bool search(const Type &item) = 0;
// virtual void insertLast(const Type &item) = 0;
// virtual void insertLast(const Type &item) = 0;
// virtual void deleteNode(const Type &item) = 0;
template <class Type>
class unorederedLinkList : public linkList<Type>
{
public:
    bool search(const Type &item);
    void insertLast(const Type &item);
    void insertFirst(const Type &item);
    void deleteNode(const Type &item);
};
template <class Type>
bool unorederedLinkList<Type>::search(const Type &item)
{
    bool found = false;
    node<Type> *current = this->first;
    current = this->first;
    while (current != NULL && !found)
    {
        if (item == current->info)
        {
            found = true;
        }
        else
        {
            current = current->link;
        }
    }
    if (found)
    {
        return found;
    }
    return found;
}
template <class Type>
void unorederedLinkList<Type>::insertFirst(const Type &item)
{
    node<Type> *temp = new node<Type>(item);
    if (this->first == NULL)
    {
        this->first = temp;
        this->last = temp;
    }
    else
    {
        temp->link = this->first;
        this->first = temp;
    }
    this->count++;
}
template <class Type>
void unorederedLinkList<Type>::insertLast(const Type &item)
{
    node<Type> *temp = new node<Type>(item);
    if (this->first == NULL)
    {
        this->first = temp;
        this->last = temp;
    }
    else
    {
        this->last->link = temp;
        this->last = temp;
    }
    this->count++;
}
template <class Type>
void unorederedLinkList<Type>::deleteNode(const Type &item)
{
    node<Type> *current;
    node<Type> *prev;
    assert(this->first != NULL);
    if (this->first->info == item)
    {
        current = this->first;
        this->first = this->first->link;

        if (this->first == NULL)
        {
            this->last = NULL;
        }
        delete current;
    }
    else
    {
        prev = this->first;
        bool found = false;
        // if(found)

        current = this->first->link;
        while (current != NULL && !found)
        {
            if (current->info != item)
            {
                prev = current;
                current = current->link;
            }
            else
            {
                found = true;
            }
        }
        if (found)
        {
            prev->link = current->link;
            this->count--;
            if (this->first == NULL)
            {
                this->last = NULL;
            }
            delete current;
        }
        else
        {
            cout << "Not Presnt in list\n";
        }
    }
}
template <class Type>
class orederedLinkList : public linkList<Type>
{
    bool search(const Type &item);
    void insert(const Type &item);
    void insertFirst(const Type &item);
    void insertLast(const Type &item);
    void deleteNode(const Type &delItem);
};


#endif
