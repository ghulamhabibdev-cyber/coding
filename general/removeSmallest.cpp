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
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        vector<int> arr;
        int count;
        cin>>count;
        for (int j = 0; j < count; j++)
        {
            int number;
            cin >> number;
            arr.push_back(number);
        }
        int len = arr.size();
        if (len == 1)
        {
            cout << "Yes" << endl;
            continue;
        }
        bool flag = true;
        ;
        sort(arr.begin(), arr.end());
        for (int k = 0; k < len-1; k++)
        {
            if (abs(arr[k] - arr[k + 1]) <= 1)
            {

                continue;
            }
            else
            {
                flag = false;
                cout << "No" << endl;
                break;
            }
        }
        if (flag)
        {
            cout << "Yes" << endl;
        }
    }
    return 0;
}