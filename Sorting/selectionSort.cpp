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
void SelectionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        int element = arr[i];
        int index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < element)
            {
                element = arr[j];
                index = j;
            }
        }

        swap(arr[index], arr[i]);
    }
}
void printArray(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    vector<int> arr = {123, 24321, 1, 1, 1, 12, 12, 1, 2, 3, 43, 5, 0, 9, 3, 3};
    SelectionSort(arr);
    printArray(arr);
    return 0;
}