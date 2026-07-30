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
void sortNum(int &a, int &b, int &c)
{
    // cout << "============================= Before Sort===================\n";
    // cout << "a : " << a << endl;
    // cout << "b : " << b << endl;
    // cout << "c : " << c << endl;
    if (a > b)
    {
        swap(a, b);
        // cout << "a : " << a << endl;
        // cout << "b : " << b << endl;
        if (a > c)
        {
            swap(a, c);
        }
    }
    else if (a > c)
    {
        swap(a, c);
    }
    if (b > c)
    {
        swap(b, c);
    }
    // cout << "============================= After Sort===================\n";
    // cout << "a : " << a << endl;
    // cout << "b : " << b << endl;
    // cout << "c : " << c << endl;
}
int minDistanceTravel(int &aDist, int &bDist, int &cDist)
{
    sortNum(aDist, bDist, cDist);
    // int a = cDist - bDist;;
    int ans = cDist - aDist;

    // int ans=a+b;
    return ans;
}
int main()
{
    int aDistance;
    int bDistance;
    int cDistance;
    cin >> aDistance >> bDistance >> cDistance;
    int ans = minDistanceTravel(aDistance, bDistance, cDistance);
    cout << ans;
    return 0;
}