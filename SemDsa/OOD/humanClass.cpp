#include <bits/stdc++.h>
using namespace std;
class human
{
private:
    int age;
    string name;
    char gender;
    bool status;
    static int rand;
    int universalIdentityNo;

protected:
    int age;
    string name;

public:
    void printInfo();
    bool checkAge(human adam);
    void happyBirthday();
    void isLive();
    void setDead();
    human(int age, string name, bool status, );
};
class male:human
{

};
human::human() ;
int human::rand = 0;
int main()
{
    return 0;
}
