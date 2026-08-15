#include <iostream>
using namespace std;

class A
{
};
bool dangerous(string str)
{
    int n = str.length();
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if (str[i] == str[i - 1])
        {
            count++;
            if (count >= 7)
            {
                return true;
            }
        }
        else
        {
            count = 1;
        }
    }
    return false;
}
int main()
{
    string str;
    cin >> str;
    bool isDang = dangerous(str);
    if (isDang)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}