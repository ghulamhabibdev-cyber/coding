#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<char('A'+j-1) << " ";
        }
        cout<<endl;
    }
    cout<<endl;

    for (int i = 1; i <= n; i++)
    {
        char ch = 'A';
        for (int j = 1; j <= n; j++)
        {
           cout<<ch<<" ";
           ch++;
        }
        cout << endl;
    }
    return 0;
}
