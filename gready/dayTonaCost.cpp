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

class clssSolution
{
public:
    bool checkSequencePrense(vector<int> arr, int k, int n)
    {

        for (int i = 0; i < n; i++)
        {
            if (k == arr[i])
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    int n;
    cin >> n;
    clssSolution sol;
    for (int i = 0; i < n; i++)
    {
        int size;
        int k;
        cin >> size;
        cin >> k;
        vector<int> arr(size);
        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
        }
        bool isPresent = sol.checkSequencePrense(arr, k, size);
        if (isPresent)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

    return 0;
}