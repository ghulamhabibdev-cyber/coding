#include <iostream>
using namespace std;
bool IsPossible(int arr[], int size, int m, int mid)
{
    int noOfPaint = 1;
    int PaintSum = 0;
    for (int i = 0; i < size; i++)
    {
        if (PaintSum + arr[i] <= mid)
        {
            PaintSum += arr[i];
        }
        else
        {
            noOfPaint++;
            if (noOfPaint > m || arr[i] > mid)
            {
                return false;
            }
            PaintSum = arr[i];
        }
    }
    return true;
}
int MinimumTimeTopaint(int arr[], int size, int m)
{
    int start = 0;
    int end = 0;
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    end = sum;

    int mid = start + (end - start) / 2;
    int ans = -1;
    while (start <= end)
    {
        if (IsPossible(arr, size, m, mid))
        {
            ans = mid;
            end = mid - 1;
        }

        else
        {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}
int main()
{
    int arr[4] = {5, 5, 5, 5};
    cout << MinimumTimeTopaint(arr, 4, 2);
}