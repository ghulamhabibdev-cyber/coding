#include <bits/stdc++.h>
using namespace std;
class myStack
{
public:
    int size;
    int top;
    int *arr;
    int min;
    myStack(int n)
    {
        size = n;
        top = -1;
        arr = new int[size];
        min = INT_MAX;
    }
    void push(int x)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = x;
            if (x < min)
            {
                min = x;
            }
            return;
        }
        cout << "Stack is Full\n";
    }
    int getMin()
    {
        if (top >= 0)
        {
            return min;
        }
        return -1;
    }
    int peek()
    {
        return arr[top];
    }
};
int main()
{
    myStack st(2);
    st.push(1);
    st.push(-10);
    st.push(4);
    cout<<st.getMin()<<endl;
    cout<<st.peek();
    // st.push(4);
    return 0;
}