#include <bits/stdc++.h>
using namespace std;
void insertinSort(vector<int> &arr)
{
    int index = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        int temp = arr[i];
        int j = i - 1;

        // shift elements greater than temp to one position ahead
        for (; j >= 0; j--)
        {
            if (arr[j] > temp)
            {
                arr[j + 1] = arr[j];
                index = j;
            }
            else
            {
                break;
            }
        }

        // insert temp at the right position
        arr[j + 1] = temp;
    }
}
int main()
{
    vector<int> arr = {43, 45, 343, 4, 3, 32, 32, 12, 14, 15, 13, 23, 453, 56};
    insertinSort(arr);

    for (int n : arr)
        cout << n << " ";
    cout << endl;
    return 0;
}
