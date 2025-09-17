#include<iostream>
#include<vector>
using namespace std;
bool rotatedAndSortd(vector<int> arr)
{
    int count=0;
    for(int i=1;i<arr.size();i++)
    {
        if(arr[i-1]>arr[i])
        {
            count++;
        }
    }
    if(arr[arr.size()-1]>arr[0])
    {
        count++;
    }
    return count<=1;
}

int main()
{
    vector<int> arr={1,2,3,4};
    vector<int> v={3,4,5,1,2};
    cout<<rotatedAndSortd(arr);
    cout<<endl;
    cout<<rotatedAndSortd(v);

}