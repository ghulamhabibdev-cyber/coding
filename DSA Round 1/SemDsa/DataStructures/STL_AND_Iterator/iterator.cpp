#include<bits/stdc++.h>
using namespace std;
class  a
{

};

int main()
{

    vector<int>v;
    vector<int>::iterator intVec=v.begin();
    for(int i=0;i<4;i++)
    {
        cout<<"Enter a Number \n";
        int num;
        cin>>num;
        v.push_back(num);
    }
    // for(intVec=v.begin();intVec!=v.end();intVec++)
    // {
    //     cout<<*intVec<<" ";
    // }
    // for(int i=0;i<v.size();i++)
    // {
    //     cout<<v[i]<<" ";
    // }
    // ostream_iterator<int>screen(cout," ,");
    // copy(v.begin(),v.end(),screen);

    return 0;
}
