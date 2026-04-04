#include <iostream>
using namespace std;

class A
{
};
void decToBinary(int n)
{
    char ch[33] = {'0'};
    int ans = 0;
    cout << ch << endl;
    int pow = 1;
    for (int i = 0; i < 32; i++)
    {
        if (n & i != 0)
        {
            ch[31 - i] = '1';
            int bit = n % 2;
            ans += bit * pow;
        }
        else
        {
            ch[31 - i] = '0';
        }
        pow *= 10;
        n >>= 1;
    }
    cout << ans << endl;
    cout << ch << endl;
}
int main()
{
    decToBinary(10);

    return 0;
}