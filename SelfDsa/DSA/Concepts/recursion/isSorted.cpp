#include <bits/stdc++.h>
using namespace std;
bool isSorted(int arr[], int size)
{
    if (size == 0 || size == 1)
    {
        return true;
    }
    if (arr[0] > arr[1])
    {
        return false;
    }
    else
    {
        bool remain = isSorted(arr + 1, size - 1);
        return remain;
    }
}
int main()
{
    int arr[4] = {1, 2, 3, 4};
    cout << isSorted(arr, 4);
    return 0;
}