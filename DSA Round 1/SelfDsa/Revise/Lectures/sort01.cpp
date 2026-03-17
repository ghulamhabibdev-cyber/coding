#include <iostream>
using namespace std;

int main()
{
    int arr[5] = {1, 0, 0, 1, 0};
    int i = 0;
    int j = 4 ;
    while (i <j)
    {
        while(arr[i]==0)
        {
            i++;
        }
        while(arr[j]==1)
        {
            j--;
        }
        if(i<j)
        {
            swap(arr[i], arr[j]);
        }
        // i++;
        // j--;
    }
    for(int i=0;i<5;i++)
    {
        cout<<arr[i];
    }

    return 0;
}
