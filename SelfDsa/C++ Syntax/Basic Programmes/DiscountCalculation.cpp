#include <iostream>
using namespace std;
double DiscountCalculation(double price)
{
    double discountForLess100 = 0.05;
    double discountForMore100 = .10;
    double discountForAbove500 = .20;
    double totalBill = 0;
    if (price < 0)
    {
        cout << "Check Price : " << price;
        return 0;
    }
    if (price >= 0 && price <= 100)
    {
        totalBill = price - price * discountForLess100;
        return totalBill;
    }
    else if (price <= 500)
    {
        totalBill = price - price * discountForMore100;
        return totalBill;
    }
    else
    {
        totalBill = price - price * discountForAbove500;
        return totalBill;
    }
}
int main()
{
    double price;
    cout << "Enter Price : ";
    cin >> price;
    double discountPrice = DiscountCalculation(price);
    cout << "Bill After Discount : " << discountPrice <<endl;
    return 0;
}