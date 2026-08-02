#include <iostream>
using namespace std;

class A
{
};
int binaryToDecimal(int binary)
{
    int ans = 0;
    int pow = 1;
    while (binary > 0)
    {
        int bit = binary % 10;
        binary /= 10;
        ans += bit * pow;
        pow *= 2;
    }
    return ans;
}
int main()
{
    int binNumber = 1010;
    cout << binaryToDecimal(binNumber) << endl;

    return 0;
}