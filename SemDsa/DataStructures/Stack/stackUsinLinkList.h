#ifndef H_stackLinkList
#define H_stackLinkList
#include <bits/stdc++.h>
#include <cassert>
using namespace std;
template <class Type>
class node
{
public:
    Type info;
    node<Type> *next;
    node(Type &item);
    node();
    ~node();
};
template <class Type>
node<Type>::node(Type &item)
{
    this->info = item;
    this->next = NULL;
}
template <class Type>
node<Type>::node()
{
    this->info = NULL;
    this->next = NULL;
}
template <class Type>
class linkyStack
{
private:
    node<Type> *stkTop;
    node<Type> *last;
    int count;

private:
    void copyStack(const linkyStack<Type> &otherStk);

public:
    linkyStack();
    ~linkyStack();

public:
    const linkyStack<Type> &operator=(const linkyStack<Type> &otherStk);
    void inilizeStack();
    void push();
    void top();
    void pop();
    bool isEmpty();
    bool isFull();
};
// implemention of linkyStack
#endif
