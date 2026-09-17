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
void insertionSort(vector<int> &arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                swap(arr[j], arr[j - 1]);
            }
            else
            {
                break;
            }
        }
    }
}
void printVector(vector<int> &arr)
{
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
}
int main()
{
    vector<int> arr = {60, 44, 13, 9, 24, 0, 2, 3, 4, 5, 0};
    insertionSort(arr);
    printVector(arr);

    return 0;
}