#include<iostream>
using namespace std;
#define ENUM_TO_STRING(e)#e
void muEnum()
{
    enum week{
        sunday=1,
        monday,
        tuesday,
        wensday,
        thurseday,
        friday,
        satureday,
    };
    week day=friday;
    cout<<"Day Is : " <<day<<endl;
    enum compCode{
        error=470,
        Server=30,
        NotAvailable=34
    };
    compCode code=error;
    int num=473;
    code=(compCode)num;
    cout<<"Code : "<<code<<endl;

}
void MyEnum()
{
    enum Week{
        sun=1,
        mon,tue,wen,
        thur,fri,sat,
    };
    for(int week=1;week!=sat;week++)
    {
        cout<<week<<endl;
    }
    Week day=sun;
    cout<<ENUM_TO_STRING(sun)<<endl; 
}
int main()
{
    MyEnum();
}