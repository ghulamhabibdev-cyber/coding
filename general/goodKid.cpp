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

long long maxProduct(vector<int> arr)
{
    sort(arr.begin(), arr.end());
    long long product = 1;
    arr[0]++;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        product *= arr[i];
    }
    return product;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        vector<int> arr;
        int size;
        cin >> size;
        for (int i = 0; i < size; i++)
        {
            int num;
            cin >> num;
            arr.push_back(num);
        }
        long long product = maxProduct(arr);
        cout << product << endl;
    }
    return 0;
}