#include <iostream>
using namespace std;
string lowerToUpperCase(string str)
{
    int start;
    int i = 0;
    while (str[i] != '\0')
    {
        start = str[i] - 32;

        if (start >= 65 && start <= 90)
        {
            char a = start;
            str[i] = a;
        }
        i++;
    }

    return str;
}
string UpperToLowerCase(string str)
{
    int start;
    int i = 0;
    while (str[i] != '\0')
    {
        start = str[i] + 32;

        if (start >= 97 && start <= 122)
        {
            char a = start;
            str[i] = a;
        }
        i++;
    }

    return str;
}

char UperTolower(char a)
{
    if (a >= 65 && a <= 90)
    {
        // A:65 Z : 90 a : 97 z : 122 a->a
        a = a + ('a'-'A');
    }
    
    return a;
}
char lowerToUper(char a)
{
    if (a >= 97 && a <= 122)
    {
        // A:65 Z : 90 a : 97 z : 122 a->a
        a = a  +('A'-'a');
    }
    
    return a;
}
// string Capilize(string str)
// {

// }
int main()
{ // A:65 Z : 90 a : 97 z : 122 a->a
    // cout << lowerToUpperCase("HabiB");
    // string str;
    // cout << "Enter your Text : \n";
    // getline(cin, str);
    // cout << lowerToUpperCase(str) << endl;
    // cout << UpperToLowerCase(str) << endl;
    cout<<UperTolower('c')<<endl;
    cout<<lowerToUper('c');

    // char a = 'a';
    // char A = 'A';
    // char z = 'z';
    // char Z = 'Z';
    // int avalue = a;
    // int Avalue = A;
    // int zvalue = z;
    // int Zvalue = Z;
    // cout << "\nA : " << Avalue << endl;
    // cout << "Z : " << Zvalue << endl;
    // cout << "a : " << avalue << endl;
    // cout << "z : " << zvalue << endl;
    // char az = 65 + 32;
    // cout << "a ->" << az;
}