#include <iostream>
using namespace std;

void removeDuplicate(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; )
        {
            if (arr[i] == arr[j])
            {
                // Shift all elements left from j+1
                for (int k = j; k < size - 1; k++)
                {
                    arr[k] = arr[k + 1];
                }
                size--; // Reduce size after removing duplicate
            }
            else
            {
                j++; // Only increment if no deletion
            }
        }
    }

    // Fill the rest with -1 (or any marker for "duplicate")
    // for (int i = size; i < 17; i++)
    // {
    //     arr[i] = -1;
    // }

    // Print result
    for (int i = 0; i < 17; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int arr[17] = {0, 0, 1, 2, 2,2,2,4,4,4 ,5,5,5,5,6,6,6};
    removeDuplicate(arr, 17);
    // shiftzero(arr,17);
    // printArray(arr, 17);
    return 0;
}