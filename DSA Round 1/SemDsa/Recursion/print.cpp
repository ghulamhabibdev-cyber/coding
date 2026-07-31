#include <iostream>
using namespace std;

class A
{
};
void printValue(int n)
{
    if (n < 1)
    {
        return;
    }
    printValue(n - 1);
    cout << n << endl;
}
int main()
{
    int n;

    cout << "Enter a Number \n";
    cin >> n;
    printValue(n);

    return 0;
}