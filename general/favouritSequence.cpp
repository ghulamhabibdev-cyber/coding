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
vector<int> restoreSequence(vector<int> arr)
{
    vector<int> restoredSequence;
    int i = 0;
    int j = arr.size() - 1;
    while (i <= j)
    {
        restoredSequence.push_back(arr[i]);
        restoredSequence.push_back(arr[j]);
        i++;
        j--;
    }
    if (arr.size() % 2 == 1)
    {
        restoredSequence.pop_back();
    }
    return restoredSequence;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int sizeOfSequence;
        cin >> sizeOfSequence;
        vector<int> arr(sizeOfSequence);
        for (int index = 0; index < sizeOfSequence; index++)
        {
            cin >> arr[index];
        }
        vector<int> restoredSequence = restoreSequence(arr);
        for (int n : restoredSequence)
        {
            cout << n << " ";
        }
        cout << endl;
    }

    return 0;
}