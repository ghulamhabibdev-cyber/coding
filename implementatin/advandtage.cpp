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
int findMax(vector<int> arr)
{
    int maxi = INT_MIN;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maxi)
        {
            maxi = arr[i];
        }
    }
    return maxi;
}
int findSecondLargest(vector<int> arr, int maxi)
{
    int secondLarget = maxi;
    int diff = maxi;

    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int currentDiff = abs(arr[i] - maxi);
        // cout << "I am current diff : " << currentDiff << endl;
        // cout << "Diff : " << diff << endl;
        if (currentDiff < diff && currentDiff != 0)
        {
            diff = currentDiff;
            // cout << "change diff : " << diff << endl;
            secondLarget = arr[i];
        }
    }
    return secondLarget;
}
vector<int> findAdvantageOverOther(vector<int> strengthArray)
{
    int maxi = findMax(strengthArray);
    int secondMaxi = findSecondLargest(strengthArray, maxi);
    // cout << "I am Maxi : " << maxi << endl;
    // cout << "I am Second Maxi : " << secondMaxi << endl;
    vector<int> advantage;
    int n = strengthArray.size();
    for (int i = 0; i < n; i++)
    {
        if (strengthArray[i] != maxi)
        {
            int diff = strengthArray[i] - maxi;
            advantage.push_back(diff);
        }
        else
        {
            int diff = maxi - secondMaxi;
            advantage.push_back(diff);
        }
    }
    return advantage;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> strengthArr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> strengthArr[i];
        }
        vector<int> advantage = findAdvantageOverOther(strengthArr);
        for (int num : advantage)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}