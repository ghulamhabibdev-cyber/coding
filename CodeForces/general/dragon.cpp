#include <iostream>
using namespace std;

class A
{
};
int dragonCount()
{
   
    int k, l, m, n, d;
    cin >> k >> l >> m >> n >> d;

    int count = 0;

    for (int i = 1; i <= d; i++)
    {
        if (i % k == 0 || i % l == 0 || i % m == 0 || i % n == 0)
        {
            count++;
        }
    }

    return count;
}
int main()
{
    int count = dragonCount();
    cout << count << endl;
    return 0;
}