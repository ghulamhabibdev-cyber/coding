#include <bits/stdc++.h>
using namespace std;
void solve(stack<int> &st, int count, int n)
{
    if (count == n / 2)
    {
        st.pop();
        return;
    }
    int num = st.top();
    st.pop();
    solve(st, count + 1, n);
    st.push(num);
}
void deleteMiddle(stack<int> &st, int n)
{
    int count = 0;
    solve(st, count, n);
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
    st.push(1);
    st.push(3);
    st.push(1);
    deleteMiddle(st,3);
    stackPrint(st);

    return 0;
}