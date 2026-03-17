#include <bits/stdc++.h>
using namespace std;
int findMinimumCost(string exp)
{
    if(exp.length()%2==1)
    {
        return -1;
    }
    stack<char> st;
    for(int i=0;i<exp.length();i++)
    {
        char ch=exp[i];
        if(ch=='{')
        {
                    st.push(ch);
        }
        else{
            if(!st.empty()&&st.top()=='{')
            {
                st.pop();
            }
            else{
                st.push(ch);
            }
        }
    }
    int a=0;
    int b=0;
    while (!st.empty())
    {
        if(st.top()=='{')
        {
            b++;
        }
        else{
            a++;
        }
        st.pop();
        /* code */
    }
    int ans=((a+1)/2)+((b+1)/2);
    return ans;
    
}
int main()
{
    string exp="{}{}}}}}";
    cout<<findMinimumCost(exp);
    
    return 0;
}