#include <iostream>
using namespace std;

class A
{
};

void reverseArray(int arr[], int size)
{
    int st = 0;
    int end = size - 1;
    while (st < end)
    {
        swap(arr[st], arr[end]);
        st++;
        end--;
    }
}
void print(int arr[], int sz)
{
    for (int i = 0; i < sz; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int arr[6] = {12, 23, 34, 43, 43,54};
    int size = 6;
    reverseArray(arr, size);
    print(arr, size);
    return 0;
}