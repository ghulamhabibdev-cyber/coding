#include <iostream>
using namespace std;
void UserNumberDigitSum()
{
    int number;
    int remind;
    int sum = 0;
    cout << "Enter Number : " << endl;
    cin >> number;
    while (number != 2)
    {
        remind = number % 10;
        number = number / 10;
        sum += remind;
        if(number==0)
        {
            cout<<"End";
            number=sum;
            cout<<number<<endl;
            sum=0;
        }
    }
    cout << "Sum Of Digits : " << sum << endl;
}
int main()
{

    UserNumberDigitSum();
    return 0;
}