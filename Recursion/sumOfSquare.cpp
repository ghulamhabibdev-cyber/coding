#include <iostream>
using namespace std;

class A
{
};
int sumOfSquare(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n * n + sumOfSquare(n - 1);
}
int main()
{
    cout << sumOfSquare(3) << endl;

    return 0;
}