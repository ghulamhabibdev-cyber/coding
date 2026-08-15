#include <iostream>
using namespace std;

class A
{
};
int countOneBit(int n)
{
    int count = 0;
    while (n > 0)
    {
        count++;
        n = n & (n - 1);
    }
    return count;
}
int main()
{
    int count = countOneBit(15);
    cout << count << endl;
    return 0;
}