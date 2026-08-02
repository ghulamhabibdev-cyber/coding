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
long long sumArray(vector<int> arr, int i)
{
    if (i >= arr.size())
    {
        return 0;
    }
    return sumArray(arr, i += 1) + arr[i-1];
}
int main()
{
    int n;
    cout << "Please Enter Size of Array" << endl;
    cin >> n;
    vector<int> arr(n > 0 ? n : 5);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter A Number : " << endl;
        cin >> arr[i];
    }
    long long sum = sumArray(arr, 0);
    cout << sum << endl;
    return 0;
}