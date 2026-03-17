#include <iostream>
using namespace std;
int binarysearchInMutlidiementional(int arr[][5],    int target)
{
        int row = 4;
    int col = 5;
    int start = 0;
    int end = (row * col) - 1;
  
    while (start <= end)
    {
         int mid=start+(end-start)/2;
        int element = arr[mid / col][mid % col];
        if (target == element)
        {
            return 1;
        }
        if (target < element)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return 0;
}
int main()
{
    int target = 4;
    int arr[4][5] = {{1, 2, 3, 4, 5},
                     {6, 7, 8, 9, 10},
                     {11, 12, 13, 14, 15},
                     {16, 17, 18, 19, 20}};
                    
    cout<<binarysearchInMutlidiementional(arr,20);

}