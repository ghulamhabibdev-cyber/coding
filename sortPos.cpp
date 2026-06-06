#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits>
#include <list>
using namespace std;

class A
{
};
void sortPos(vector<int> &arr)
{
    int n = arr.size();
    int s = 0;
    int e = n - 1;
    while (s < e)
    {
        if (arr[s] == arr[e])
        {
            swap(arr[s], arr[e]);
            s++;
        }
        else if (arr[s] < arr[e])
        {
            s++;
        }
        else
        {
            swap(arr[s], arr[e]);
            s++;
        }
    }
}
int main()
{
    vector<int>arr={2,3,23,1,7,9,5};
    sortPos(arr);
    for(int x:arr)
    {
        cout<<x<<" ";
    }

    return 0;
}