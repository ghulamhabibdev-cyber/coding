#include <iostream>
using namespace std;

int totalDominos(int n, int m)
{
    return (n * m) / 2;
}

int main()
{
  
        int n, m;
        cin >> n >> m;
        cout << totalDominos(n, m) << endl;
    

    return 0;
}
