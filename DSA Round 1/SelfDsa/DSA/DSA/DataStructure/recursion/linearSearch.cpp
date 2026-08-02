#include <bits/stdc++.h>
using namespace std;
bool linearSearch(int arr[], int size, int key)
{
    if (size == 0)
    {
        return false;
    }
    else
    {
        if (key == arr[0])
        {
            return true;
        }
        else
        {
            bool remain = linearSearch(arr + 1, size - 1, key);
            return remain;
        }

        return true;
    }
}
int main()
{
    int arr[4] = {1, 2, 3, 4};
    cout << linearSearch(arr, 4, 7);
    return 0;
}