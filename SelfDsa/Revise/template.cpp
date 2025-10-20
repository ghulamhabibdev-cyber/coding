#include <iostream>
using namespace std;

int main()
{
    int num;
    cout << "Enter a positive number: ";
    cin >> num;

    if (num < 0)
        goto negative; // jump to label 'negative'

    cout << "You entered a positive number." << endl;
    return 0;

negative: // label
    cout << "You entered a negative number!" << endl;
    cout << "enter \n";
    return 0;
}
