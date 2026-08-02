#include <iostream>
using namespace std;
void BillCalculculator(int unit)
{
    double chageForLower100 = 0.50;
    double chargeForAbove100 = 0.75;
    double  chargeForAboe300= 1.20;
    double totalBill = 0;
    if(unit<0){
        cout<<"Please Enter Valid Units  "<<endl;-
    }
    else if (unit>=0 && unit <= 100)
    {
        totalBill = unit * chageForLower100;
        cout << "Total Bill For unit : " << unit << " Is : " << totalBill << endl;
    }
    else if (unit <= 300)
    {
        totalBill = unit * chargeForAbove100;
        cout << "Total Bill For unit : " << unit << " Is : " << totalBill << endl;
    }
    else if(unit<=500)
    {
        totalBill = unit * chargeForAboe300;
        cout << "Total Bill For unit : " << unit << " Is : " << totalBill << endl;
    }
    else if(unit>500)
    {
        totalBill = unit * chargeForAboe300;
        totalBill+=totalBill*0.10;
        cout << "Total Bill For unit : " << unit << " Is : " << totalBill << endl;
    }
    
    
}
int main()
{
    cout << "Hell world";
    int unit;
    cout << "Enter Total No Of Units : ";
    cin >> unit;
    BillCalculculator(unit);
}