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
vector<int> prefixSum(vector<int>arr)
{
    int n=arr.size();
    vector<int>ans(n);
    ans[0]=arr[0];
    for(int i=1;i<n;i++)
    {
        ans[i]=arr[i-1]+arr[i];
    }
    return ans;
}

void print(vector<int>arr)
{
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main() {
    vector<int>arr={1,2,3,4,5};
    vector<int>ans=prefixSum(arr);
    print(ans);
    return 0;
}