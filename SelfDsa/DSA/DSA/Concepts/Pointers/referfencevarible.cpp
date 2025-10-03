#include <bits/stdc++.h>
using namespace std;
void update(int n)
{
    n++;
}
void update2(int& n)
{
    n++;
}
//it bad pratise and not welcome because memory die after call

int& sum(int &n)
{
    int i=10;
    int &a=i;
    a=a+n;
    return a;
}
int main()
{
    // int i = 5;
    // int &j = i;
    // //   i++;
    // //   j++;
    // //   cout<<j<<i<<endl;
    // cout << "Before : " << i << endl;
    // update(i);
    // cout << "After : " << i << endl
    //      << endl;
    // cout << "Before : " << i << endl;
    // update2(i);
    // cout << "After : " << i << endl
    //      << endl;

    int num=5;
    int &value=num;
    int val=sum(value);
    cout<<val<<endl;
    val+=10;
    cout<<sum(value);
    return 0;
}