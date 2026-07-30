#include <iostream>
using namespace std;

class A
{
};
bool casmirString(string str)
{
    int aCount = 0;
    int bCount = 0;
    int cCount = 0;
    for (char ch : str)
    {
        if (ch == 'A')
        {
            aCount++;
        }
        else if (ch == 'B')
        {
            bCount++;
        }
        else if (ch == 'C')
        {
            cCount++;
        }
    }
    return bCount == (aCount + cCount);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        if (casmirString(str))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}