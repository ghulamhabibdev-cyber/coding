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
long sumArray(vector<int> array)
{
    long int totalSum = 0;
    for (int n : array)
    {
        totalSum += n;
    }
    return totalSum;
}
long productArray(vector<int> array)
{
    long int totalProduct = 1;
    for (int n : array)
    {
        totalProduct *= n;
    }
    return totalProduct;
}
int findMaxIndex(vector<int> array)
{
    int maxIndex = 0;
    for (int i = 1; i < array.size(); i++)
    {
        if (array[i] > array[maxIndex])
        {
            maxIndex = i;
        }
    }
    return maxIndex;
}
int findMinIndex(vector<int> array)
{
    int minIndex = 0;
    for (int i = 1; i < array.size(); i++)
    {
        if (array[i] < array[minIndex])
        {
            minIndex = i;
        }
    }
    return minIndex;
}

void swapMinMax(vector<int> &array, int minIndex, int maxIndex)
{
    swap(array[minIndex], array[maxIndex]);
}
void printAllUnique(vector<int> array)
{
    unordered_map<int, int> frequency;
    for (int n : array)
    {
        frequency[n]++;
    }
    for (auto it = frequency.begin(); it != frequency.end(); it++)
    {
        if (it->second == 1)
        {
            cout << it->first << " ";
        }
    }
    cout << endl;
}
void printVector(vector<int> arr)
{
    for (int n : arr)
    {
        cout << n << " ";
    }
    cout << endl;
}
int main()
{
    vector<int> arr = {11, 32, 43, 34, 45, 4334, 23, 3434, 434, 343, 3, 2, -1};
    printVector(arr);
    cout << sumArray(arr) << endl;
    cout << productArray(arr) << endl;
    cout << endl;
    swapMinMax(arr, findMinIndex(arr), findMaxIndex(arr));
    printVector(arr);

    return 0;
}