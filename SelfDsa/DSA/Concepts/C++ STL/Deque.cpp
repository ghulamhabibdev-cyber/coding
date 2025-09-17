#include<iostream>
#include<deque>
using namespace std;
int main()
{
    deque<int> d;
    d.push_back(12);
    d.push_back(23);
    d.push_front(1);
    for(int x:d)
    {
        cout<<x<<"\t";
    }
    cout<<endl;
}