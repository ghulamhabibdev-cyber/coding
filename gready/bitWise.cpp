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
int getNumber(int n)
{
    int pow=1;
    while(pow<n)
    {
        pow*=2;
    }
    return (pow/2)-1;
}
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << getNumber(n) << endl;
    }

    return 0;
}