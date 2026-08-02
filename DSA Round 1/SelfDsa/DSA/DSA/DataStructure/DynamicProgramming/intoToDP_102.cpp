#include <bits/stdc++.h>
using namespace std;
class a
{
public:
};
int fib(int n, vector<int> &dp)
{
    if (n == 1 || n == 0)
    {
        return n;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
    return dp[n];
}
int main()
{
    int n;

    cout << "Enter a number : \n";
    cin >> n;
    vector<int> dp(n + 1, -1);
    
    for(int i=0;i<=n;i++)
    {
        if(i==0)
        {
            cout<<i<<" ";

        }
        else if(i==1)
        {
            cout<<i<<" ";
        }
        else{
            cout<<dp[i]<<" ";
        }
    }
    cout<<endl;

    return 0;
}