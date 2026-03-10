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
bool getOddSumOfArray(vector<int> arr)
{
    int evenCount = 0;
    int oddCount = 0;
    for (int n : arr)
    {
        if (n % 2 == 0)
        {
            evenCount++;
        }
        else
        {
            oddCount++;
        }
    }

    if (oddCount == 0)
    {
        return false;
    }
    if (evenCount == 0 && oddCount % 2 == 0)
    {
        return false;
    }
    return true;
}
int main()
{
    int tests;
    cin >> tests;
    while (tests--)
    {
        int sizeOfArray;
        cin >> sizeOfArray;
        vector<int> arr(sizeOfArray);
        for (int index = 0; index < sizeOfArray; index++)
        {
            cin >> arr[index];
        }
        bool oddSum = getOddSumOfArray(arr);
        if (oddSum)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}