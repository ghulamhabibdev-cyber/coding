#include <bits/stdc++.h>
using namespace std;
string firstNorepeating(string A)
{
    unordered_map<char,int> count;
    queue<int > q;
    string ans="";
    for(int i=0;i<A.length();i++)
    {
        char ch=A[i];
        count[ch]++;
        q.push(ch);
        while (!q.empty())
        {
            if(count[ch]>1){
                q.pop();
            }
            else{
                ans.push_back(q.front());
                break;
            }
            /* code */
        }
        if(q.empty())
        {
            ans.push_back('#');
        }

    }
    return ans;
}
int main()
{
    string a="aaabbc";
    cout<<firstNorepeating(a)<<endl;
    
    return 0;
}