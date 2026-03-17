#include <iostream>
using namespace std;
int starisWays(int n)
{
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return 1;
    }
    return starisWays(n - 1) + starisWays(n - 2);
}
void countSay(int n)
{
    if (n < 0)
    {
        return;
    }
    if (n == 0)
        return;
    int digit = n % 10;
    string arr[10] = {
        "zero", "one", "two", "three", "four",
        "five", "six", "seven", "eight", "nine"};

    countSay(n / 10);
    cout << arr[digit] << endl;
}
int main()
{

    // cout<<starisWays(2);
    countSay(200);
    return 0;
}
