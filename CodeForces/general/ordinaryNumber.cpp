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
int findCountOfOrdinaryNumber(int num)
{
    if (num < 10)
    {
        return num;
    }
    int ten = 10;
    int eleven = 1;
    // int diff = 10;
    int number = 0;
    int count = 0;
    int ordinaryCount = 9;
    int diff = 10;
    while (number + ten < num && diff > eleven)
    {
        number = ten + number + eleven;
        diff = num - number;
        ordinaryCount++;
        count++;
        if (count == 9)
        {
            // cout << "Count : " << count << " ten  : " << ten << " diff : " << diff << " number : " << number << endl;
            eleven = eleven * 10 + 1;
            ten *= 10;
            count = 0;
            number = 0;
        }
    }
    return ordinaryCount;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int number;
        cin >> number;
        int ordinaryCount = findCountOfOrdinaryNumber(number);
        cout << ordinaryCount << endl;
    }

    return 0;
}