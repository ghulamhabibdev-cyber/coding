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
int findNumberOfTeam(int numberOfEmployee)
{
    int teamCount = 0;
    for (int factor = 1; factor <= numberOfEmployee / 2; factor += 1)
    {
        if (numberOfEmployee % factor == 0)
        {
            teamCount++;
        }
    }
    return teamCount;
}
int main()
{
    int numberOfEmployee;
    cin >> numberOfEmployee;
    int maxNumberOfTeams = findNumberOfTeam(numberOfEmployee);
    cout << maxNumberOfTeams << endl;

    return 0;
}