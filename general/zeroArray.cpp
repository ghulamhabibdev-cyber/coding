#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits>
#include <list>
using namespace std;

class A {
};
bool isPossible(vector<int>dp)
{
    sort(dp.begin(),dp.end());
    int ans=0;
    int n=dp.size();
    for(int i=0;i<n;i++)
    {
        ans^=dp[i];
    }
    if(ans==0)
    {
        return 1;
    }
    return 0;
}
int main() {
    int n;
    cin>>n;
    vector<int>dp(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>dp[i];
    }
    if(isPossible(dp))
    {
        cout<<"Yes \n";
    }
    else{
        cout<<"No \n";
    }
    
    return 0;
}