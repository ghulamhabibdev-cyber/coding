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
void waysToSum(int &count, vector<int> &arr, int sum, int t, int index)
{
    if (sum == t)
    {
        count++;
        return;
    }
    if (sum > t || index >= arr.size())
    {
        return;
    }
    sum += arr[index];
    waysToSum(count, arr,  sum, t, index);
    sum -= arr[index];
    waysToSum(count, arr,sum, t, index + 1);
}
int main()
{
    vector<int> arr = {1, 5, 6};
    int count = 0;
    waysToSum(count, arr, 0, 7, 0);
    cout << "Ways : " << count << endl;
}