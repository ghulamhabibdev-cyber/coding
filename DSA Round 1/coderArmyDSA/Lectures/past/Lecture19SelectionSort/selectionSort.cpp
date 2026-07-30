#include <iostream>
#include <vector>
using namespace std;
void selectionSortAscendingOrdeer(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n - 1; i++)
    {
        int index = i;
        bool isSorted = true;
        for (int j = i + 1; j < n; j++)
        {
            if (nums[j] < nums[index])
            {
                index = j;
                isSorted = false;
            }
        }
        swap(nums[i], nums[index]);
        // if (index==i)
        // {
        //     break;
        // }
    }
}
void selectionSortIndecendingOrder(vector<int>&nums)
{
    int n=nums.size();
    for(int i=0;i<n-1;i++)
    {
        int index=i;
        for(int j=i+1;j<n;j++)
        {
            if(nums[j]>nums[index])
            {
                index=j;
            }
        }
        swap(nums[i],nums[index]);
    }
}
void selectionSortOnCharaterDataType(vector<char>&nums)
{
    int n=nums.size();
    for(int i=0;i<n-1;i++)
    {
        int index=i;
        for(int j=i+1;j<n;j++)
        {
            if(nums[j]<nums[index])
            {
                index=j;
            }
        }
        swap(nums[i],nums[index]);
    }
}
void practiseSelectionSort(vector<int>&arr)
{
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
        int index=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[index])
            {
                index=j;
            }

        }
        swap(arr[i],arr[index]);
    }
}
template <typename t>
void printArray(vector<t> nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> v = {1, 323, 4354, 645, 464, 654535, 3453, 543, 45, 35, 3, 53, 5, 353, 5, 345, 3, 53};
    // selectionSortAscendingOrdeer(v);
    // selectionSortIndecendingOrder(v);
    // vector<char>ch={'a','z','b','f','x','r','c','A'};
    // selectionSortOnCharaterDataType(ch);
    practiseSelectionSort(v);
    printArray(v);
    // cout<<char(49+'0');
    return 0;
}