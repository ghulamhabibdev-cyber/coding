#include <iostream>
#include <map>
using namespace std;
int main()
{
    map<int,string> m;
    m[1]="habib";
    m[3]="Ali";
    for(auto i:m)
    {
        cout<<i.first<<endl;
        cout<<i.second<<endl;
    }
    cout<<m.count(1)<<endl;
}