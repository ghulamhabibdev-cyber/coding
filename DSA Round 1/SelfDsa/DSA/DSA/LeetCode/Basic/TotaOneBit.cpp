#include <iostream>
using namespace std;
void CountTotalOneBit(int n)
{
    int count = 0;
    while (n != 0)
    {

        if (n & 1)
        {
            count++;
        }
        n = n >> 1;
    }
    cout << count << endl;
}
void CountTotalOneBit(int a, int b)
{
    int count = 0;
    while (a != 0 || b != 0)
    {
        if ((a & 1) && (b & 1))
        {
            count++;
        }
        if ((a & 1) || (b & 1))
        {
            count++;
        }
        a = a >> 1;
        b = b >> 1;

        /* code */
    }
    cout << count << endl;
}
int main()
{
    CountTotalOneBit(62 ,7);
}