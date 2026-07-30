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
int maxLengthOfIncreasingSubArray(vector<int> arr)
{
    int n = arr.size();
    int prev = 1;
    int curr = 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] < arr[i + 1])
        {
            curr++;
        }
        else
        {
            if (curr > prev)
            {
                prev = max(prev, curr);
                curr = 1;
            }
            else{
                curr=1;
            }
        }
    }

    prev = max(curr, prev);
    
    return prev;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int subLen = maxLengthOfIncreasingSubArray(arr);
    cout << subLen << endl;
    return 0;
}