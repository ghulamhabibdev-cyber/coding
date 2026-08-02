#include <bits/stdc++.h>
using namespace std;
//find frequeny of number
int maximumFrequency(vector<int> &arr,int n)
{
    unordered_map<int,int>count;
    for(int i=0;i<arr.size();i++)
    {
        count[arr[i]]++;
    }

    int maxi=INT_MIN;
    int ans=-1;
    for(auto i:count)
    {
        maxi=i.second;
        ans=i.second;
    }
    cout<<maxi<<endl;
    cout<<ans<<endl;
    return ans;
}
int maxFre(vector<int>arr)
{
    int maxFreq=0;
    int maxAns=0;
    unordered_map<int,int>count;
    for(int i=0;i<arr.size();i++)
{
    count[arr[i]]++;
    maxFreq=max(maxFreq,count[arr[i]]);

}
for(int i=0;i<arr.size();i++)
{
    if(maxFreq==count[arr[i]])
    {
        maxAns=arr[i];
    }
}
return maxAns;
}
int main()
{
    vector<int> v={1,4,2,3,2,42,1,23,1,1,1};
    cout<<"Max fre  : "<<maximumFrequency(v,2)<<endl;
    cout<<"Max fre  : "<<maxFre(v)<<endl;
    
    return 0;
}