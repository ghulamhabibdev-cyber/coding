#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;

class A
{
};
string sumStringCountProblem(string str)
{
    int n = str.length();
    vector<char> dp;
    for (int i = 0; i < n; i++)
    {
        if (str[i] != '+')
        {
            dp.push_back(str[i]);
        
        }
    }
    sort(dp.begin(),dp.end());
    string ans="";
    for(int i=0;i<dp.size();i++)
    {
        ans+=dp[i];
        if(i!=dp.size()-1)
        {
            ans+='+';
        }
    }
    return ans;
}
int main()
{
    string exp;
    cin>>exp;
    cout<<sumStringCountProblem(exp);

    return 0;
}