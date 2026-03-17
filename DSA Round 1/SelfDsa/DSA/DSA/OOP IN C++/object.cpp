#include <bits/stdc++.h>
using namespace std;
class Hero
{
private:
    string name;
    int age;

public:
    Hero(string n, int a)
    {
        cout<<"adrees of Obj : "<<this<<endl;
        this->name = n;
        this->age = a;
    }
    // Hero(Hero &h)
    // {
    //     name=h.name;
    //     age=h.age;
    // }
    Hero()
    {
       cout<<"adrees of Obj : "<<this<<endl;
        cout << " I Am default constructor : \n";
    }
    void Print()
    {
        cout << "Name : " << name << endl;
        cout << "Age  : " << age << endl;
    }
    void SetName(string name)
    {
        this->name = name;
    }
    void SetAge(int age)
    {
        this->age=age;
    }
    int getAge()
    {
        return age;
    }
    string Getname()
    {
        return name;
    }
};

int main()
{
    // Hero a("habib", 20);
    // a.Print();
    // a.SetAge(10);
    // a.Print();
    // cout<<"A NAME : " << a.Getname()<<endl;
    // cout<<a.Print();
    // cout<<"Adess :of a : "<<&a<<endl;
    // Hero *b=new Hero("Galab",32);
    // // b->SetName("ALi");
    // // b->SetAge(13);
    // b->Print();
    // cout << sizeof(a) << endl;
    // Hero ali(a);
    // a.Print();
    // return 0;
    // Hero ba("Habib",34);
    // Hero ab(ba);
    // ab.Print();



    //shallow and deep copy 
    Hero aliAhmad("ali ahmad",23);
    // Hero tyab=aliAhmad;
    Hero ali(aliAhmad);
    ali=aliAhmad;
    aliAhmad.SetName("Qayam");
    // tyab.Print();
    // tyab.SetName("Hassan");
    aliAhmad.Print();
    // tyab.Print();
    ali.Print();
    ali.SetName("XYX");
    aliAhmad.Print();
    ali.Print();
}
