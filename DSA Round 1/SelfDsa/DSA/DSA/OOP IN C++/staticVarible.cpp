#include <bits/stdc++.h>
using namespace std;
class hero
{
public:
    static int age;
    static int Randono()
    {
        cout << "Randome ";
        cout << "\nAge : " << age << endl;
    }
};
int hero::age = 5;
int main()
{
    cout << hero::age << endl;
    cout << hero::Randono();
    return 0;
}
