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
    vector<int> temp;
    int left = st;
    int right = mid + 1;

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
        arr[index++] = temp[i];
    }
}
void mergeSort(vector<int> &arr, int st, int end)
{
    if (st >= end)
    {
        return;
    }
    int mid = st + (end - st) / 2;
    mergeSort(arr, st, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, st, mid, end);
}
template <typename T>
void Print(vector<T> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    vector<int> arr = {32, 1, 23, 34, 232, 234, 32, 3, 2, 1, 0, -1, 23};
    mergeSort(arr, 0, arr.size() - 1);
    Print(arr);
    return 0;
}