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

int main()
{
    int n;
    cin >> n;
   
    vector<int>ans;
    for (int i = 0; i < n; i++)
    {
        int size;
        cin >> size;
        vector<int> arr;
        int count = 0;
        int index;
        int otherCount = 0;
        int otherIndex = 0;
        for (int i = 1; i <= size; i++)
        {
            int number;
            cin >> number;
            arr.push_back(number);
            if (arr[0] == number)
            {
                count++;
                index = i;
            }
            else
            {
                otherCount++;
                otherIndex = i;
            }
        }
       
        if (otherCount == 1)
        {
            ans.push_back(otherIndex);
        }
        else if (count == 1)
        {
            ans.push_back(index);
        }
    }
    for (int index : ans)
    {
        cout << index  << endl;
    }

    return 0;
}