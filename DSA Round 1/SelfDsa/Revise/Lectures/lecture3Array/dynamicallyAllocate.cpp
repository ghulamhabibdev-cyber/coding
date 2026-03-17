#include <iostream>
using namespace std;

int main()
{
    cout << "Enter the size \n";
    int n;
    cin >> n;
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the Element \n";
        cin >> arr[i];
    }
    arr = (int *)realloc(arr, (n + 1) * sizeof(int));
    cout << "Enter the new element \n";
    int x;
    cin >> x;
    arr[n] = x;
    n++;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i]<<" ";
    }
    return 0;
}
