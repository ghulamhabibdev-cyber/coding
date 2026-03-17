#include <iostream>
using namespace std;

int main()
{
    int arr[5] = {12, 43, 54, 6, 1};
    for (int i = 0; i < 5; i++)
    {

        int index = i;
        for (int j = i + 1; j < 5; j++)
        {
            if (arr[j] < arr[index])
            {
                index = j;
            }
        }
        swap(arr[index],arr[i]);
    }
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
