#include <bits/stdc++.h>
using namespace std;
string reversStr(string str)
{
    if(str=="")
    {
        return "";
    }
    return reversStr(str.substr(1))+str.at(0);
}
int main()
{
  cout<<reversStr("hello");
  string name="ALi";
  char h=name.at(0);
  string b;
  b+=h;
  cout<<"\n"<<b;
    return 0;
}