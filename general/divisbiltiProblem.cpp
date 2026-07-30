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
void numberOfStepToDiviAbyB(int n)
{
    while (n--)
    {
        int a, b;
        cin >> a >> b;

        int rem = a % b;
        if (rem == 0)
            cout << 0 << endl;
        else
            cout << b - rem << endl;
    }
}
int main()
{
    int n;
    cin>>n;
    numberOfStepToDiviAbyB(n);
    return 0;
}