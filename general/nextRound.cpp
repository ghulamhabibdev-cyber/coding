#include <iostream>
#include <vector>
using namespace std;
int totalPass(vector<int>arr,int k)
{
     int kthScore=arr[k-1];
     int count=0;
     int n=arr.size();

     for(int i=0;i<n;i++)
     {
        if(arr[i]>=kthScore&&arr[i]>0)
        {
            count++;
        }
     }
     return count;
}
int main() {
    int n;
    cin>>n;
    int k;
    cin>>k;
    int ans=0;
    vector<int>vec;
    for(int i=0;i<n;i++)
    {
        int num;
        cin>>num;
        vec.push_back(num);

    }
    cout<<totalPass(vec,k);
    return 0;
}