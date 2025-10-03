#include<bits/stdc++.h>
using namespace std;
int main(){
    int day,year,month;
    bool flagmonth=false;
    bool yeaFlag=false;
    int months[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    cout<<"Enter day: ";
    cin>>day;
    cout<<"Enter Month : ";
    cin>>month;
    cout<<"ENter Year : ";
    cin>>year;
    if(month>=1&&month<=12){
        flagmonth=true;
    }

    else{
        cout<<"Wrong Month";
        return 0;

        
        
    }
    if(year%4==0&&year%100!=0||year%400==0){
        yeaFlag=true;
        months[1]=29;
        
    }

    if(flagmonth==true&&day>=1&&day<=months[month-1]){
        cout<<day<<"/"<<month<<"/"<<year<<endl;
    }
    else{
        cout<<"Wrong date";
        return 0;
    }
    return 0;
}