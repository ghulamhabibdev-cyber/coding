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
bool LinearSearch(vector<int> arr, int target, int index)
{
    if (index >= arr.size())
    {
        return false;
    }
    if (arr[index] == target)
    {
        return true;
    }
    bool ans = LinearSearch(arr, target, index + 1);
    return ans;
}
int main()
{
    vector<int> arr = {1, 32, 6, 434, 45, 34, 5, 3, 70, 7};
    bool success = LinearSearch(arr, 700, 0);
    if (success)
    {
        cout << "Exist in array" << endl;
    }
    else
    {
        cout << "Does Not Exist" << endl;
    }

    return 0;
}