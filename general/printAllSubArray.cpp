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

int main()
{
    vector<int> arr = {1, 3, 4, 5, 6};
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        cout << "{";
        for (int j = i; j < n; j++)
        {
            cout << arr[j] << " ";
        }
        cout << "}";
        cout << endl;
    }
    return 0;
}