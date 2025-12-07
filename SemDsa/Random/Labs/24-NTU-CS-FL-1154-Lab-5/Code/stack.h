// exerecise 1
#ifndef H_stack
#define H_stack
#include <iostream>
using namespace std;
const int MaxSize = 100;
class stack
{
    int *arr;
    int count;
    int stktop;

public:
    stack();
    ~stack();
    bool isEmpty();
    bool isFull();
    int size();
    void push(int);
    void pop();
    void display();
    int top();
};
int stack::size()
{
    return stktop;
}
void stack::display()
{
    for (int i=stktop-1;i>=0;i--)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int stack::top()
{
    if (stktop != 0)
    {
        return arr[stktop - 1];
    }
    return -1;
}
// int stack::size()
// {
//     return count;
// }
bool stack::isFull()
{
    return (count == MaxSize);
}
bool stack::isEmpty()
{
    return (count == 0);
}
void stack::pop()
{
    if (!isEmpty())
    {
        stktop--;
        count--;
    }
    else
    {
        cout << "stack Is empty \n";
    }
}
void stack::push(int val)
{
    if (!isFull())
    {
        arr[stktop] = val;
        stktop++;
        count++;
    }
    else
    {
        cout << "Stack is Full \n";
    }
}
stack::stack()
{
    count = 0;
    stktop = 0;
    arr = new int[MaxSize];
}
stack::~stack()
{
    delete[] arr;
}

#endif
