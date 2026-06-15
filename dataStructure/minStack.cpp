#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits>
#include <list>
using namespace std;

class myStack
{
    int index;
    int n;
    int *arr;

public:
    myStack(int arrSize)
    {
        arr = new int[arrSize];
        index = -1;
        n = arrSize;
    }
    void push(int data)
    {
        if (index < n)
        {
            arr[index + 1] = data;
            index++;
        }
        else
        {
            cout << "Stack overflow" << endl;
        }
    }
    int peek()
    {
        if (index >= 0 && index - 1 < n)
        {
            return arr[index];
        }
        return INT_MIN;
    }
    void pop()
    {
        if (index >= 0)
        {
            index--;
        }
    }
    bool empty()
    {
        return index == -1;
    }
};

int main()
{
    myStack st(4);
    st.push(10);
    // st.push(20);
    // st.push(40);
    // st.push(30);
    // st.push(30);
    cout << st.peek() << endl;

    return 0;
}