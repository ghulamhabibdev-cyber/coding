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
int minAmountToEqualize(int n)
{
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int number;
        cin >> number;
        arr.push_back(number);
    }
    sort(arr.begin(),arr.end());
    int size = arr.size() - 1;
    int maxAmount = arr[size];
    int minAmount = 0;

    for (int weliPer : arr)
    {
        int diff = maxAmount - weliPer;
  
        minAmount += diff;
    }
    return minAmount;
}
int main()
{
    int n;
    cin >> n;
    int minAmount = minAmountToEqualize(n);
    cout << minAmount << endl;

    return 0;
}