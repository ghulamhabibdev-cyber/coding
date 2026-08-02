#include<iostream>
#include<vector>
using namespace std;
void printArray(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<"\t";
    }
}
void printVector(vector<int> v)
{
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<"\t";
    }
}
void rotateArray(vector<int> nums,int k)
{
    vector<int> temp(nums.size());
    for(int i=0;i<nums.size();i++)
    {
        temp[(i+k)%nums.size()]=nums[i];
    }
    nums=temp;
    printVector(nums);
}
// void reverseArray(int arr[],int size)
// {
//     int start=0;
//     int end=size-1;
//     while (start<=end)
//     {
//         int temp=arr[end];
//         arr[end]=arr[start];
//         arr[start]=temp;
//         start++;
//         end--;
//     }
//     printArray(arr,size);
// }
int main()
{
    int arr[5]={1,2,4,5,6};
    vector<int> v={12,43,5,54};
    rotateArray(v,2);
    // reverseArray(arr,5);
}