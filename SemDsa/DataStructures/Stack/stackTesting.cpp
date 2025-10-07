#include <bits/stdc++.h>
// #include "StackUsingArray.h"
#include "stackUsinLinkList.h"
using namespace std;

int main()
{
    // stackType<int> st(5);
    // cout << st.isEmpty() << endl;
    // cout << st.isFullStack() << endl;
    // st.push(10);
    // st.push(20);
    // st.push(30);
    // st.push(40);
    // st.push(50);
    // // st.push(30);
    // cout << st.isEmpty() << endl;
    // cout << st.isFullStack() << endl;
    // while (!st.isEmpty())
    // {
    //     cout << st.top() << " ";
    //     st.pop();
    // }
    // cout<<endl;
    // st.push(10);
    // st.push(20);
    // st.push(30);
    // st.push(40);
    // st.push(50);
    // st.pop();
    // st.pop();
    // st.push(120);
    // st.push(30);
    // while (!st.isEmpty())
    // {
    //     cout << st.top() << " ";
    //     st.pop();
    // }
    // cout << endl;
    linkyStack<int> stl;
    // stl.inilizeStack();
    cout << stl.isEmpty() << endl;
    cout << stl.isFull() << endl;
    stl.push(12);
    stl.push(14);
    stl.push(12);
    stl.push(14);
    stl.push(12);
    stl.push(14);
    cout << stl.isEmpty() << endl;
    cout << stl.isFull() << endl;
    cout << stl.length() << endl;
    stl.pop();
    cout << stl.length() << endl;
    while (!stl.isEmpty())
    {
        cout << stl.top() << " ";
        stl.pop();
    }
    cout << endl;
    stl.push(12);
    stl.push(14);
    stl.push(12);
    stl.push(14);
    stl.push(12);
    stl.push(14);
    while (!stl.isEmpty())
    {
        cout << stl.top() << " ";
        stl.pop();
    }
    cout << endl;
    return 0;
}
