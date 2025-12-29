#include <iostream>
#include <vector>
using namespace std;

class A
{
};
bool isSorted(vector<int> arr, int n)
{
    if (n == 0 || n == 1)
    {
        return true;
    }
    return arr[n - 1] >= arr[n - 2] && isSorted(arr, n - 1);
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 60, 7, 8, 9};
    int n = arr.size();
    bool isSort = isSorted(arr, n);
    if (isSort)
    {
        cout << "Yes i am sorted \n";
    }
    else{
        cout<<"i am not sorted \n";
    }

    return 0;
}