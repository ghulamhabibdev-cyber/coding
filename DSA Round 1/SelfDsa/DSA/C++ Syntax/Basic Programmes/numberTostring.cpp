#include <iostream>
using namespace std;
void numberToString()
{
    int number;
    string word;
    int remind;
    char chr;
    cout << "Enter A Number : " << endl;
    cin >> number;

    while (number != 0)
    {
        remind = number % 10;
        chr = remind;
        word += chr+'0';
        number=number/10;
    }
    cout << "Word : " << word << endl;
}
int main()
{
    numberToString();
    return 0;
}