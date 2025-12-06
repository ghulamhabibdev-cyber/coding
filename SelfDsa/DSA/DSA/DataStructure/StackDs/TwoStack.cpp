#include <bits/stdc++.h>
using namespace std;
class TwoStack
{
public:
    int *arr;
    int size;
    int top1;
    int top2;
    TwoStack(int size)
    {
        this->size = size;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }
    void push1(int element)
    {
        if (top2 - top1 > 1)
        {
            top1++;
            arr[top1] = element;
        }
        else
        {
            cout << "Stack Overflow \n";
        }
    }
    void push2(int element)
    {
        if (top2 - top1 > 1)
        {
            top2--;
            arr[top2] = element;
        }
        else
        {
            cout << "Stack Overflow \n";
        }
    }
    int pop1()
    {
        if (top1 >= 0)
        {

            int ans = arr[top1];
            top1--;
            return ans;
        }
        else
        {
            return -1;
        }
    }
    int pop2()
    {
        if (top2 < size)
        {

            int ans = arr[top1];
            top2++;
            return ans;
        }
        else
        {
            return -1;
        }
    }
    int peek1()
    {
        if (top1 >= 0 && top1 < size)
        {
            return arr[top1];
        }
        else
        {
            cout << "Stack is Empty\n";
            return -1;
        }
    }
    int peek2()
    {
        if (top2 < size && top1 >= 0)
        {
            return arr[top2];
        }
        else
        {

            cout << "Stack is Empty\n";
            return -1;
        }
    }
};
int main()
{
    TwoStack st(5);
    st.push1(1);
    st.push1(4);
    st.push2(4);
    st.push2(10);
    cout << "st pekk2 : " << st.peek2() << endl;
    cout << st.peek1();
    return 0;
}