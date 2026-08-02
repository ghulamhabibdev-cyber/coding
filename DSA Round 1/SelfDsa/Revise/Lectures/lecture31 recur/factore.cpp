#include <iostream>
using namespace std;
int fact(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    int choti = fact(n - 1);
    int badi = n * choti;
    return badi;
}
int pow(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return 2 * pow(n - 1);
}
void printCount(int n)
{
    if (n == 0)
    {
        return;
    }
    printCount(n - 1);
    cout << n << endl;
}
void reachHome(int src, int dest)
{
    cout << "Source : " << src << " Destination : " << dest << endl;
    if (src > dest)
    {
        src--;
        reachHome(src, dest);
        return;
    }

    if (src == dest)
    {
        cout << "Reached At Home \n";
        return;
    }
    src++;
    reachHome(src, dest);
}
int main()
{
    cout << fact(5) << endl;
    // cout << pow(3) << endl;
    // printCount(100);
    int src = -100;
    int dest = -1000;
    reachHome(src, dest);
    return 0;
}
