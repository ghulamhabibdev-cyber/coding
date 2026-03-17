#include <bits/stdc++.h>
using namespace std;
class freindFuncHandler
{
private:
    string name;
    int age;
    friend void friendy(freindFuncHandler &f);

public:
    freindFuncHandler()
    {
    }
    freindFuncHandler(string name, int age);
    void printData();
};
freindFuncHandler::freindFuncHandler(string name, int age)
{
    this->name = name;
    this->age = age;
}
void freindFuncHandler::printData()
{
    cout << "Name : " << name << endl;
    cout << "Age  : " << age << endl;
}
void friendy(freindFuncHandler &f)
{
    f.printData();
    freindFuncHandler nf;
    int x = 10;
    string name = "Habib";
    nf.age = x;
    nf.name = name;
    nf.printData();
}
int main()
{
    freindFuncHandler ali("Habib", 30);
    ali.printData();
    friendy(ali);
    cout << "Hello World\n";

    return 0;
}
