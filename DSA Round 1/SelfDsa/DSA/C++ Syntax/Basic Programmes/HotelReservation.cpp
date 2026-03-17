#include <iostream>
using namespace std;
void HotelReservation()
{
    int totalDaysToStay;
    double totalDicount;
    double total;
    int choise;
    cout << "1>Single room: $100 per night" << endl;
    cout << "2>Double room: $150 per night" << endl;
    cout << "3>Suite:  $300 per night" << endl;
    cin >> choise;
    cout << "Enter Total Staying days : " << endl;
    cin >> totalDaysToStay;
    if (choise == 1)
    {
        if (totalDaysToStay > 7)
        {
            total = 100 - (100 * .10);
            total = total * totalDaysToStay;
            cout << "Total Bill For : " << totalDaysToStay << " Is " << total << endl;
        }
        if (totalDaysToStay > 14)
        {
            total = 100 - (100 * .15);
            total = total * totalDaysToStay;
            cout << "Total Bill For : " << totalDaysToStay << " Is " << total << endl;
        }
        else
        {
            total = 100 * totalDaysToStay;
            cout<<"Total Bill : "<<total;
        }
    }
    if (choise == 2)
    {
        if (totalDaysToStay > 7)
        {
            total = 150 - (150 * .10);
            total = total * totalDaysToStay;
            cout << "Total Bill For : " << totalDaysToStay << " Is " << total << endl;
        }
        if (totalDaysToStay > 14)
        {
            total = 150 - (150 * .15);
            total = total * totalDaysToStay;
            cout << "Total Bill For : " << totalDaysToStay << " Is " << total << endl;
        }
        else
        {
            total = 150 * totalDaysToStay;
            cout<<"Total Bill : "<<total;
        }
    }
    if (choise == 3)
    {
        if (totalDaysToStay > 7)
        {
            total = 300 - (300 * .10);
            total = total * totalDaysToStay;
            cout << "Total Bill For : " << totalDaysToStay << " Is " << total << endl;
        }
        if (totalDaysToStay > 14)
        {
            total = 300 - (300 * .15);
            total = total * totalDaysToStay;
            cout << "Total Bill For : " << totalDaysToStay << " Is " << total << endl;
        }
        else
        {
            total = 300 * totalDaysToStay;
            cout<<"Total Bill : "<<total;
        }
    }
}
int main()
{
    HotelReservation();
    return 0;
}