#include <bits/stdc++.h>
using namespace std;
int binarySearch(int arr[], int size, int key)
{
    int ans=-1;
    int st = 0;
    int end = size - 1;
    int mid = st+ (end-st) / 2;
    while (st <= end)
    {
        if (arr[mid] == key)
        {
            ans= mid;
            break;
        }
        else if (key > arr[mid])
        {
            // end = mid - 2;
            st = mid + 1;
        }
        else
        {
            end = mid - 1;

        }
        mid = st + (end - st) / 2;
    }
    return ans;
}
int main()
{
    int arr[10] = {12, 34, 56, 78, 90, 100, 134, 543, 678, 547};
    int arre[5]={12,10,7,5,3};
    cout << binarySearch(arr, 10, 90)<<endl;;
    // cout << binarySearch(arre, 5, 12) << endl;
    return 0;
}
