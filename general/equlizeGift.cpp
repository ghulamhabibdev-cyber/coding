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
pair<int, int> findMin(vector<int> candies, vector<int> oranges)
{
    int n = candies.size();
    int candyMin = candies[0];
    int orangeMin = oranges[0];
    for (int i = 0; i < n; i++)
    {
        if (candies[i] < candyMin)
        {
            candyMin = candies[i];
        }
        if (oranges[i] < orangeMin)
        {
            orangeMin = oranges[i];
        }
    }
    return {candyMin, orangeMin};
}
long long minStepToEqualizeGif(vector<int> candies, vector<int> oranges)
{
    int n = candies.size();
    long long minStep = 0;
    pair<int, int> p = findMin(candies, oranges);
    int candyMin = p.first;
    int orangeMin = p.second;
    for (int i = 0; i < n; i++)
    {
        int currCandy = candies[i];
        int currOrange = oranges[i];
        int combineStep = min(currCandy - candyMin, currOrange - orangeMin);
        minStep += combineStep;
        int maxStep = max(currCandy - candyMin, currOrange - orangeMin);
        minStep += maxStep - combineStep;
        // cout << " curr min Step : " << minStep << endl;
    }
    return minStep;
}
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> candies(n);
        vector<int> oranges(n);
        for (int i = 0; i < n; i++)
        {
            cin >> candies[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> oranges[i];
        }
        long long minStep = minStepToEqualizeGif(candies, oranges);
        cout << minStep << endl;
    }
    return 0;
}