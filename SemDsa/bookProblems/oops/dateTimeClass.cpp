#include <bits/stdc++.h>
using namespace std;
class dateTime
{
    static string dayArray;
    string currentDay;
    string stdDay="Thursday";

public:
    void setCurrentDay(string day);
    void setCurrentDate(int date,int month,int year);
    string getCurrentDate();
    void displayDate();
    void displayDay();
};

int main()
{

    return 0;
}
