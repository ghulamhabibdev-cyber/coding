#include <iostream>
using namespace std;
bool isSorted(int arr[], int n)
{
    if (n == 0 || n == 1)
    {
        return true;
    }
    if (arr[0] > arr[1])
    {
        return false;
    }
    else
    {
        return isSorted(arr + 1, n - 1);
    }
}
int sumarr(int arr[], int n)
{
    if (n == 1)
    {
        return arr[0];
    }
    int sum = sumarr(arr, n - 1) + arr[n - 1];
    return sum;
}
int linearSearch(int arr[], int n, int key)
{
    if (n < 0)
    {
        return -1;
    }
    if (arr[n - 1] == key)
    {
        return n - 1;
    }
    return linearSearch(arr, n - 1, key);
}
int linsearc(int arr[], int n, int key)
{
    if (n == 0)
    {
        return -1;
    }
    if (arr[0] == key)
    {
        return true;
    }
    else
    {
        return linsearc(arr + 1, n - 1, key);
    }
}
int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    // bool ans = isSorted(arr, 5);
    // cout<<sumarr(arr,5);
    // cout << ans << endl;
    cout << linearSearch(arr, 5, 10) << endl;
    cout << linsearc(arr, 5, 2) << endl;
    return 0;
}
