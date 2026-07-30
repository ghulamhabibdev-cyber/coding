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

class setOfStack
{
    int rows = 10;
    int cols;
    int **arr = new int *[rows];
    int *ary = new int[rows];
    int index;

public:
    setOfStack(int stackCount)
    {
        for (int i = 0; i < stackCount; i++)
        {
            arr[i] = new int[stackCount];
            cols = stackCount;
        }
        for (int i = 0; i < rows; i++)
        {
            ary[i] = 0;
        }
        index = -1;
    }
    void push(int data)
    {
        if (ary[index + 1] < rows && index < cols)
        {
            arr[ary[index + 1]][index + 1] = data;
            ary[index]++;
        }
        if (ary[index] == rows)
        {
            index++;
        }
        else
        {
            cout << "stacks OverFlow " << endl;
        }
    }
    void popAt(int stackNo)
    {
        if (index >= 0 && ary[stackNo - 1] >= 0)
        {
            ary[stackNo - 1]--;
        }
    }
    int peek(int stackNo)
    {
        if (index >= 0 && ary[stackNo - 1] >= 0)
        {
            return arr[ary[stackNo - 1]][stackNo - 1];
        }
        return -1;
    }
    void print()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    setOfStack st(4);
    st.push(10);
    st.push(20);
    st.push(10);
    st.push(20);
    cout << st.peek(1) << endl;
    st.print();

    return 0;
}