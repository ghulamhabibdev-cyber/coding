#include <iostream>
using namespace std;

class A
{
};
void unSetBit(int &n, int pos)
{
    int mask = 1 << pos;
    mask = ~mask;
    n = n & mask;
}
int main()
{
    int n = 7;
    unSetBit(n, 2);
    cout << n << endl;
    return 0;
}