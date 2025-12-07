// Write a program to find and display the maximum and minimum elements of an array
#include <iostream>
using namespace std;
int findMinOfArray(int arr[], int size)
{
    int mini = INT_MAX;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < mini)
        {
            mini = arr[i];
        }
    }
    return mini;
}
int findMaxOfArray(int arr[], int size)
{
    int maxi = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > maxi)
        {
            maxi = arr[i];
        }
    }
    return maxi;
}
int main()
{
    const int size=5;
    int arr[size]={323,345,4654,-1,454};
    cout<<"============Max of Array=========\n";
    cout<<findMaxOfArray(arr,size)<<endl;
    cout<<"============Min of Array=========\n";
    cout<<findMinOfArray(arr,size)<<endl;

    return 0;
}
