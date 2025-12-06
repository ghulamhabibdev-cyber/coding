#include <bits/stdc++.h>
using namespace std;
int sumofArr(int arr[], int size)
{
    if (size ==0)
    {
        return 0;
    }
    else
    {
        int sum = arr[0];
        sum += sumofArr(arr + 1, size - 1);
        return sum;
    }
}

int main()
{

    int arr[4] = {1, 2, 3, 4};
    cout << "sum : " << sumofArr(arr, 4);
    return 0;
}