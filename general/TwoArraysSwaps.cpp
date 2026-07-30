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
void sumArr(vector<int> &arr, long &sum)
{
    for (int n : arr)
    {
        sum += n;
    }
}
long maxSwapSum(int n, int k, vector<int> arrA, vector<int> arrB)
{
    sort(arrB.begin(), arrB.end());
    sort(arrA.begin(), arrA.end());
    int i = 0;
    int j = n - 1;
    long sum = 0;
    while (k--)
    {
        if (arrA[i] < arrB[j])
        {
            swap(arrA[i], arrB[j]);

            i++;
            j--;
        }
        else
        {
            i++;
        }
    }
    sumArr(arrA, sum);
    return sum;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arrA(n);
        vector<int> arrB(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arrA[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> arrB[i];
        }
        long sum = maxSwapSum(n, k, arrA, arrB);
        cout << sum << endl;
    }
    return 0;
}