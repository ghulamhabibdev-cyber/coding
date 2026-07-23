#include <iostream>
using namespace std;

class A
{
};
void happyBirht(int days)
{
    if (days == 0)
    {
        cout << "Happy Birthday to you" << endl;
        return;
    }
    if (days == 1)
    {
        cout << days << " day left for birthday" << endl;
    }
    else
    {
        cout << days << " days left for Birthday " << endl;
    }
    happyBirht(days - 1);
}
int main()
{

    int i = 0;
    happyBirht(5);
    // main(n);

    return 0;
}