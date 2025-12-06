#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v;
    cout << v.capacity();
    v.push_back(1);
    v.push_back(2);
    cout << endl;
    cout << v.capacity();
    v.push_back(34);
    cout << endl;
    cout << v.capacity();
    v.push_back(34);
    cout << endl;
    v.push_back(34);
    cout << v.capacity();
    cout << v[4] << endl;
    cout << endl;
    cout << endl;
    cout<<v.front()<<endl;
    cout<<v.back()<<endl;
    cout<<v.at(3)<<endl;
    cout<<v.size()<<endl;


    v.pop_back();
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<"\t";
    }
    for(int x:v)
    {
        cout<<"\n"<<x<<endl;
    }
}