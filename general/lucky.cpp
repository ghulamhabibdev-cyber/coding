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
bool isLuckyTicket(string number)
{
    int i = 0;
    int j = number.length() - 1;
    int firstThreeDigitSum = 0;
    int lastThreeDigitSum = 0;
    while (i <= j)
    {
        int leftDig = number[i] - '0';
        int rightDigit = number[j] - '0';
        firstThreeDigitSum += leftDig;
        lastThreeDigitSum += rightDigit;
        i++;
        j--;
    }
    return firstThreeDigitSum == lastThreeDigitSum;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string number;
        cin >> number;
        bool isLucky = isLuckyTicket(number);
        if (isLucky)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}