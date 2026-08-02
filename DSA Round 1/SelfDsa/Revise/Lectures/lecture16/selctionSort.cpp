#include <bits/stdc++.h>
using namespace std;
void selectionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n-1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
    }
}
int main()
{
    vector<int> arr = {23, 43, 35, 453, 4354, 34534, 453, 3, 5, 4, 34, 34, 54};
    selectionSort(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] <<

            " ";
    }

    return 0;
}
