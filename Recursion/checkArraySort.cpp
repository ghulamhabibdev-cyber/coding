#include <iostream>
#include <vector>
using namespace std;

class A
{
};
bool isSorted(vector<int> arr, int index)
{
    if (index >= arr.size())
    {
        return true;
    }
    else if (index == 0)
    {
        return true;
    }
    else if (arr[index] < arr[index - 1])
    {
        return false;
    }
    bool ans = isSorted(arr, index + 1);
    return ans;
}
int main()
{
    vector<int> arr = {1, 2, 3, 40, 5};
    cout << isSorted(arr, 4);

    return 0;
}