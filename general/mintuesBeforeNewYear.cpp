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
int timeRemainInNewYear(int hour, int mint)
{
    int reminHour = 24 - hour;
    int remHourMintes = reminHour * 60;

    int ans = remHourMintes - mint;
    return ans;
}
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int hour,mint;
        cin>>hour>>mint;
        int ans = timeRemainInNewYear(hour, mint);
        cout << ans << endl;
    }
   

    return 0;
}