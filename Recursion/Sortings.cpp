#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits>
#include <list>
using namespace std;

class A
{
};
void merge(vector<int> &arr, int st, int mid, int end)
{
    int left = st;
    int right = mid + 1;
    vector<int> temp;
    while (left <= mid && right <= end)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= end)
    {
        temp.push_back(arr[right]);
        right++;
    }
    int index = st;
    for (int i = 0; i < temp.size(); i++)
    {
        arr[index] = temp[i];
        index++;
    }
}
void helper(vector<int> &arr, int st, int end)
{
    if (st >= end)
    {
        return;
    }
    int mid = st + (end - st) / 2;
    helper(arr, st, mid);
    helper(arr, mid + 1, end);
    merge(arr, st, mid, end);
}
void mergeSort(vector<int> &arr)
{
    int n = arr.size();
    int st = 0;
    int end = n - 1;
    helper(arr, st, end);
}
void print(vector<int> &arr)
{
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
}
int partition(vector<int> &arr, int st, int end)
{
    int pos = st;
    for (int i = st; i <= end; i++)
    {
        if (arr[i] <= arr[end])
        {
            swap(arr[st], arr[i]);
            pos++;
        }
    }
    return pos - 1;
}
void quickSortHelper(vector<int> &arr, int st, int end)
{
    if (st >= end)
    {
        return;
    }
    int pivot = partition(arr, st, end);
    quickSortHelper(arr, st, pivot-1);
    quickSortHelper(arr, pivot + 1, end);
}
void quickSort(vector<int> &arr)
{
    int n = arr.size();
    if (n <= 1)
    {
        return;
    }
    int st = 0;
    int end = n - 1;
    quickSortHelper(arr, st, end);
}
int main()
{
    vector<int> arr = {233435, 234, 4, 234, 23, 21, 35, 43, 50, 3, 4, 56, 23, 10, -1, 4, -4, 5, -30};
    // mergeSort(arr);
    quickSort(arr);
    print(arr);
    return 0;
}