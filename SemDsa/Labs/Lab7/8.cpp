#include <iostream>
using namespace std;
int sumOfnNumbers(int n)
{
    if (n == 1)
    {
        return 1;
    }
    int ans = n + sumOfnNumbers(n - 1);
    return ans;
}
int main()
{
    int n;
    cout << "Enter the No \n";
    cin >> n;
    int ans = sumOfnNumbers(n);
    cout << ans << endl;

    return 0;
}
