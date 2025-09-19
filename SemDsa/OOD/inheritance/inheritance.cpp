#include <bits/stdc++.h>
using namespace std;
class human
{
    int age;
    string name;
protected:
    char gender;
    char married;
public:
    int height;
    int birthDay;
    human(int age, string name, int birthDay, int height, char gender, char married);
    human(int age, string name, int birthday, int height, char gender);
    void printInformation();
};

class male : public human
{
private:
    int speed;

public:
    male(string name, int age, int birthDay, char gen, char married, int height, int speed);
};
class female : private human
{
private:
    int noBabies;
    string fatherName;

public:
    female(string name, int age, int birthDay, char gen, char married, int height, int speed, int babies, string fatherName);
    void printInformation();
};
class child : protected human
{
private:
    int innocentIndex;

public:
    child(string name, int age, int birthday,int innocentIndex,int height,char gend);
    void printInformation();
};
child ::child(string name, int age, int birthDay,int innocentIndex,int height,char gend):human(age,name,birthDay,height,gend){
    this->innocentIndex=innocentIndex;
}
void child::printInformation()
{
    human::printInformation();
    cout<<"InncentIndex : "<<innocentIndex<<endl;
}
female::female(string name, int age, int birthDay, char gen, char marreid, int hegith, int speed, int babies, string fatherName) : human(age, name, birthDay, height, gender, married)
{
    this->noBabies = babies;
    this->fatherName = fatherName;
}
void female::printInformation()
{
    human::printInformation();
    cout << "No Of Babies : " << noBabies << endl;
    cout << "Father Name  : " << fatherName << endl;
}
male::male(string name, int age, int birday, char gen, char married, int height, int speed) : human(age, name, birday, height, gender, married)
{
    this->speed = speed;
}
human::human(int age, string name, int bithday, int height, char gender, char married)
{
    this->age = age;
    this->gender = gender;
    this->married = married;
    this->height = height;
    this->name = name;
    this->birthDay = bithday;
    this->married='N';
}
human::human(int age,string name,int birthDay,int height,char gend)
{
    this->age=age;
    this->name=name;
    this->birthDay=birthDay;
    this->height=height;
    this->gender=gend;
}
void human::printInformation()
{
    cout << "Name : " << name << endl;
    cout << "Age  : " << age << endl;
    cout << "BirthDay : " << this->birthDay << endl;
    cout << "Gender : " << gender << endl;
    cout << "Height : " << height << endl;
    cout << "Married : " << married << endl;
}
int main()
{
    human name(23, "Habib", 2004, 5, 'M', 'N');
    child ali("Ali",12,2013,1,4,'M');
    ali.printInformation();
    // name.printInformation();
    return 0;
}
