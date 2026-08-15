#include <iostream>
using namespace std;
void bittValIncDex(string type, int &val)
{
    if (type.find("++") != string::npos)
    {
        ++val;
    }
    else
    {
        --val;
    }
}
int main()
{
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        string expres;
        cin >> expres;

        bittValIncDex(expres, ans);
    }
    cout << ans << endl;
    return 0;
}