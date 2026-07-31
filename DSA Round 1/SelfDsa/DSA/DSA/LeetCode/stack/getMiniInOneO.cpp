#include <bits/stdc++.h>
using namespace std;
class SpecialStack
{
    int mini;
    stack<int>s;

public:
    void push(int element)
    {
        if (s.empty())
        {
            s.push(element);
            mini=element;
            return;
        }
        
        if (element < mini)
        {
            int val = 2 * element - mini;
            s.push(val);
            mini = element;
        }
        else
        {
            s.push(element);
        }
    }
    int pop()
    {
        if (s.empty())
        {
            return -1;
        }
        int curr = s.top();
        if (curr > mini)
        {
            return curr;
        }
        else
        {
            int prevMini = mini;
            int val = 2 * mini - curr;
            mini = val;
            return prevMini;
        }
    }
    int getMin()
    {
        return mini;
    }
    int top()
    {
        if (s.empty())
        {
            return -1;
        }
        int curr = s.top();
        if (curr < mini)
        {
            return mini;
        }
        else
        {
            return curr;
        }
    }
    bool isEmpty()
    {
        return s.empty();
    }
};
int main()
{
    SpecialStack st;
    st.push(5);
    st.push(3);
    st.push(9);
    st.push(2);
    st.push(4);
    cout<<st.getMin();

    return 0;
}