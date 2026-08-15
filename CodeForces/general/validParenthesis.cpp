#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits>
#include <list>
using namespace std;

class A {
};
bool isValid(string str)
{
    string res="";
    for(char ch:str)
    {
        if(ch=='('||ch=='{'||ch=='[')
        {
            res+=ch;
        }
        else{
            if(res!="")
            {
                int n=res.length()-1;
                if(res[n]=='('&&ch==')')
                {
                    res.erase(n,1);
                }
               else if (res[n] == '{' && ch == '}')
                {
                    res.erase(n, 1);
                }
                else if (res[n] == '[' && ch == ']')
                {
                    res.erase(n, 1);
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
        
    }
    if (res != "")
    {
        return false;
    }
    return true;
}
int main() {
    string str="({}){";
    cout<<isValid(str)<<endl;
    return 0;
}