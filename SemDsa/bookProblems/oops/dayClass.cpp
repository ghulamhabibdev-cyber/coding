#include <bits/stdc++.h>
#include<string>
#include<iostream>
using namespace std;
class dayType
{
private:
    static string dayArray[7];
    string CurrentDay;

public:
    void setDay(string day);
    void printDay();
    dayType(string day);
    dayType();
    string returnDay();
    string returnPrevDay();
    string returnNextDay();
    string findDay(int noOfDays);
};
string dayType::dayArray[7] = {"Sunday", "Monday", "Tuesday", "WensDay", "Thursday", "Frinday", "Saturday"};

dayType::dayType(string day)
{
    this->CurrentDay=day;
}

dayType::dayType()
{
    CurrentDay="SunDay";
}
string dayType::returnDay()
{
    return  CurrentDay;
}
string dayType::returnPrevDay()
{
    int currentIndex;
    for(int i=0;i<7;i++)
    {
        if(CurrentDay==dayArray[i])
        {
            currentIndex=i;
        }
    }
    if(currentIndex==0)
    {
        currentIndex=6;
        return dayArray[currentIndex];
    }
    string prevDay=dayArray[currentIndex-1];
    return prevDay;
}
string dayType::returnNextDay()
{
    int currentIndex;
    for(int i=0;i<7;i++)
    {
        if(CurrentDay==dayArray[i])
        {
            currentIndex=i;
        }
    }
    if(currentIndex==6)
    {
        currentIndex=0;
        return dayArray[currentIndex];
    }
    return dayArray[currentIndex+1];
}
string dayType::findDay(int noOfDays)
{
    int currentIndex;
    for(int i=0;i<7;i++)
    {
        if(CurrentDay==dayArray[i])
        {
            currentIndex=i;
        }

    }
    // the next days are current +nofdays
    int findingDay=currentIndex+noOfDays;
    int remind=findingDay%7;
    return dayArray[remind];
}

void dayType::setDay(string day)
{
    this->CurrentDay=day;
}
void dayType::printDay()
{
    cout<<"Current Day : "<<CurrentDay<<endl;
}

int main()
{
    dayType  currentDay ("Sunday");
    // cout<<"Prev day  : "<<currentDay.returnPrevDay()<<endl;
    // cout<<"Next Day : "<<currentDay.returnNextDay()<<endl;
    // cout << "Hello World\n";
    cout<<"NExt Days : "<<currentDay.findDay(100);

    return 0;
}
