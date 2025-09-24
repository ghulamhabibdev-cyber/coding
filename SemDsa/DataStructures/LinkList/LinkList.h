#ifndef H_linkList
#define H_linkList
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
    void length();
    void destroyList();
    Type front();
    Type back();
    // must be implemented in derived classed
    virtual bool search(const Type &item) = 0;
    virtual void insertLast(const Type &item) = 0;
    virtual void insertLast(const Type &item) = 0;
    virtual void deleteNode(const Type &item) = 0;
    // for itereator
    linkList<Type> begin();
    linkList<Type> end();
    linkList();
    linkList(const linkList<Type> &otherList);
    ~linkList();

protected:
private:
    void copyList(const linkList<Type> &otherList);
};
template <class Type>
class UnorederedLinkList : punlic linkList<Type>
{
};
template <class Type>
class orederedLinkList : punlic linkList<Type>
{
};

#endif