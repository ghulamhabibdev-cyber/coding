#ifndef H_doublyLinkList
#define H_doublyLinkList
#include <bits/stdc++.h>
using namespace std;
template <class Type>
class node
{
public:
    Type info;
    node<Type> *next;
    node<Type> *back;
    node(Type info);
    node()
    {
    }
    ~node();
};
template <class Type>
node<Type>::node(Type info)
{
    this->info = info;
    back = 0;
    next = 0;
}
template <class Type>
node<Type>::~node()
{
}

template <class Type>
class doublyIterator
{
public:
    doublyIterator();
    doublyIterator(node<Type> *nody);
    // Type operator[]();
    doublyIterator<Type> operator++();
    Type operator*();
    bool operator==(const doublyIterator<Type> &right);
    bool operator!=(const doublyIterator<Type> &right);

private:
    node<Type> *current;
};
template<class Type>
bool doublyIterator<Type>::operator!=(const doublyIterator<Type>&right)
{
    return (current!=right.current);
}
template<class Type>
bool doublyIterator<Type>::operator==(const doublyIterator<Type>&right)
{
    return (current=right.current);
}
template<class Type>
doublyIterator<Type> doublyIterator<Type>::operator++()
{
    current=current->next;
    return *this;
}
template <class Type>
Type doublyIterator<Type>::operator*()
{
    return *cruuent;
}
template <class Type>
doublyIterator<Type>::doublyIterator(node<Type> *nody)
{
    this->current = nody;
}
template<class Type>
doublyIterator<Type>::doublyIterator()
{
    current=0;
}
template <class Type>
class doublyLinkList
{
public:
    bool isEmpty();
    void destroyList();
    int length();
    void print();
    doublyIterator<Type> &begin();
    doublyIterator<Type> &end();
    Type front();
    Type back();
    void makeCircular();
    void inilizeList();
    bool search(const Type &item);
    void insertFirst(const Type &item);
    void insertLast(const Type &item);
    void deleteNode(const Type &delItem);
    void makeStraight();
    bool search(const Type &item);
    void insert(const Type &item);
    void insertFirst(const Type &item);
    void insertLast(const Type &item);
    void deleteNode(const Type &delItem);
    const doublyLinkList<Type> &operator=(const doublyLinkList<Type> &otherList);

public:
    doublyLinkList();
    doublyLinkList(doublyLinkList<Type> &otherList);
    ~doublyLinkList();

private:
    void copy(doublyLinkList<Type> &otherList);
private:
    int len;
    node<Type> *first;
    node<Type> *last;
};
template<class Type>
void doublyLinkList<Type>::insert(const Type &item)
{
    
}
template<class Type>
void doublyLinkList<Type>::insertFirst(const Type &item)
{
    insert(item);
}
template<class Type>
void doublyLinkList<Type>::insertLast(const Type &item)
{
    insert(item);
}
template<class Type>
void doublyLinkList<Type>::makeStraight()
{
    node<Type>*slow=first;
    node<Type>*fast=first->next;
    while (fast!=slow)
    {
        slow=slow->next;
        fast=fast->next->next;
        
    }
    fast->next=NULL;
    first->back=NULL;
    
}
template<class Type>
void doublyLinkList<Type>::makeCircular()
{
    last->next=first;
    first->back=last;
}
template<class Type>
void doublyLinkList<Type>::inilizeList()
{
    destroyList();
    this->first=0;
    this->last=0;
    this->len=0;
}
template<class Type>
int doublyLinkList<Type>::length()
{
    return len;
}
// impleemting douly link list
template<class Type>
void doublyLinkList<Type>::print()
{
    node<Type>* temp=first;
    while (temp!=NULL)
    {
        cout<<temp->info<<" ";
        temp=temp->next;
        /* code */
    }
    cout<<endl;
    
}
template <class Type>
doublyIterator<Type> &doublyLinkList<Type>::end()
{
}
template <class Type>
doublyIterator<Type> &doublyLinkList<Type>::begin()
{
    doublyIterator<Type> temp(first);
    return temp;
}
template <class Type>
Type doublyLinkList<Type>::back()
{
    return last->info;
}
template <class Type>
Type doublyLinkList<Type>::front()
{
    return first->info;
}
template <class Type>
bool doublyLinkList<Type>::isEmpty()
{
    return (first == NULL);
}
template <class Type>
void doublyLinkList<Type>::copy(doublyLinkList<Type> &otherList)
{
    node<Type> *newNode;
    node<Type> *current;
    if (first != NULL)
    {
        destroyList();
    }
    if (otherList.first == NULL)
    {
        first = 0;
        last = 0;
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
void doublyLinkList<Type>::destroyList()
{
    node<Type> *current;
    while (first != NULL)
    {
        current = first;
        first = first->next;
        delete current;
        /* code */
    }
    last = 0;
    len = 0;
}
template <class Type>
doublyLinkList<Type>::doublyLinkList(doublyLinkList<Type> &otherList)
{
    if (first == NULL)
    {
        this->first = 0;
        this->last = 0;
        this->len = 0;
    }
    else
    {
        destroyList();
        copy(otherList);
    }
}
template <class Type>
doublyLinkList<Type>::doublyLinkList()
{
    this->len = 0;
    first = 0;
    last = 0;
}
template <class Type>
doublyLinkList<Type>::~doublyLinkList()
{
}
#endif
