#include <bits/stdc++.h>
using namespace std;
queue<int> interLeaveaQues(queue<int> a)
{
    queue<int> newq;
    int half = a.size() / 2;
    for (int i = 0; i < half; i++)
    {
        int val = a.front();
        a.pop();
        newq.push(val);
    }
    //  for(int i=0;i<newq.size();i++)
    // {
    //     cout<<newq.front() << " ";
    //     newq.pop();
    // }
    // cout<<endl;

    while (!newq.empty())
    {
        int val = newq.front();
        newq.pop();
        a.push(val);
        val = a.front();
        a.pop();
        a.push(val);
        /* code */
    }
    return a;
}
queue<int> interLeavePartByStack(queue<int> a)
{
    int half = a.size() / 2;
    stack<int> s;
    for (int i = 0; i < half; i++)
    {
        int val = a.front();
        a.pop();
        s.push(val);
    }
    while (!s.empty())
    {
        int val = s.top();
        s.pop();
        a.push(val);
    }
    int i = half;
    while (i != 0)
    {
        int val = a.front();
        a.push(val);
        a.pop();
        i--;
        /* code */
    }
    for (int i = 0; i < half; i++)
    {
        int val = a.front();
        a.pop();
        s.push(val);
    }
    while (!s.empty())
    {
        int val=s.top();
        s.pop();
        a.push(val);
        val=a.front();
        a.push(val);
        a.pop();
    }
    return a;
}
int main()
{
    queue<int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
    int size = q.size();
    // q = interLeaveaQues(q);
    q=interLeavePartByStack(q);
    for (int i = 0; i < size; i++)
    {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}