#include<bits/stdc++.h>
using namespace std;
class  a
{

};

int main()
{
    vector<int>v;
    
    for(int i=0;i<10;i++)
    {
        int num;
        cout<<"Enter a Number \n";
        cin>>num;
        v.push_back(num);
    }
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<endl;
    }


    return 0;
}
