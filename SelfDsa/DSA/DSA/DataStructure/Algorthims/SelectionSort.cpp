// The Selection sort
#include <iostream>

using namespace std;
void SelectionSort(int arr[], int size)
{
    int lex = 1;
    for (int i = 0; i < size - 1; i++)
    {
        bool found = false;
        int index = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[index])
            {
                index = j;
                found = true;
            
            }
        }
        if (found)
        {
            int temp = arr[i];
            arr[i] = arr[index];
            arr[index] = temp;
        }
    }
    cout << endl;
}
void PrintArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}
int main()
{
    int arr[8] = {0, 13, 4, 8, 6, 788, 65, 43};
    SelectionSort(arr, 8);
    PrintArray(arr, 8);
}