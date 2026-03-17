#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> q;
    q.push(10);
    cout << q.front() << endl;

    q.push(23);
    q.push(32);
    q.push(20);
    cout << q.front() << endl;
    cout << "Size : " << q.size() << endl;
    ;
    cout << "Is empty : " << q.empty() << endl;

    return 0;
}