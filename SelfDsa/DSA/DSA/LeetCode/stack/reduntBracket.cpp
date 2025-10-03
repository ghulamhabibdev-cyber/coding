#include <bits/stdc++.h>
using namespace std;
bool isRedundant(string exp)
{
    stack<char>st;
    for(int i=0;i<exp.length();i++)
    {
        char ch=exp[i];
        if(ch=='(' || ch=='+'||ch=='-'||ch=='*'|| ch=='/')
        {
            st.push(ch);

        }
        else{
            if(ch==')')
            {
                bool redendant=true;
                while (!st.empty()&&st.top()!='(')
                {
                    char top=st.top();
                    if( top=='+'||top=='-'||top=='*'|| top=='/')
                    {
                        redendant=false;

                    }
                    st.pop();
                    /* code */
                }
                if(redendant==true)
                {
                    return true;
                }
                st.pop();
            }
        }
    }
    return false;
}
int main()
{
    string st="(a+(a+b))";
    cout<<isRedundant(st);
    
    return 0;
}