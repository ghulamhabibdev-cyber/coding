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
bool linearSearch(vector<int> arr, int i, int key)
{
    if (i >= arr.size())
    {
        return false;
    }
    if (arr[i] == key)
    {
        return true;
    }
    i++;
    return linearSearch(arr, i, key);
}
int main()
{
    // find a number in array using recursion
    int n;
    cout << "Enter Size of array : \n";
    cin >> n;
    int key;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {

        cin >> arr[i];
    }
    cout << "Enter Key to Search : " << endl;
    cin >> key;

    bool yes = linearSearch(arr, 0, key);
    if (yes)
    {
        cout << "Key : " << key << " Present in Array" << endl;
    }
    else
    {
        cout << "Key : " << key << " Absent in Array" << endl;
    }
    return 0;
}