#include <iostream>
using namespace std;

class A
{
};
int minStep(int a, int b)
{
    if (a == b)
    {
        return 0;
    }
    else if (a > b)
    {
        int diff = a - b;
        if (a % 2 == 0 && b % 2 == 1)
        {
            return 1;
        }
        else if (a % 2 == 1 && b % 2 == 0)
        {
            return 2;
        }
        else if (a % 2 == 0 && b % 2 == 0)
        {
            return 2;
        }
        return 1;
    }
    else
    {
        int diff = a - b;
        if (a % 2 == 0 && b % 2 == 1)
        {
            return 1;
        }
        else if (a % 2 == 0 && b % 2 == 0)
        {
            return 2;
        }
        else if (a % 2 == 1 && b % 2 == 0)
        {
            return 1;
        }
        return 2;
    }
    return 0;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        int min = minStep(a, b);
        cout << min << endl;
    }

    return 0;
}