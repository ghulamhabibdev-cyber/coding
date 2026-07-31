#include <bits/stdc++.h>
using namespace std;
// stack usuing arr
class Stack
{
public:
    int top;
    int *arr;
    int size;
    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    void push(int element)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = element;
        }
        else
        {
            cout << "Stack overflow\n";
        }
    }
    void pop()
    {
        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << "Stack underflow ";
        }
    }
    int peek()
    {
        if (top >= 0 && top < size)
        {
            return arr[top];
        }
        else
        {
            cout << "Stack is empty\n";
            return -1;
        }
    }
    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        return false;
    }
};
int main()
{
    Stack st(5);
    st.push(4);
    st.push(3);
    st.push(2);
    cout << st.peek() << endl;
    st.pop();
    st.pop();
    st.pop();
    cout << st.peek() << endl;
    return 0;
}