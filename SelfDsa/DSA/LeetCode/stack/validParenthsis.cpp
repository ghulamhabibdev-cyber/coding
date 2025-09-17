#include <bits/stdc++.h>
using namespace std;
bool matches(char top,char ch)
{
    if(ch==')'&& top=='('||ch=='}'&&top=='{'||ch==']'&&top=='[')
    {
        return true;
    }
    return false;
}
bool isValidParenthsis(string expression)
{
    stack<char> s;
    for(int i=0;i<expression.length();i++)
    {
        char ch=expression[i];
        if(ch=='('||ch=='{'||ch=='[')
        {
            s.push(ch);
        }
        else
        {
            if(!s.empty())
            {
                char top=s.top();
                if(matches(top,ch))
                {
                    s.pop();
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
    if(s.empty()){
        return true;
    }
    else{
        return false;
    }
}
int main()
{
    string str="[()]";
    cout<<isValidParenthsis(str);
    return 0;
}