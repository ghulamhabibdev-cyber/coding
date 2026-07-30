#include <iostream>
using namespace std;

class A
{
};
void printEven(int n)
{
    if (n % 2 == 1)
    {
        n = n - 1;
    }
    if (n < 0)
    {
        return;
    }

    if (n == 0)
    {
        cout << n << endl;
        return;
    }

    printEven(n - 2);
    cout << n << endl;
}
void printWithThinking(int n)
{
    if(n==2)
    {
        cout<<n<<endl;
        return;
    }
    printWithThinking(n-2);
    cout<<n<<endl;
}
int main()
{
    int n;
    cin>>n;
    // printEven(n);
    printWithThinking(n);

    return 0;
}