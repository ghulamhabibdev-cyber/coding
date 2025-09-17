#include <bits/stdc++.h>
using namespace std;
bool knows(vector<vector<int>> &m, int a, int b, int n)
{
    if (m[a][b] == 1)
    {
        return true;
    }
    return false;
}
int celebrityProblem(vector<vector<int>> &cele, int n)
{
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        st.push(i);
    }
    while (st.size() != 1)
    {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();
        if (knows(cele, a, b, n))
        {
            st.push(b);
        }
        else
        {
            st.push(a);
        }
    }
    int candiate = st.top();
    bool rowCheck = false;
    int zeroCount = 0;
    int oneCount = 0;

    for (int i = 0; i < n; i++)
    {
        if (cele[candiate][i] == 0)
        {
            zeroCount++;
        }
    }
    if (zeroCount == n)
    {
        rowCheck = true;
    }
    bool colCheck = false;
    
    for (int i = 0; i < n; i++)
    {
        if (cele[i][candiate] == 1)
        {
            oneCount++;
        }
    }
    if (oneCount == n - 1)
    {
        colCheck = true;
    }
    if (rowCheck == true && colCheck == true)
    {
        return candiate;
    }
    return -1;
}
int main()
{
    vector<vector<int>> m(3);
    m[0].push_back(0);
    m[0].push_back(1);
    m[0].push_back(0);
    m[1].push_back(0);
    m[1].push_back(0);
    m[1].push_back(0);
    m[2].push_back(0);
    m[2].push_back(1);
    m[2].push_back(0);
    cout<<celebrityProblem(m,3);
    

    return 0;
}