#include <iostream>
using namespace std;

class A
{
};
void printEven(int n)
{
    if (n == 2)
    {
        cout << n << endl;
        return;
    }
    cout << n << " ";
    printEven(n - 2);
}
int main()
{
    printEven(16);

    return 0;
}