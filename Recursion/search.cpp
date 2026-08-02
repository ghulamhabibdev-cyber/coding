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
bool helper(vector<int> arr, int index, int target)
{
    if (index >= arr.size())
    {
        return false;
    }
    if (arr[index] == target)
    {
        return true;
    }
    return helper(arr, index + 1, target);
}
bool linearSearch(vector<int> arr, int target)
{
    return helper(arr, 0, target);
}
int bsHelper(vector<int> arr, int target, int st, int end)
{
    if (st > end)
    {
        return -1;
    }
    int mid = st + (end - st) / 2;
    if (arr[mid] == target)
    {
        return mid;
    }
    else if (arr[mid] < target)
    {
        return bsHelper(arr, target, mid + 1, end);
    }
    else
    {
        return bsHelper(arr, target, st, mid - 1);
    }
}
int binarySearhc(vector<int> arr, int target)
{
    return bsHelper( arr, target,0,arr.size()-1);
}
int main()
{
    vector<int> arr = {1, 2, 4323, 43, 2, 32, 3, 9, 10};
    if (linearSearch(arr, 100))
    {
        cout << "Present" << endl;
    }
    else
    {
        cout << "Not Present" << endl;
    }
    vector<int> sortedArr = {1, 2, 3, 4, 5, 45, 65, 776, 4000, 4500};
    int index = binarySearhc(sortedArr, 4000);
    if (index != -1)
    {
        cout << "Element Present " << endl;
    }
    else
    {
        cout << "Not Present" << endl;
    }
    return 0;
}