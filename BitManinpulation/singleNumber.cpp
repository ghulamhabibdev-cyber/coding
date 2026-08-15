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
int FindSingelNumber(vector<int> arr)
{
    int ans = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        ans ^= arr[i];
    }
    return ans;
}
int main()
{
    vector<int> arr = {1, 2, 3, 2, 1};
    cout << FindSingelNumber(arr);
    return 0;
}