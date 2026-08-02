#include <bits/stdc++.h>
using namespace std;
string revStr(string str)
{
    if(str=="")
    {
        return "";
    }
     return revStr(str.substr(1))+str.at(0);
    
}
int main()
{
  cout<<revStr("ABC");
    return 0;
}
