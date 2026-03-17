#include <bits/stdc++.h>
using namespace std;
vector<int> mergeTwo(vector<int> a, vector<int> b)
{
    int i = 0;
    int j = 0;
    int n = a.size();
    int m = b.size();
    int k = 0;
    vector<int> ans;
    while (i < n && j < m)
    {
        if (a[i] < b[j])
        {
            ans.push_back(a[i]);
            k++;
            i++;
        }
        else
        {
            ans.push_back(b[j]);
            k++;
            j++;
        }
    }
    while (i < n)
    {
        ans.push_back(a[i]);
        k++;
        i++;
    }
    while (j < m)
    {
        ans.push_back(a[j]);
        j++;
    }
    return ans;
}
int main()
{
    vector<int> a = {23, 44, 55, 67, 78, 90};
    vector<int> b = {34, 54, 65, 87, 97, 100};
    vector<int> ans = mergeTwo(a, b);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
