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
int boringApartmentCount(int appartmentNo)
{
    int digit = 1;
    int current = 0;
    int digitCount = 0;
    int len = 0;
    while (true)
    {
        current = current * 10 + digit;
        len += 1;
        digitCount += len;
        if (current == appartmentNo)
        {
            return digitCount;
        }
        if (len == 4)
        {
            digit++;
            len = 0;
            current = 0;
        }
    }
    return digitCount;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int appartment;
        cin >> appartment;
        cout << boringApartmentCount(appartment) << endl;
    }

    return 0;
}