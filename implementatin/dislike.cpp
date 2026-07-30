#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int k;
        cin >> k;

        int count = 0;
        int x = 1;

        while (true)
        {
           
            if (x % 3 != 0 && x % 10 != 3)
            {
                count++;
                if (count == k)
                {
                    cout << x << endl;
                    break;
                }
            }
            x++;
        }
    }

    return 0;
}
