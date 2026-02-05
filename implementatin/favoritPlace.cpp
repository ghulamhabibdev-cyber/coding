#include <iostream>
#include <algorithm>
#include <numeric> // for gcd
using namespace std;

int main()
{
    int yako, wako;
    cin >> yako >> wako;

    int maxi = max(yako, wako);

    int numerator = 7 - maxi;
    int denominator = 6;

    if (numerator <= 0)
    {
        cout << "0/1";
        return 0;
    }

    int g = gcd(numerator, denominator);
  
    numerator /= g;
    denominator /= g;

    cout << numerator << "/" << denominator;
    return 0;
}
