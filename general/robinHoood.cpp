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
int noOfPeopleGetGold(vector<int> arr, int k)
{
    int n = arr.size();
    int sum = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= k)
        {
            sum += arr[i];
        }
        else if (arr[i] == 0 && sum == 0)
        {
            continue;
        }
        else if (arr[i] == 0 && sum != 0)
        {
            count++;
            sum--;
        }
    }
    return count;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int noOfpeople = noOfPeopleGetGold(arr, k);
        cout  << noOfpeople << endl;
    }

    return 0;
}