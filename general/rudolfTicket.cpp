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
int numberOfWay(vector<int> leftBag, vector<int> rightBag, int k)
{
    int n = leftBag.size();
    int m = rightBag.size();
    sort(leftBag.begin(), leftBag.end());
    sort(rightBag.begin(), rightBag.end());
    int index=0;
    int nWays=0;
    for(int i=0;i<n;i++)
    {
        if(leftBag[i]+rightBag[index]<=k&&index<m)
        {
            nWays++;
            while()
        }
    }
    int ways=index*nWays;
    return ways;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> leftBag(n);
        vector<int> rightBag(m);
        for (int i = 0; i < n; i++)
        {
            cin >> leftBag[i];
        }
        for (int i = 0; i < m; i++)
        {
            cin >> rightBag[i];
        }
        int ways = numberOfWay(leftBag, rightBag, k);
        cout << ways << endl;
    }
    return 0;
}