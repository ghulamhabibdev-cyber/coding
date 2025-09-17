#include <iostream>
using namespace std;
void ATMStimulation(double withdrawAmount)
{
    // balance is 10000
    double userBalance = 1000;
    
    
    
    if (withdrawAmount > 20.0 && int(withdrawAmount) % 10 == 0 && withdrawAmount <= userBalance)
    {
        userBalance = userBalance - withdrawAmount;
        cout << "Amount of " << withdrawAmount << " Is Withdraw From You Account : " << "Your Current Balance : " << userBalance << endl;
    }
    else{
        cout<<"Pleae Check the balnce : ";
    }
}
int main()
{
    int WithdrawAmount;
    cout << "Entre Withdraw Amount : " << endl;
    cin >> WithdrawAmount;
    ATMStimulation(WithdrawAmount);
    return 0;
}