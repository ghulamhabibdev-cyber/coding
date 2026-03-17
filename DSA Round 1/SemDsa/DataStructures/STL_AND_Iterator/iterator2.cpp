#include<bits/stdc++.h>
using namespace std;
class  a
{

};

int main()
{
    vector<int>v;
    for(int i=0;i<3;i++)
    {
        int n;
        cout<<"enter the value \n";
        cin>>n;
        v.push_back(n);
    }
    vector<int>::iterator intvec=v.begin();
    cout<<"print \n";
    for(;intvec!=v.end();intvec++)
    {
        cout<<*intvec<<endl;
    }
    copy(v.rbegin(),v.rend(),ostream_iterator<int>(cout," ")); 

    return 0;
}
