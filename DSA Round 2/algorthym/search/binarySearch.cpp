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
int binarySearch(vector<int> arr, int key)
{
    int n = arr.size();
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        int num = arr[mid];
        if (key == num)
        {
            return mid;
        }
        if (key > num)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return -1;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int index = binarySearch(arr, 7);
    if (index != -1)
    {
        cout << arr[index] << endl;
    }
    else
    {
        cout << "NOT FOUND" << endl;
    }

    return 0;
}