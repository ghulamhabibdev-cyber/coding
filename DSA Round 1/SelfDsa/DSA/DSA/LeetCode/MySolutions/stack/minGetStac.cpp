#include <bits/stdc++.h>
using namespace std;
class MinStack
{
public:
    int min;
    int top;
    int size;
    int *arr;

    MinStack()
    {
        min = INT_MAX;
        size = 30000;
        arr = new int[size];
        top = -1;
    }

    void push(int val)
    {
        if (size - top >= 1)
        {
        }
    }

    void pop()
    {
    }

    int top()
    {
    }

    int getMin()
    {
    }
};
int main()
{

    return 0;
}