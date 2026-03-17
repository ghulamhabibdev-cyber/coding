#include <iostream>
using namespace std;
int main()
{
    // int i=0;
    // int n;
    // cout<<"Enter A No : "<<endl;
    // cin>>n;
    // for(;i<=n;i++)
    // {
    //     cout<<i<<endl;
    // }

    // int i = 0;
    // int n;
    // cout << "Enter A No : " << endl;
    // cin >> n;
    // for (;; i++)
    // {
    //     if (i <= n)
    //     {
    //         cout << i << endl;
    //     }
    //     else
    //     {
    //         break;
    //     }
    // }

    // int i = 0;
    // int n;
    // cout << "Enter A No : " << endl;
    // cin >> n;
    // for (;;)
    // {
    //     if (i <= n)
    //     {
    //         cout << i << endl;
    //         i++;
    //     }
    //     else
    //     {
    //         break;
    //     }
    // }

    // for(int a=0,b=0;a<=4&&b<=4;a++,b++)
    // {
    //     cout<<" a : "<<a<<endl;
    //     cout<<" b : "<<b<<endl;
    // }

    //   for(int a=0,b=1;a<=4||b<=10;a++,b++)
    // {
    //     cout<<" a : "<<a<<endl;
    //     cout<<" b : "<<b<<endl;
    // // }
    // for(int i=0;i<=3;i++)
    // {
    //     cout<<"Hello";
    //     cout<<" HI "<<endl;
    //     continue;
    //     cout<<"good ";
    // }

    //-->>>>for loop order Exact Order of Steps:
    // 1 > Initialization → (only once)
    //         2 > Condition Check
    //     3 > Body Execution
    //     4 > Increment / Update
    //             5 >
    //     Go back to Step 2(condition)

    //      for (int i = 0; i <= 5; i++)
    // {
    //     cout << "I : " << i << endl;
    //     i++;
    // }
    // for(int i=0;i<=5;i--)
    // {
    //     cout<<i<<endl;
    //     i++;
    // }

    // for(int i=0;i<=15;i+=2)
    // {
    //     cout<<i<<endl;
    //     if(i&2)
    //     {
    //         continue;
    //     }
    //     i++;
    // }
    for (int i = 0; i < 5; i++)
    {
        for (int j = i; j <= 5; j++)
        {
            if (i + j == 10)
            {
                cout << "Brake";
                cout<<i<<endl;
                cout<<"Print test "<<endl;
                break;
            }
            cout << "j " << j << endl;
        }
    }
}