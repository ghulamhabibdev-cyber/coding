#include <iostream>
using namespace std;
void NoTriangle()
{
    int n;
    cout << "Enter No : ";
    cin >> n;
    int i = 1;
    while (i <= n)
    {
        int j = 1;
        while (j <= i)
        {
            cout << j << " ";
            j++;
        }
        cout<<"\n";
        i++;

    }
}
int main()
{
    NoTriangle();
    return 0;
}