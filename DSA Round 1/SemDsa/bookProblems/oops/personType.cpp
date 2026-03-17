#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <climits>
#include <list>
using namespace std;
class personType
{
private:
    string firstName;
    string lastName;
    string middleName;

public:
    void setName(string name);
    void printName();
    string getName();
    void setFirstName(string firstName);
    void setLastTime(string lastName);
    string getLastTime();
    void setMiddleName(string mName);
    bool checkFirstName(personType &p);
    bool checkLastName(personType &p);
    personType();
    personType(string, string, string);
};
personType::personType(string fName, string mName, string lName)
{
    this->firstName = fName;
    this->middleName = mName;
    this->lastName = lName;
}
personType::personType()
{
    this->firstName = "";
    this->lastName = "";
    this->lastName = "";
}
bool personType::checkLastName(personType &p)
{
    this->lastName == p.lastName;
}
bool personType::checkFirstName(personType &p)
{
    return this->firstName == p.firstName;
}
void personType::setLastTime(string lName)
{
    this->lastName = lName;
}
void personType::setMiddleName(string mName)
{
    this->middleName = mName;
}
void personType::setFirstName(string fName)
{
    this->firstName = fName;
}
string personType::getName()
{
    return firstName + " " + middleName + " " + lastName;
}
void personType::printName()
{
    cout << "Name : " << this->firstName << " " << middleName << " " << lastName << endl;
}
void personType::setName(string name)
{
    this->firstName = name;
    this->middleName = "";
    this->lastName = "";
}
int main()
{
    personType p("ali", "Habib", "Ahmad");
    p.printName();

    cout << "Hello World\n";
    return 0;
}
