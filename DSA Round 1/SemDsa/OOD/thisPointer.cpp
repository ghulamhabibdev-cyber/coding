#include <bits/stdc++.h>
using namespace std;
class student
{
    string lastName;
    string firstName;

public:
    student(string firstName, string LastName);
    student()
    {
    }
    student& setFirstName(string name);
    student& setLastName(string LastName);
    student& print();
};
student::student(string firstName, string lastName)
{
    this->firstName = firstName;
    this->lastName = lastName;
}

student& student::setFirstName(string firstName)
{
    this->firstName=firstName;
    return *this;
}
student& student::setLastName(string lastName)
{
    this->lastName=lastName;
    return *this;
}
student& student::print()
{
    cout << "Name : " <<this->firstName << " " << this->lastName << endl;
}
int main()
{
    student std;
    std.setFirstName("Ghulam").setLastName("Habib").print();
    return 0;
}
