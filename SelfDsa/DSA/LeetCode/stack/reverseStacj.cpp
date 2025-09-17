#include <bits/stdc++.h>
using namespace std;
void solve(stack<int> &st, int num)
{
    if (st.empty())
    {
        st.push(num);
        return;
    }
    int top = st.top();
    st.pop();
    solve(st, num);
    st.push(top);
}
void insertAtBottom(stack<int> &st, int num)
{
    solve(st, num);
}
void reverse(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }
    int top = st.top();
    st.pop();
    reverse(st);
    insertAtBottom(st, top);
}
void stackPrint(stack<int> st)
{
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
        /* code */
    }
}
int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    // insertAtBottom(st, 5);
    // stackPrint(st);
    reverse(st);
    stackPrint(st);

    return 0;
}