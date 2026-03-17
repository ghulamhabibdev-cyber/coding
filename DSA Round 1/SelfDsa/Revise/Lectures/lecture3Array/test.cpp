#include<iostream>
using namespace std;

int main()
{
    int n, x;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[100];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter element to insert at beginning: ";
    cin >> x;

    for (int i = n; i > 0; i--)
        arr[i] = arr[i - 1];

    arr[0] = x;
    n++;

    cout << "\nArray after insertion:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    for (int i = n; i > 0; i--)
        arr[i] = arr[i - 1];
    cout << "Enter element to insert at beginning: ";
    cin >> x;
    arr[0]=x;
    n++;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
