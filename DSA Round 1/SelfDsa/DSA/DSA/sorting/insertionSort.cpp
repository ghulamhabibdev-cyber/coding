#include <bits/stdc++.h>
using namespace std;
void inseretionSort(vector<int> &arr)
{
    int n=arr.size();
   for(int i=1;i<n;i++)
   {
    int j=i-1;
    int temp=arr[i];
    while (j>=0&&arr[j]>temp)
    {
        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1]=temp;
    

   }
}
void printVec(vector<int> arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
}
int main()
{

    vector<int> nums = {10000, 232, 3323, 4, 432};
    cout << "before sort" << endl;
    printVec(nums);
    cout << "after sort" << endl;
    inseretionSort(nums);
    printVec(nums);
    return 0;
}