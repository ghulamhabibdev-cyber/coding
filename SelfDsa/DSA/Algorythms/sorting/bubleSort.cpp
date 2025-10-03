#include <bits/stdc++.h>
using namespace std;
void bubbleSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        bool swaped=false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[i], arr[j + 1]);
                swaped=true;
            }
        }
        if(!swaped)
        {
            cout<<i<<" \n";
            break;
        }
    }
}
void printVec(vector<int> arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
}
int main()
{

    vector<int> nums = {1,2,3,4,4};
    cout << "before sort" << endl;
    printVec(nums);
    cout << "after sort" << endl;
    bubbleSort(nums);
    printVec(nums);

    return 0;
}