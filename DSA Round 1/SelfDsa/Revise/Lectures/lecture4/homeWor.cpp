#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter a number \n";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i - 1; j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= n - i + 1; j++)
        {
            cout << i << "";
        }
        cout << endl;
    }
    cout<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n-i;j++)
        {
            cout<<" ";
        }
        for(int j=1;j<=i;j++)
        {
            cout<<i<<"";
        }
        cout<<"\n";
    }
    cout<<endl<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i-1;j++)
        {
            cout<<" ";
        }
        for(int j=1;j<=n-i+1;j++)
        {
            cout<<j;
        }
        cout<<endl;
    }
    cout<<endl<<endl;
    int num = 1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n-i;j++)
        {
            cout<<" ";
        }

        for(int j=1;j<=i;j++)
        {
          cout<<num;
          num++;
        }
        cout<<endl;
    }
    return 0;
}
