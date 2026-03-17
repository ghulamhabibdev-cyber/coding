#include <iostream>
using namespace std;
void CheckTwoPower()
{
    int n;
    cout << "Enter No : ";
    cin >> n;
    int count = 0;
    int temp = n;
    while (n != 0)
    {
        n = n >> 1;
        if (n & 1)
        {
            count++;
        }
    }
    if (count == 1)
    {
        cout << temp << " Is Two Power";
    }
}
int main()
{
    CheckTwoPower();
}