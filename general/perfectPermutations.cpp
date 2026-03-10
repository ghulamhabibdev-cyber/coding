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
vector<int> findPerfectPermutation(int n)
{
    bool toggle = true;
    if (n%2==1)
    {
        return {-1};
    }
    vector<int> arr;
    for (int i = 1; i <= n; i++)
    {
        if (toggle)
        {
            arr.push_back(i + 1);
        }
        else
        {
            arr.push_back(i - 1);
        }
        toggle = !toggle;
    }
    // if(n%2==1)
    // {
    //     // swap(arr[arr.size() - 1] - 1, arr[arr.size() - 2]);
    //     arr[arr.size()-1]--;
    //     swap(arr[arr.size() - 1], arr[arr.size() - 2]);
    // }
    return arr;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr = findPerfectPermutation(n);
    for (int per : arr)
    {
        cout << per << " ";
    }

    return 0;
}