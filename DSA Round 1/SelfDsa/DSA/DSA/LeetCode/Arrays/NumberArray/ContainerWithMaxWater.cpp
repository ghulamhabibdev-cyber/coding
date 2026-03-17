#include <iostream>
using namespace std;
int containerWater(int arr[], int size)
{
    int ans = INT32_MIN;
    for (int i = 0; i <size; i++)
    {
        for (int j = i+1 ; j <size; j++)
        {
                int wid = j - i;
                int height  = min(arr[i], arr[j]);
            
                int area = wid * height;
                 ans = max(ans, area);
        }
    }
    return ans;
}
int main()
{
        int arr2[2]={1,2};
       
        cout<<containerWater(arr2,2)<<endl;
         int arr3[3]={1,2,1};
         cout<<containerWater(arr3,3)<<endl;
    int arr[9] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << containerWater(arr, 9)<<endl;
    return 0;
}