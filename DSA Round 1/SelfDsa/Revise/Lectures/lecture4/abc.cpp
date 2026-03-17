#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    char ch='A';
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<ch<<" ";
        }
        cout<<endl;
        ch++;
    }
    cout<<endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout <<char('A'+i-1) << " ";
        }
        cout << endl;
        // ch++;
    }
    return 0;
}
