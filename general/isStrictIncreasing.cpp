#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits>
#include <list>
using namespace std;

class A {
};
bool isStrictIncreasing(vector<int>arr)
{
    sort(arr.begin(),arr.end());
    int n=arr.size();
    for(int i=0;i<n-1;i++)
    {
        if(arr[i]==arr[i+1])
        {
            return false;
        }
    }
    return true;
}
int main() {
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int size;
        cin>>size;
        vector<int>arr(size);
        for(int j=0;j<size;j++)
        {
            cin>>arr[j];
        }
        if(isStrictIncreasing(arr))
        {
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}