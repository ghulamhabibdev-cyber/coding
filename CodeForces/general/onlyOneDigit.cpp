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
int minDigitInNumber(int num)
{
    int minNumber = INT_MAX;
    int divid = 10000;
    while (num != 0)
    {
        int digit = num % 10;
        if (digit < minNumber)
        {
            minNumber = digit;
                }
        num /= 10;
    }
    return minNumber;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int number;
        cin >> number;
        int ans = minDigitInNumber(number);
        cout << ans << endl;
    }

    return 0;
}