#include <bits/stdc++.h>
using namespace std;
bool ispossible(vector<int> arr, int n, int m, int mid)
{
    int stdCount = 1;
    int pageSum = 0;
    for (int i = 0; i < n; i++)
    {
        if (pageSum + arr[i] <= mid)
        {
            pageSum += arr[i];
        }
        else
        {
            stdCount++;
            if (stdCount > m || arr[i] > mid)
            {
                return false;
            }

            pageSum = arr[i];
        }

        /* code */
    }
    return true;
}
int bookAll(vector<int> arr, int n, int m)
{
    int s = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int end = sum;
    int ans = -1;
    int mid = s + (end - s) / 2;
    while (s <= end)
    {
        if (ispossible(arr, n, m, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (end - s) / 2;
    }
    return ans;
}
int main()
{
    vector<int> arr = {10, 20, 30, 40};
    int n = 4;
    int m = 2;

    cout << "Minimum pages: " << bookAll(arr, n, m);
    return 0;

    return 0;
}
