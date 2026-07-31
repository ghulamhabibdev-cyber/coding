#include <bits/stdc++.h>
using namespace std;
class Person
{
private:
    string pname;
    int page;
    static int pno;

public:
    Person(string name, int age)
    {
        this->pname = name;
        this->page = age;
        cout << pno << endl;
        pno++;
    }
    void printInformation()
    {
        cout << "Name : " << pname << endl;
        cout << "age  :" << page << endl;
    }
    static int Sum(int n,int n2)
    {
        return (n+n2);
    }
};
int Person ::pno = 1;
int main()
{
    Person p1("habib", 22);
    p1.printInformation();
    Person p3("ali",34);
    p3.printInformation();
    cout<< Person::Sum(34,43);
     return 0;
}
