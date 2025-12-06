#include <bits/stdc++.h>
using namespace std;
class a
{
public:
};
int solveRecCostProb(int n, vector<int> &days, vector<int> &cost, int i)
{

    if (i >= n)
    {
        return 0;
    }

    // for 1 day
    int option1 = cost[0] + solveRecCostProb(n, days, cost, i + 1);
    cout << "I am option no two :2-4-6:  : " << option1 << endl;
    // for 7 days
    int index;
    for (index = i; index < n && days[index] < days[i] + 7; index++)
        ;

    int option2 = cost[1] + solveRecCostProb(n, days, cost, index);
    cout << "I am option no two :7:  : " << option2 << endl;

    // for 30 days
    for (index = i; index < n && days[index] < days[i] + 30; index++)
        ;

    int option3 = cost[2] + solveRecCostProb(n, days, cost, index);
    cout << "I am option no two :15:  : " << option3 << endl;
    // getting min ans
    int ans = min(option1, min(option2, option3));
    return ans;
}
int solveTickByMem(int n, vector<int> &days, vector<int> &cost, int i, vector<int> &dp)
{

    if (i >= n)
    {
        return 0;
    }
    // for 1 day
    int option1 = cost[0] + solveRecCostProb(n, days, cost, i + 1);
    // for 7 days
    int index;
    for (index = i; index < n && days[index] < days[i] + 7; index++)
        ;

    int option2 = cost[1] + solveRecCostProb(n, days, cost, index);

    // for 30 days
    for (index = i; index < n && days[index] < days[i] + 30; index++)
        ;

    int option3 = cost[2] + solveRecCostProb(n, days, cost, index);
    // getting min ans
    int ans = min(option1, min(option2, option3));
    dp[i] = ans;
    return dp[i];
}
int solveTicketByTab(int n, vector<int> &days, vector<int> &cost, int i)
{
    vector<int> dp(n + 1, INT_MAX);
    dp[n] = 0;
    for (int k = n - 1; k >= 0; k--)
    {
        int option1 = cost[0] + dp[k + 1];
        // for 7 days
        int index;
        for (index = k; index < n && days[index] < days[k] + 7; index++)
            ;

        int option2 = cost[1] + dp[index];

        // for 30 days
        for (index = k; index < n && days[index] < days[k] + 30; index++)
            ;

        int option3 = cost[2] + dp[index];
        // getting min ans
        dp[k] = min(option1, min(option2, option3));
    }
    return dp[0];
}
int solveTicketOptimization(int n, vector<int> &days, vector<int> &cost, int i)
{
    int ans = 0;
    queue<pair<int,int>> month;
    queue<pair<int,int>> week;
    for (int day : days)
    {
        while (!month.empty() && month.front().first + 30 <= day)
        {
            month.pop();
            cout << "Month Poping \n";
        }
        while (!week.empty() && week.front().first + 7 <= day)

        {
            week.pop();
            cout << "week Poping \n";
        }
        week.push(make_pair(day, ans + cost[1]));
        month.push(make_pair(day, ans + cost[2]));

        ans = min(ans + cost[0], min(week.front().second, month.front().second));
        cout << "ans : " << ans << endl;
    }

    return ans;
}

int minimumTicketCost(int n, vector<int> days, vector<int> cost)
{
    int ans = 0;
    // ans = solveRecCostProb(n, days, cost, 0);
    vector<int> dp(n + 1, -1);
    // ans = solveTickByMem(n, days, cost, 0, dp);
    // ans = solveTicketByTab(n, days, cost, 0);
    ans = solveTicketOptimization(n, days, cost, 0);

    return ans;
}
int main()
{
    vector<int> days = {1, 4, 7, 40, 50, 200,201,202,203,204,205,206,207};
    vector<int> cost = {2, 7, 15};
    int n = days.size();
    cout << "Size : " << n << endl;
    cout << "Minimum cost   :   \n" << minimumTicketCost(n, days, cost) << endl;
    cout<<endl;
    return 0;
    return 0;
}