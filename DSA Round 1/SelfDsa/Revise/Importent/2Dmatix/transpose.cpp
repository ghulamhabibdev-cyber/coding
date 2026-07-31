#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
void transpose(vector<vector<int>>&arr)
{
    int row=arr.size();
    int col=arr[0].size();
    for(int i=0;i<row;i++)
    {
        for(int j=i+1;j<col;j++)
        {
            swap(arr[i][j],arr[j][i]);
        }
    }
}
int main()
{
    int rows = 4, cols = 4;
    vector<vector<int>> ans(rows, vector<int>(cols));

    int value = 3; // starting value
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            ans[i][j] = value;
            value++; // increment for variety
        }
    }

    // Display
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    cout<<"\n\nTranpose\n";
    transpose(ans);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < ans.size(); ++i)
    {
        std::reverse(ans[i].begin(), ans[i].end());
    }
    cout<<endl<<endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
