#include <iostream>
#include <any>
#include <string>
using namespace std;

any returnME()
{
    any i;
    int ch;
    string ali="123";

    cout << "1 for int, 2 for string: ";
    cin >> ch;

    if (ch == 1)
        i = 0;
    else
        i = string("ali");
    return i;
}

int main()
{
    any value = returnME();

    if (value.type() == typeid(int))
        cout << any_cast<int>(value);

    else if (value.type() == typeid(string))
        cout << any_cast<string>(value);
}
