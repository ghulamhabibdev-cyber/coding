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
bool backTrackMatchStickSqaure(vector<int> arr, int curr, int index, int count)
{
    if (index >= arr.size())
    {
        if (count == 4)
        {
            return true;
        }
        return false;
    }
    cout << "curr : " << curr << endl;

    bool combine = backTrackMatchStickSqaure(arr, curr + arr[index], index + 1, count);
    bool use = false;
    if (curr == arr[index])
    {
        use = backTrackMatchStickSqaure(arr, arr[index], index + 1, count + 1);
        return combine || use;
    }
    else
    {
        return combine || use;
    }
}
int main()
{
    vector<int> arr = {1, 1, 2, 2, 2};
    bool ans = backTrackMatchStickSqaure(arr, arr[0], 1, 0);
    if (ans)
    {
        cout << "Found" << endl;
    }
    else
    {
        cout << "No " << endl;
    }
    return 0;
}