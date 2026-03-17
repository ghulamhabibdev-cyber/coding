#include <bits/stdc++.h>
using namespace std;

int main()
{ string name ;
    cout<<"Enter Your Name :\n";
    getline(cin,name);
    stack<char> strName;
    for(int i=0;i<name.length();i++)
    {
        char chr=name[i];
        strName.push(chr);
    }
    string ans="";
    while (!strName.empty())
    {
        char chr=strName.top();
        ans.push_back(chr);
        strName.pop();
        /* code */
    }
    cout <<  ans << endl;
    
    
    return 0;
}