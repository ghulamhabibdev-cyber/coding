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
bool makeItBeautiful(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    int arrSize = arr.size();
    if (arrSize == 0 || arr[0] == arr[arrSize - 1])
    {
        return false;
    }
    return true;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int arrSize;
        cin >> arrSize;
        vector<int> arr(arrSize);
        for (int index = 0; index < arrSize; index += 1)
        {
            cin >> arr[index];
        }
        bool makeBeautiful = makeItBeautiful(arr);
        if (makeBeautiful)
        {
            cout << "YES" << endl;
            cout << arr[arrSize - 1] << " ";
            for (int i = 0; i < arrSize - 1; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}