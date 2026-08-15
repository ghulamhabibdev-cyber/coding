#include <iostream>
using namespace std;

class A
{
};
void ToggleBit(int &n, int post)
{
    int mask = 1 << post;
    n = n ^ mask;
}
int main()
{
    int n = 8;
    ToggleBit(n, 3);
    cout << n << endl;
    return 0;
}