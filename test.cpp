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
void sepRateZero(vector<int> &arr)
{
    int st = 0;
    int n = arr.size();
    int end = n - 1;
    int back = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            swap(arr[i], arr[back]);
            back++;
        }
    }
}

int getZeroIndex(const vector<int> &arr, int value)
{
    int n = arr.size();
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == value)
        {
            index = i;
        }
    }
    return index;
}
int getNegIndex(const vector<int> &arr)
{
    int index = -1;
    int i = 0;
    while (i < arr.size() && arr[i] < 0)
    {
        index = i;
        i++;
    }
    return index;
}
void habibSort(vector<int> &arr)
{
    int negIndex = getNegIndex(arr);
    int zeroIndex = getZeroIndex(arr, 0);
    int posIndex = zeroIndex + 1;
    if (negIndex != -1)
    {
        int s = 0;
        int e = negIndex;
        while ()
        {
            swap(arr[s], arr[e]);
            s++;
            e--;
        }
    }
    if (zeroIndex != -1)
    {
    }
}
void separateNeg(vector<int> &arr)
{
    int zeroIndex = getZeroIndex(arr, 0);
    if (zeroIndex != -1)
    {
        // Move all negative numbers to the left of the zero
        int negIndex = zeroIndex + 1;
        for (int i = zeroIndex + 1; i < arr.size(); i++)
        {
            if (arr[i] < 0)
            {
                swap(arr[i], arr[negIndex]);
                negIndex++;
            }
        }
        int zeroFor = 0;
        for (int i = negIndex - 1; i > zeroIndex; i--)
        {
            swap(arr[i], arr[zeroFor]);
            zeroFor++;
        }
    }
}
void print(const vector<int> &arr)
{
    for (int x : arr)
    {
        cout << x << " ";
    }
    cout << endl;
}
int main()
{
    vector<int> arr = {0, 1, 0, 5, 6, 7, 0, -23, 9, 0, -1, 0, -3};

    ;
    sepRateZero(arr);
    print(arr);
    separateNeg(arr);
    print(arr);
    return 0;
}