#include <iostream>
#include <list>
using namespace std;
int main()
{
    list<int> l;
    l.push_back(2);
    l.push_front(3);
    // for (int i : l)
    // {
    //     cout << i << endl;
    // }
    // l.erase(l.begin());

    // for (int i : l)
    // {
    //     cout << i << endl;
    // }
    // l.push_front(3);
    // list<int> l2(l);
    // for (int i : l2)
    // {
    //     cout << i << endl;
    // }
    //size 5 all 100
    list<int> b(5,100);
    for(int i:b)
    {
        cout<<i<<"\t";
    }
    cout<<endl;
    // cout<<b[1]<<endl;
}