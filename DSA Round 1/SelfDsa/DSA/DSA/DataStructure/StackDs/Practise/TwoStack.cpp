#include <bits/stdc++.h>
using namespace std;
class TwoStack
{
public:
    int size;
    int *arr;
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
            cout << "Stack is Overflow \n";
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
            cout << "Stack is Overflow \n";
        }
    }
    void pop1()
    {
        if (top1 >= 0)
        {
            top1--;
        }
        else
        {
            cout << "Stack2 Underflow\n";
        }
    }
    void pop2()
    {
        if (top2 < size)
        {
            top2++;
        }
        else
        {
            cout << "Stack2 Underflow\n";
        }
    }
    int peek1()
    {
        if (top1 >= 0)
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
        if (top2 < size)
        {
            return arr[top2];
        }
        else
        {
            cout << "Stack is Empty\n";
            return -1;
        }
    }
    bool isEmptye()
    {
        if (top1 < 0 && top2 == size)
        {
            return true;
        }
        return false;
    }
    void display()
    {
        cout << "Stack 1 : ";
        if (top1 >= 0)
        {
            for (int i = top1; i >= 0; i--)
            {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
        cout << "Stack 2 : ";
        if (top2 < size)
        {
            for (int i = top2; i < size; i++)
            {
                cout << arr[i] << " ";
            }
        }
    }
};
int main()
{
    TwoStack ts(5);
    ts.push1(10);
    ts.push2(20);
    ts.push1(30);
    cout << "Top of Stack 1: " << ts.peek1() << endl;
    cout << "Top of Stack 2: " << ts.peek2() << endl;
    // ts.pop1();
    // ts.pop2();
    ts.display();
    return 0;
}