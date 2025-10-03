#include<iostream>
using namespace std;
void myBoolFunction(){
    bool myBool;
    int num1;int num2;
    cout<<"Enter A number : \n";
    cin>>num1;
    cout<<"Enter Antoher Number :\n";
    cin>>num2;
    myBool=num1>num2;
    cout<<"My Bool IS : "<<myBool<<endl;
    cout<<"ENtre A number :\n";
    cin>>num1;
    cout<<"Enter Another Number : \n";
    cin>>num2;
    myBool=(num1>num2)&&(num1<num2);
    cout<<"My Bool IS : "<<myBool<<endl;
}
void myBoolChecker()
{
    int num1=23;
    int num2=21;
    bool myBool;
    myBool=num1!=num2;
    cout<<"My Bool IS : "<<myBool<<endl;
    myBool=num1==num2;
    cout<<"My Bool IS : "<<myBool<<endl;
}
void myBitwise()
{
    int num1=23;
    int num3=24;
    int num2=num2&num1;
    cout<<"my bitwise : "<<num2;
}
void boolChe()
{
    int num2=12;
    int num3=23;
   
}
void myCondition()
{
    int num1=123;
    int num2=2223;
    if(num1>num2)
    {
        cout<<"my Num1>num 2";
    }
    else{
        if(num1==num2)
        {
            cout<<"NUmber are equal : ";
        }
        else{
            cout<<"num<num2";
        }
    }
}
void myInterest()
{
    double amount=1000;
    double interest=5;
    int year=0;;
    cout<<"ENter gain amount :\n";
    double Interestedamount;
    cin>>Interestedamount;
    int myInterest=1+(interest/100);
    while(amount <=Interestedamount){
        amount*=1.5;
        year++;
    }
    cout<<"yaear requirs : "<<year<<endl;
    cout<<"My amount : "<<amount<<endl;
}
int main()
{
    // myBoolFunction();
    // myBoolChecker();
    // myBitwise();
    // myCondition();
    myInterest();
}