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
int minFenceWidth(vector<int> arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    cout << "N : " << n << endl;
    int ans = 1;
    int counter = n - 1;
    for (int i = 0; i < n; i++)
    {
        int st = 0;

        int end = counter;
        cout << "counter : " << counter << endl;

        cout << "Else part is running " << endl;
        vector<int> curr;
        // curr.push_back(arr[counter]);
        while (st < end)
        {
            cout << "Inter While loop" << endl;
            if (arr[st] + arr[end] < arr[counter])
            {
                st++;
            }
            else if (arr[st] + arr[end] > counter)
            {
                end--;
            }
            else
            {
                curr.push_back(arr[st] + arr[end]);
                st++;
                end--;
            }
        }
        int len = curr.size();
        ans = max(len, ans);
        counter--;
    }
    cout << "Ans : " << ans << endl;
    return ans ;
}
int main()
{
    vector<int> arr = {1, 3, 2, 5, 7, 5, 4, 2, 1};
    vector<int> arr2 = {2, 3, 7};
    cout << minFenceWidth(arr2);
    return 0;
}