#include <iostream>
#include <vector>
using namespace std;

void helper(vector<vector<int>> &arr, vector<int> &curr, const vector<int> &arry, int index)
{
    if (index >= arry.size())
    {
        arr.push_back(curr);
        return; 
    }

  
    helper(arr, curr, arry, index + 1);

    curr.push_back(arry[index]);
    helper(arr, curr, arry, index + 1); 
    curr.pop_back();              
}

void FindAllSubSets(vector<vector<int>> &arr, const vector<int> &array, int index)
{
    vector<int> curr;
    helper(arr, curr, array, 0);
}

int main()
{
    vector<vector<int>> ans;
    vector<int> arr = {1, 2, 3};
    FindAllSubSets(ans, arr, 0);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << (j + 1 < ans[i].size() ? ", " : "");
        }
        cout << "]" << endl;
    }
    return 0;
}
