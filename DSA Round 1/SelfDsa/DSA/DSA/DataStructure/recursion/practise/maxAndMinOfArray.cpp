#include <bits/stdc++.h>
using namespace std;
vector<int> maxOfArray(int *arr, int size)
{

    if(size==1)
    {
        return {arr[0],arr[0]};
    }
    vector<int>temp=maxOfArray(arr+1,size-1);
    int curmax=max(arr[0],temp[0]);
    int curmin=min(arr[0],temp[1]);
    return {curmax,curmin};
    ;
}
int main()
{
    vector<int> ans;
    int arr[4] = {1, 2, 4, 5};
    ans = maxOfArray(arr, 4);
    for (int v : ans)
    {
        cout << v << " ";
    }
    return 0;
}
