#include <bits/stdc++.h>
using namespace std;
// void sortStack(stack<int> st);
void sortedInsert(stack<int> &st, int num)
{
    if (st.empty() || ((!st.empty()) && st.top() < num))
    {
        st.push(num);
        return;
    }
    int n = st.top();
    st.pop();
    sortedInsert(st, num);
    st.push(n);
}
void sortStack(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }
    int num = st.top();
    st.pop();
    sortStack(st);
    sortedInsert(st, num);
}
void stackPrint(stack<int> st)
{
    while (!st.empty())
    {
        cout<<st.top()<< " ";
        st.pop();
        /* code */
    }
    
}
int main()
{
    stack<int> st;
    st.push(3);
    st.push(32);
    st.push(-3);
    st.push(43);
    st.push(53);
    st.push(43);
    st.push(432);
    sortStack(st);
    stackPrint(st);

    return 0;
}