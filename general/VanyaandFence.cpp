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
int minWidthOfRoad(vector<int>arr,int k)
{
    int bigThenRoad=0;
    int lessEqualRoad=0;
    int n=arr.size();

    for(int i=0;i<n;i++)
    {
        if(arr[i]>k)
        {
            bigThenRoad+=2;
        }
        else{
            lessEqualRoad++;
        }
    }
    return (bigThenRoad+lessEqualRoad);
}
int main() {
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int>arr;
    for(int i=0;i<n;i++)
    {
        int num;
        cin>>num;
        arr.push_back(num);
    }
    int ans=minWidthOfRoad(arr,k);
    cout<<ans<<endl;
    return 0;
}