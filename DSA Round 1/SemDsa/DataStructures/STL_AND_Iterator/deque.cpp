#include<bits/stdc++.h>
using namespace std;
class  a
{

};

int main()
{
    deque<int>dq;
    dq.push_front(10);
    dq.push_front(101);
    dq.push_front(12);
    dq.push_front(143);
    dq.push_back(10);
    dq.push_back(10323);
    deque<int>::iterator dqIt;
    dqIt=dq.begin();
    cout<<endl;
    for(;dqIt!=dq.end();dqIt++)
    {
        cout<<*dqIt<<" ";
    }
    cout<<endl;
    // make copy data inot vecotr and printing using copy method and ostream_iterator
    vector<int>v(dq.size());
    cout<<endl;
    copy(dq.begin(),dq.end(),v.begin());
    cout<<endl;
    ostream_iterator<int> screen(cout, ", ");
    copy(v.begin(),v.end(),screen);





    return 0;
}
