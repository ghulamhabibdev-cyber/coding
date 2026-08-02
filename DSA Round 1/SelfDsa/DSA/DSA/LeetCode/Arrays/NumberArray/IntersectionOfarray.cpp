#include<iostream>
#include<vector>
using namespace std;
vector<int> Interseection(vector<int> &arr,int n,vector <int> &arr2,int m)
{
    vector<int>ans;
    int i=0,j=0;
    while (i<n&&j<m)
    {
        if(arr[i]==arr2[j])
        {
             ans.push_back(arr[i]);
            arr[j]=-1;
            i++;j++;
           
        }
        else if(arr[i]<arr2[j])
        {
            i++;
        }
        else{
            j++;
        }
    }
    return ans;

}
int main()
{
    vector<int> arr = {1, 2, 2, 2, 3, 4};
    vector<int> arr2 = {2, 3};
      vector<int> result = Interseection(arr, arr.size(), arr2, arr2.size());

    for (int x : result)
    {
        cout << x << " ";
    }
}
