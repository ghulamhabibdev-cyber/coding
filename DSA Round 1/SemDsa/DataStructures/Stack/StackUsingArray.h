#ifndef H_stack
#define H_stack
#include <bits/stdc++.h>
#include <cassert>
using namespace std;
template <class Type>
class stackType
{
private:
    int maxSize;
    int stkTop;
    Type *list;

public:
    stackType(int MaxSize = 100);
    stackType(const stackType<Type> &otherStk);
    ~stackType();
    const stackType<Type> &operator=(const stackType<Type> &otherStk);
    void inilizeStack();
    bool isEmpty();
    bool isFullStack();
    void push(const Type &item);
    Type top();
    void pop();

private:
    void copyStack(const stackType<Type> &otherStk);
};
// implementinf destructor
template <class Type>
stackType<Type>::~stackType()
{
    delete[] list;
}
// implememting the copy stack
template <class Type>
void stackType<Type>::copyStack(const stackType<Type> &otherStk)
{
    delete[] list;
    maxSize = otherStk.maxSize;
    stkTop = otherStk.stkTop;
    list = new Type[maxSize];
    for (int i = 0; i < stkTop; i++)
    {
        list[i] = otherStk.list[i];
    }
}
// implementiion of stack
template <class Type>
stackType<Type>::stackType(int maxSize)
{
    if (maxSize <= 0)
    {
        cout << "Stack has size of 100\n";
        this->maxSize = 100;

    }
    else
    {
        this->maxSize = maxSize;

    }
    this->stkTop = 0;
    this->list = new Type[this->maxSize];
}
template <class Type>
const stackType<Type> &stackType<Type>::operator=(const stackType<Type> &otherStk)
{
    if (this != &otherStk) // avoid self-assignment
    {
        copyStack(otherStk);
    }
    return *this;
}
template <class Type>
stackType<Type>::stackType(const stackType<Type> &otherStk)
{
    copyStack(otherStk);
}
template <class Type>
void stackType<Type>::inilizeStack()
{
    stkTop = 0;
}
template <class Type>
bool stackType<Type>::isEmpty()
{
    return (stkTop == 0);
}
template <class Type>
bool stackType<Type>::isFullStack()
{
    return (stkTop == maxSize);
}
template <class Type>
void stackType<Type>::push(const Type &item)
{
    if (!isFullStack())
    {
        list[stkTop] = item;
        stkTop++;
    }
    else
    {
        cout << "Stack is full \n";
    }
}
template <class Type>
void stackType<Type>::pop()
{
    if (!isEmpty())
    {
        stkTop--;
    }
    else
    {
        cout << "Stack is Empty\n";
    }
}
template <class Type>
Type stackType<Type>::top()
{
    assert(stkTop != 0);
    return list[stkTop - 1];
}
#endif
