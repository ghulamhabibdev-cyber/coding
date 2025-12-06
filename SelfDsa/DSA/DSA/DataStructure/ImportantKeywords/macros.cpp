#include <bits/stdc++.h>
using namespace std;
//objct like macros
#define pi 3.14
#define name "Habib"
//function like macros
#define Print(x) cout<<" Value : "<<x
//chain like macros
#define clerk 10
#define work clerk
// multline maros
#define printRec(width, length)         \
for (int i = 0; i < width; i++) {       \
    for (int j = 0; j < length; j++) {  \
        std::cout << "*";               \
    }                                   \
    std::cout << std::endl;             \
}

int main()
{
    // double area = 5 * 5 * pi;
    // cout << area << endl;
    // Print(area);
    // cout<<name<<endl;
    // Print(work);
    printRec(3,3);
    return 0;
}