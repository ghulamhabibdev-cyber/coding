#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <climits>
#include <list>
using namespace std;
class clockType
{
protected:
    int hr;
    int mintue;
    int sec;

public:
    void setTime(int hr, int min, int sec);
    void getTime(int &hr, int &min, int &sec);
    void printTime();
    void incrementSec();
    void incrementMin();
    void incrementHr();
    bool equalTime(clockType &cl);
    clockType(int hr, int min, int sec);
    clockType();
};
class extClockType : public clockType
{
private:
    string timeZone;

public:
    void setTimeZone(string timeZone);
    string getTimeZone();
    extClockType();
    extClockType(int hr, int min, int sec, string timeZone);
    void printTime();
};
void extClockType::printTime()
{
    clockType::printTime();
    cout<<"Time zone : "<<timeZone<<endl;
}
extClockType::extClockType(int hr, int min, int sec, string timeZone) : clockType(hr, min, sec)
{
    this->timeZone = timeZone;
}
extClockType::extClockType()
{
    this->hr = 0;
    this->mintue = 0;
    this->sec = 0;
    this->timeZone = "Islambad";
}
string extClockType::getTimeZone()
{
    return this->timeZone;
}
void extClockType::setTimeZone(string timeZone)
{
    this->timeZone = timeZone;
}
bool clockType::equalTime(clockType &cl)
{
    if (this->hr == cl.hr && this->mintue == cl.mintue && this->sec == cl.sec)
    {
        return true;
    }
    return false;
}
void clockType::incrementSec()
{
    sec++;
    if (sec > 59)
    {
        sec = 0;
    }
}
void clockType::incrementMin()
{

    mintue++;
    if (mintue > 59)
    {
        mintue = 0;
    }
}
void clockType::incrementHr()
{
    hr++;
    if (hr > 24)
    {
        hr = 0;
    }
}
void clockType ::printTime()
{
    cout << "Hour : " << this->hr << endl;
    cout << "Minute : " << this->mintue << endl;
    cout << "second : " << this->sec << endl;
}
void clockType::getTime(int &hr, int &min, int &sec)
{
    hr = this->hr;
    min = this->mintue;
    sec = this->sec;
}
void clockType::setTime(int hr, int min, int sec)
{
    this->hr = hr;
    this->mintue = min;
    this->sec = sec;
}
clockType::clockType()
{
    this->hr = 0;
    this->mintue = 0;
    this->sec = 0;
}
clockType::clockType(int hr, int min, int sec)
{
    this->hr = hr;
    this->mintue = min;
    this->sec = sec;
}
int main()
{
    clockType cl(10, 10, 10);
    extClockType cl2(12, 10, 23, "Dubai");
    cl2.printTime();
    // cl.printTime();

    cout << "Hello World\n";
    return 0;
}
