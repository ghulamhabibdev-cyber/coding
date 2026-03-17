#ifndef H_linkListStack
#define H_linkListStack
#include <bits/stdc++.h>
#include <cassert>
using namespace std;
template <class Type>
class node
{
public:
    Type info;
    node<Type> *next;
    node(const Type &item);
    node();

};
template <class Type>
node<Type>::node(const Type &item)
{
    this->info = item;
    this->next = NULL;
}
template <class Type>
node<Type>::node()
{
    this->info = Type();
    this->next = NULL;
}

template <class Type>
class linkyStack
{
private:
    node<Type> *stkTop;
    int count;

private:
    void copyStack(const linkyStack<Type> &otherStk);

public:
    linkyStack();
    linkyStack(const linkyStack<Type> &otherStk);
    ~linkyStack();

public:
    const linkyStack<Type> &operator=(const linkyStack<Type> &otherStk);
    void inilizeStack();
    void push(const Type &item);
    Type top();
    void pop();
    int length();
    bool isEmpty();
    bool isFull();
};
// implemention of linkyStack
template <class Type>
linkyStack<Type>::linkyStack()
{
    this->stkTop = NULL;
    count = 0;
}
template <class Type>
linkyStack<Type>::linkyStack(const linkyStack<Type> &otherStk)
{
    stkTop = NULL;
    copyStack(otherStk);
}
template <class Type>
void linkyStack<Type>::copyStack(const linkyStack<Type> &otherStk)
{
    node<Type> *temp, *curr, *last;
    if (stkTop != NULL)
    {
        inilizeStack();
    }
    if (otherStk.stkTop == NULL)
    {
        this->stkTop = NULL;
        count = 0;
    }
    else
    {
        curr = otherStk.stkTop;
        this->stkTop = new node<Type>;
        this->stkTop->info = curr->info;
        last = this->stkTop;
        curr = curr->next;
        while (curr != NULL)
        {
            temp = new node<Type>;
            temp->info = curr->info;
            temp->next = NULL;
            last->next = temp;
            last = temp;
            curr = curr->next;
        }
        count = otherStk.count;
    }
}
template <class Type>
const linkyStack<Type> &linkyStack<Type>::operator=(const linkyStack<Type> &otherStk)
{
    if (this != &otherStk)
    {
        inilizeStack();
        copyStack(otherStk);
    }
    return *this;
}

template <class Type>
void linkyStack<Type>::inilizeStack()
{
    node<Type> *temp;
    while (stkTop != NULL)
    {
        temp = stkTop;
        stkTop = stkTop->next;
        delete temp;
    }
}
template <class Type>
linkyStack<Type>::~linkyStack()
{
    inilizeStack();
}
    template <class Type>
    void linkyStack<Type>::push(const Type &item)
{
    node<Type> *temp = new node<Type>(item);
    temp->next = stkTop;
    stkTop = temp;
    count++;
}
template <class Type>
void linkyStack<Type>::pop()
{
    if (stkTop != NULL)
    {
        node<Type> *temp = stkTop;
        stkTop = stkTop->next;
        delete temp;
        count--;
    }
    else
    {
        cout << "Cant delete from Empty stask \n";
    }
}
template <class Type>
int linkyStack<Type>::length()
{
    return count;
}
template <class Type>
Type linkyStack<Type>::top()
{
    assert(stkTop != NULL);
    return this->stkTop->info;
}
template <class Type>
bool linkyStack<Type>::isEmpty()
{
    return (stkTop == NULL);
}
template <class Type>
bool linkyStack<Type>::isFull()
{
    return false;
}
#endif
