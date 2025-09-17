#include <iostream>
using namespace std;
void TickerBookingFunction()
{
    int choise;
    int noTicket;
    double total;
    cout << "1>Standard: $50" << endl;
    cout << "2>Premium: $100" << endl;
    cout << "3>VIP: $200" << endl;
    cout << "Chose Ticket Category " << endl;
    cin >> choise;
    cout << "How Many ticket Do You want to buy : " << endl;
    cin >> noTicket;
    if (choise == 1)
    {
        if(noTicket>5)
        {
            total=50-(50*.10);
            cout<<"Total Bill for "<<noTicket<< " Is : "<<total<<endl;
        }
        if(noTicket>10)
        {
            total=50-(50*.15);
            cout<<"Total Bill for "<<noTicket<< " Is : "<<total<<endl;
        }
        else{
            total=noTicket*50;
                        cout<<"Total Bill for "<<noTicket<< " Is : "<<total<<endl;

        }
    }
    if (choise == 2)
    {
         if(noTicket>5)
        {
            total=100-(100*.10);
            cout<<"Total Bill for "<<noTicket<< " Is : "<<total<<endl;
        }
        if(noTicket>10)
        {
            total=100-(100*.15);
            cout<<"Total Bill for "<<noTicket<< " Is : "<<total<<endl;
        }
        else{
            total=noTicket*100;
                        cout<<"Total Bill for "<<noTicket<< " Is : "<<total<<endl;

        }
    }
    if (choise == 3)
    {
         if(noTicket>5)
        {
            total=200-(200*.10);
            cout<<"Total Bill for "<<noTicket<< " Is : "<<total<<endl;
        }
        if(noTicket>10)
        {
            total=200-(200*.15);
            cout<<"Total Bill for "<<noTicket<< " Is : "<<total<<endl;
        }
        else{
            total=noTicket*200;
                        cout<<"Total Bill for "<<noTicket<< " Is : "<<total<<endl;

        }
    }
}

int main()
{

    TickerBookingFunction();
    return 0;
}