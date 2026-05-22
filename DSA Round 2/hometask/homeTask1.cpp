#include <iostream>
using namespace std;

class A
{
};

int main()
{
    int number;
    cin >> number;
    // cout << (number << 31) << endl;
    if ((number & number - 1) == 0)
    {
        cout << "Two Power " << endl;
    }
    return 0;
}