#include <bits/stdc++.h>
using namespace std;
class human
{
private:
    char gender;
    bool status;
    static int rand;
    int universalIdentityNo;

protected:
    int age;
    string name;
    bool isMarried;

public:
    void printInfo();
    bool checkAge(human adam);
    void happyBirthday();
    void isLive();
    void setDead();
    void makeMarried();
    human(int age, string name, bool status,char geneder);
};
void human::makeMarried()
{
    this->isMarried = true;
}
human::human(int age, string name, bool status,char gen)
{
    this->age = age;
    gender=gen;
    this->name = name;
    this->status = status;
    isMarried = false;
    this->universalIdentityNo=rand;
    rand++;
}
class male : public human
{
private:
    bool hasJob;
    string jobType;
    double salary;
public:
    male(int age,string name,bool islive,char gend,bool hasJob,string jobTypes,double salary);
    void  printInfo();
};
class femal:public human
{


};
int human::rand = 1;
void human::printInfo()
{
    cout<<"Name         : "<<name<<endl;
    cout<<"Age          : "<<age<<endl;
    cout<<"Status       : "<<status<<endl;
    cout<<"Gender       : "<<gender<<endl;
    cout<<"Identity No  : "<<universalIdentityNo<<endl;
    cout<<"Married : "<<isMarried<<endl;
}
male::male(int age,string name,bool islive,char gend ,bool hasJob,string jobType,double salry):human(age,name,islive,gend)
{
    this->hasJob=hasJob;
    this->jobType=jobType;
    this->salary=salary;
}
void male::printInfo()
{
    human::printInfo();
    cout<<"Has Job : "<<hasJob<<endl;
    cout<<"JobType : "<<jobType<<endl;
    cout<<"Salary  : "<<salary<<endl; 
}
int main()
{
    human adam(10,"Adam",0,'M');
    adam.printInfo();

    return 0;
}
