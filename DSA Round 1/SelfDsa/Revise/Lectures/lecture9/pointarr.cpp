#include <bits/stdc++.h>
using namespace std;

void print(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
        arr++;
    }
}

int main()
{
    int arr[4] = {43, 55, 545, 656};
    print(arr, 4);
    return 0;
}
