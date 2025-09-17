#include <bits/stdc++.h>
using namespace std;
void revQue(queue<int> &q)
{
    stack<int> s;
    while (!q.empty())
    {
        int ele = q.front();
        q.pop();
        s.push(ele);
    }
    while (!s.empty())
    {
        int ele = s.top();
        s.pop();
        q.push(ele); /* code */
    }
}
int main()
{
    queue<int> q;
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    revQue(q);
    while (!q.empty())
    {
        int ele=q.front();
        cout<< ele<< " ";
        q.pop();
        /* code */
    }
    cout<<endl;
    

    return 0;
}