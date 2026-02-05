#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int mishkaWins = 0;
    int chrisWins = 0;

    for (int i = 0; i < n; i++)
    {
        int m, c;
        cin >> m >> c;

        if (m > c)
            mishkaWins++;
        else if (c > m)
            chrisWins++;
        // equal → no one gets a point
    }

    if (mishkaWins > chrisWins)
        cout << "Mishka";
    else if (chrisWins > mishkaWins)
        cout << "Chris";
    else
        cout << "Friendship is magic!^^";

    return 0;
}
