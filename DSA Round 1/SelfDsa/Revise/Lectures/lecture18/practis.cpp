#include<bits/stdc++.h>
using namespace std;
void insertionSort(vector<int>&arr)
{
    int n=arr.size();
    for(int i=1;i<n;i++)
    {
        int j=i-1;
        int temp=arr[i];
        for(;j>=0;j--)
        {
            if(arr[j]>temp)
            {
                arr[j+1]=arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1]=temp;
    }
}
int main()
{

    vector<int> arr = {43, 45, 343, 4, 3, 32, 32, 12, 14, 15, 13, 23, 453, 56};
    insertionSort(arr);

    for (int n : arr)
        cout << n << " ";
    cout << endl;
    return 0;
}
