#include <bits/stdc++.h>
using namespace std;
bool found(int arr[], int size, int key)
{
    int st = 0;
    int end = size - 1;
    bool find = false;
    while (st < end)
    {
        if (key == arr[st])
        {
            find = true;
        }
        if (key == arr[end])
        {
            find = true;
        }
        st++;
        end--;
    }
    return find;
}
int main()
{
    int arr[10] = {12, 345, 5, 43, 55, 534, 34, 545, 34, 54};
    bool yes = found(arr, 10, 545);
    if (yes)
    {
        cout << "Present \n";
    }
    else
    {
        cout << "not present \n";
    }

    return 0;
}
