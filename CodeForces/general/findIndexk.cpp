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
int findBothEqualPart(vector<int> arr)
{
    int n = arr.size();
    int prevMul = 1;
    for (int i = 0; i < n; i++)
    {
        prevMul = prevMul * arr[i];
        int newMul = 1;
        for (int j = i + 1; j < n; j++)
        {
            newMul = newMul * arr[j];
        }
        if (prevMul == newMul)
        {
            return i + 1;
        }
        else if (prevMul > newMul)
        {
            return -1;
        }
    }
    return -1;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int k = findBothEqualPart(arr);
        cout << k << endl;
    }
    return 0;
}