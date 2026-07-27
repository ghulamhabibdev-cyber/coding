#include <iostream>
using namespace std;

class A
{
};
int powerTwo(int n)
{
    if (n == 1)
    {
        return 2;
    }
    if (n == 0)
    {
        return 1;
    }
    return 2 * powerTwo(n - 1);
}
int main()
{
    cout << powerTwo(0) << endl;
    return 0;
}