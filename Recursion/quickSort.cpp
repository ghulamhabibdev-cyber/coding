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
int partition(vector<int> &arr, int st, int end)
{
    int pos = st;
    for (int i = st; i <= end; i++)
    {
        if (arr[i] <= arr[end])
        {
            swap(arr[i], arr[pos++]);
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
    quickSortHelper(arr, st, pivot - 1);
    quickSortHelper(arr, pivot + 1, end);
}
void quickSort(vector<int> &arr)
{
    int st = 0;
    int n = arr.size();
    int end = n - 1;
    quickSortHelper(arr, st, end);
}
void print(vector<int> arr)
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
    vector<int> arr = {12, 23, 2, 32, 3, 343, 3443, 3, 34343, 4343, 34, 23, 342, 44, 554, 3, 12, 13, 9, 85};
    quickSort(arr);
    print(arr);

    return 0;
}