#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a = 324;
    char b = 'd';
    bool found = false;
    float num = 34.4;
    double pi = 3.1459;
    cout << a << b << endl;
    cout << "Size of a : " << sizeof(a) << " byte  Size of b : " << sizeof(b) << " byte   Size of num : " << sizeof(num) << " byte   size of double pi " << sizeof(pi) << " byte   Size of bool : " << sizeof(found) << " byte" << endl;
    int size = sizeof(a); // size ccan be stroe in int
    cout << size << endl;
    // asci working
    
    char c = 'A';       // Character A
    int asciiValue = c; // Convert to ASCII integer
    cout << "Character: " << c << ", ASCII: " << asciiValue << endl;

    return 0;
}
