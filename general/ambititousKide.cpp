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
int findMin(vector<int> arr)
{
    int mini = abs(arr[0]);
    int sizeOfArray = arr.size();
    for (int i = 1; i < sizeOfArray; i++)
    {
        if (arr[i] == 0)
        {
            return 0;
        }
        if (abs(arr[i]) < mini)
        {
            mini = abs(arr[i]);
        }
    }
    return mini;
}
int stepToGetZeroByMultiplyAllElement(vector<int> arr)
{
    return findMin(arr);
}
int main()
{

    int sizeOfArray;
    cin >> sizeOfArray;
    vector<int> arr(sizeOfArray);
    for (int index = 0; index < sizeOfArray; index++)
    {
        cin >> arr[index];
    }
    int minStep = stepToGetZeroByMultiplyAllElement(arr);
    cout << minStep << endl;

    return 0;
}