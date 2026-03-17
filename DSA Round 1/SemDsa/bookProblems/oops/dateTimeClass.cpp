#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;
class dateTime
{
private:
    int dDay;
    int dMonth;
    int dYear;
   static int monthArr[] = {0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string monthStrArray[] = {"errot",
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"};
    string weekStrArray[] = {"error",
        "Sunday", "Monday", "Tuesday", "Wednesday",
        "Thursday", "Friday", "Saturday"};

public:
    void setDate(int month, int day, int year);
    int getDay();
    int getMonth();
    int getYear();
    int noOfDayInMonth(int monthNo);
    void printDate();
    void setMonth(int month);
    void setDay(int day);
    void setYear(int year);
    dateTime(int month = 1, int day = 1, int year = 1900);
    int getNoPassedDay();
    int getNoRemainDayOfYear();
    string drawNewDate(int noOfDays);

private:
    bool isValidYear(int year);
    bool isLeap(int year);
    bool isValidMonth(int month);
};
string dateTime::drawNewDate(int noOfDays)
{
   int remainingDays=monthArr[dMonth-1]-dDay;
   int sum=0;
   sum+=remainingDays;
   int i=dMonth;
   while(sum<noOfDays)
   {
    sum+=monthArr[i];
    i++;
   }
   int date = (noOfDays - sum);
    string newData= to_string(i) + "/" +to_string(date) + "/" +to_string(dYear);
    return newData;
}
int dateTime::getNoRemainDayOfYear()
{
    int noPassedDay = getNoPassedDay();
    int remainDays = 0;
    if (isLeap(this->dYear))
    {
        remainDays = 366 - noPassedDay;
    }
    else
    {
        remainDays = 365 - noPassedDay;
    }
    return remainDays;
}
int dateTime::getNoPassedDay()
{
    int noOfPassDays = 0;
    for (int i = 1; i < dMonth; i++)
    {
        noOfPassDays += monthArr[i - 1];
    }
    noOfPassDays += dDay;
    if (isLeap(dYear) && dMonth > 2)
    {
        noOfPassDays += 1;
    }
    // noOfPassDays += dDay;
    return noOfPassDays;
}
int dateTime::noOfDayInMonth(int monthNo)
{
    if (isValidMonth(monthNo))
    {
        return monthArr[monthNo - 1];
    }
    else
    {
        return 0;
    }
}
int dateTime::getYear()
{
    return this->dYear;
}
int dateTime::getMonth()
{
    return this->dMonth;
}
int dateTime::getDay()
{
    return this->dDay;
}
void dateTime::setYear(int year)
{
    setDate(this->dMonth, this->dDay, year);
}
void dateTime::setMonth(int month)
{
    setDate(month, this->dDay, this->dYear);
}
void dateTime::setDay(int day)
{
    setDate(this->dMonth, day, this->dYear);
}
// constructor
void dateTime::printDate()
{
    if (dMonth < 10)
    {
        cout << "0" << dMonth << "\\";
    }
    else
    {
        cout << dMonth << "\\";
    }
    if (dDay < 10)
    {
        cout << "0" << dDay << "\\" << dYear;
    }
    else
    {
        cout << dDay << "\\" << dYear << endl;
    }
}
dateTime::dateTime(int month, int day, int year)
{
    setDate(month, day, year);
}
bool dateTime::isValidMonth(int month)
{
    if (month >= 1 && month <= 12)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool dateTime::isValidYear(int year)
{
    if (year >= 1900 && year <= 4000)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool dateTime::isLeap(int year)
{
    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void dateTime::setDate(int month, int day, int year)
{
    if (isValidMonth(month))
    {
        this->dMonth = month;
        if (month == 2 && isLeap(year))
        {
            if ((day >= 1 && day <= 29))
            {
                this->dDay = day;
            }
            else
            {
                this->dDay = 1;
            }
        }
        else
        {
            if (month == 2 && day < 28)
            {
                this->dDay = day;
            }
            else
            {
                if (month == 2)
                {
                    this->dDay = 1;
                }
                else
                {
                    if (day <= monthArr[month - 1])
                    {
                        this->dDay = day;
                    }
                }
            }
        }
    }
    else
    {
        this->dMonth = 1;
        this->dDay = 1;
    }
    if (isValidYear(year))
    {
        this->dYear = year;
    }
    else
    {
        this->dYear = 1900;
    }
}
int main()
{
    dateTime dt(3, 3, 2025);
    // dt.printDate();
    int month = 2;
    // cout << "NO Days In : " << month << "  :  " << dt.noOfDayInMonth(month) << endl;
    // cout << "NO OF PASSED : " << dt.getNoPassedDay() << endl;
    // cout << "No remain Day : " << dt.getNoRemainDayOfYear();
    cout<<dt.drawNewDate(50);
    // dt.printDate();

    return 0;
}
