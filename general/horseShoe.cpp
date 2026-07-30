#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits>

#include <unordered_set>
#include <list>
using namespace std;

class A
{
};
int horseShoe()
{
    unordered_set<int> sety;
    for (int i = 0; i < 4; i++)
    {
        int n;
        cin >> n;
        sety.insert(n);
    }
    int dif = sety.size();
    return 4 - dif;
}
int main()
{
    int ans = horseShoe();
    cout << ans << endl;
    return 0;
}