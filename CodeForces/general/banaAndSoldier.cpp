#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits>
#include <list>
using namespace std;

class A
{
};
int howMuchBorrowAmount(int k, int n, int w)
{
    int totalAmount = 0;
    for (int i = 1; i <= w; i++)
    {
        totalAmount += i * k;
    }
    int borrow = totalAmount - n;
    if (borrow > 0)
    {
        return borrow;
    }
    return 0;
}
int main()
{
    int k,n,w;
    cin>>k>>n>>w;
    int ans=howMuchBorrowAmount(k,n,w);
    cout<<ans;

    return 0;
}