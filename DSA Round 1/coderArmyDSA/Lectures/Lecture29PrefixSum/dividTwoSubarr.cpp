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
bool divide(vector<int>arr)
{
    int n=arr.size();
    int maxi=INT_MIN,prefix=0,totalSum=0;
    for(int i:arr)
    {
        totalSum+=i;
    }
    for(int i=0;i<n;i++)
    {
        prefix+=arr[i];
        int ans=totalSum-prefix;
        if(ans==prefix)
        {
            return true;
        }

    }
    return false;
}
int main() {
    vector<int>arr={2,4,6,2,1,5,8,2};
    cout<<divide(arr);
    
    return 0;
}