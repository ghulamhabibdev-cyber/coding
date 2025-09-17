#include<bits/stdc++.h>
using namespace std;
class  clockTypes
{
    private:
        int sec;
        int min;
        int hours;
    public:
        void printTime();
        void setTime(int sec,int min,int hours);
        void getTime(int &sec,int & min,int &hour);
        bool equalTime(clockTypes &ohterclock);
        void incrementHour();
        void incrementSec();
        void incrementMin();
        string getTime();
        clockTypes(int sec,int min,int hours);
};
void clockTypes::setTime(int sec,int min,int hours)
{
    if((0<=sec &&sec<60))
    {
        this->sec=sec;
        
    }
    else{
        this->sec=0;
    }
    
    if( (0<=min &&min<60) )
    {
        this->min=min;
    }
    else{
        this->min=0;
    }
    if(0<=hours &&hours<24)
    {
        this->hours=hours;
    }
    else{
        this->hours=0;
    }
}
clockTypes::clockTypes(int sec,int min,int hour)
{
    setTime(sec,min,hour);
}
void clockTypes::printTime()
{
    if(hours<10)
    {
        cout<<0;
    }
    cout<<hours<<" : ";
    if(min<10)
    {
        cout<<0;
    }
    cout<<min <<" : ";
    if(sec<10)
    {
        cout<<0;
    }
    cout<<sec<<endl;
}


int main()
{
    clockTypes habib(2,20,12);
    cout<<"Helo\n";
    habib.printTime();

    return 0;
}
