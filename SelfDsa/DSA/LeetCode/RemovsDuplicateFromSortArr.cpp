#include <bits/stdc++.h>
using namespace std;
int couuntUnique(int arr[], int size)
{
    int i = 1;
    for (int j = 1; j < size; j++)
    {
        int last=arr[size-1];
        if (arr[j] !=arr[i+1] )
        {
           
            i++;
        }
    }
    return i;
}
void printArray(int arr[], int size)
{
    for (int j = 0; j < size; j++)
    {
        cout << arr[j] << "\t";
    }
}
void removeDuplicate(int arr[], int size)
{
    
    for (int i = 0; i < size; i++)
    {
         for (int j = i + 1; j < size; )
        {
            if(arr[i]==arr[j])
            {
                for(int k=j;k<size-1;k++)
                {
                    arr[k]=arr[k+1];
                   
                }
                 size--;
            }
            else{
                j++;
            }
           
        }
        
    }
     couuntUnique(arr,size);
} 
int main()
{
    int arr[17] = {0, 0, 1, 2, 2,2,2,4,4,4 ,5,5,5,5,6,6,6};
    removeDuplicate(arr, 17);
    // shiftzero(arr,17);
    // printArray(arr, 17);
    return 0;
}