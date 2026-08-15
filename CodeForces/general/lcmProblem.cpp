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
int gcd(int numberOne, int numberTwo)
{
    while (numberTwo != 0)
    {
        int tempNumber = numberTwo;
        numberTwo = numberOne % numberTwo;
        numberOne = tempNumber;
    }
    return numberOne;
}
int MinLcmNumber(int numberOne, int numberTwo)
{
    int numberGcd = gcd(numberOne, numberTwo);
    if (numberGcd != 1)
    {
        int minNumber = min(numberTwo, numberOne);
        return minNumber * numberGcd;
    }
    return numberTwo * numberOne;
}
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int numberOne, numberTwo;
        cin >> numberOne >> numberTwo;
        int minLcm = MinLcmNumber(numberOne, numberTwo);
        cout << minLcm << endl;
    }
    return 0;
}