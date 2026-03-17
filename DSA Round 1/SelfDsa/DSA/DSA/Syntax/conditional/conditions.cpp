#include<bits/stdc++.h>
using namespace std;
int main()
{
    // int marks;
    // cout<<"Enter Marks : ";
    // cin>>marks;
    // char grade;
    // if(marks<60){
    //     grade='F';
    // }
    // else if(marks<69){
    //     grade='D';
    // }
    // else if (marks<79)
    // {
    //     grade='C';
    // }
    // else if(marks<89){
    //     grade='B';
    // }
    // else if(marks<=100){
    //     grade='A';
    // }
    // cout<<grade;
    // int balance,drawAmount;
    // cout<<"Enter Balance : ";
    // cin>>balance;
    // cout<<"Enter WithDraw Amount : ";
    // cin>>drawAmount;
    // if(drawAmount<=balance){
    //     balance=balance-drawAmount;
    //     cout<<balance;
    // }
    // else{
    //     cout<<"Draw Amount Is more  :";
    // }
    // int year;
    // cout<<"Enter Year (yyyy)\n";
    // cin>>year;
    // if(year%4==0&&year%100!=0||year%400==0){
    //     cout<<"Leap Year : "<<year<<endl;
    // }
    // else{
    //     cout<<year<<"Not leap\n";
    // }
    // int age;
    // cout<<"Enter Your age :";
    // cin>>age;
    // if(age<18){
    //     cout<<"You are Not  eligible ";

    // }
    
    // else if(age<=57){
    //     cout<<"Eligible for job";
    //     if(age>=55){
    //         cout<<"retirment soon";
    //     }
    // }
    // else{
    //     cout<<"Retirment time ";
    // }
    int side1,side2,side3;
    cout<<"Enter sides : ";
    cin>>side1>>side2>>side3;
    if(side1+side2>side3){
        cout<<"trianle";
    }
    else if(side2+side3>side1){
        cout<<"trianle";

    }
    else if(side1+side3>side2){
        cout<<"trianel";
    }


}