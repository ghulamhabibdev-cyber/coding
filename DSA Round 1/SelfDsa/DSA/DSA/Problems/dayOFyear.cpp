#include <bits/stdc++.h>
using namespace std;
int main()
{
    int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int day, month, year;
    int dayOfYear = 0;
    bool flagMonth = false;
    cout << "Enter Day :\n";
    cin >> day;
    cout << "Enter Month : \n";
    cin >> month;
    cout << "Entern Year : \n";
    cin >> year;
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        months[1] = 29;
    }
    if (month >= 1 && month <= 12)
    {
        flagMonth = true;
    }
    else
    {
        return 0;
    }
bool flag;
    if (day >= 1 && day <= months[month - 1] && flagMonth == true)
    {
        for (int i = 0; i < month - 1; i++)
        {
            dayOfYear += months[i];
        }
        dayOfYear += day;
        flag=true;

    }
    if(flag==true){

        cout << "Day of year : " << dayOfYear << endl;
        return 0;
    }
    cout<<"Wrong date : "<<endl;
    return 0;
}