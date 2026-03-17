#include <bits/stdc++.h>
using namespace std;
void bubleSort(vector<int> &arr)
{
    int n = arr.size();
    bool sorted = false;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < (n - i - 1); j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                sorted = false;
            }
            else
            {
                sorted= true;
            }
        }
        cout<<"roudn : "<<i<<endl;
        if (sorted)
        {
            break;
        }
    }
}
template <class Type>
void printVector(vector<Type> arr)
{
    for (Type n : arr)
    {
        cout << n << " ";
    }
}
int main()
{

    vector<int> arr = {1,2,3,4,5};
    bubleSort(arr);
    printVector(arr);
    return 0;
}
