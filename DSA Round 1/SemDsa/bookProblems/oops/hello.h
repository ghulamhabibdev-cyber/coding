#include<bits/stdc++.h>
using namespace std;
class person
{
    private:
    int age;
    string name;
    public:
    person(string name,int  age)
    {
        this->age=age;
        this->name=name;
    }
    void setName(string name)
    {
        
        this->name=name;
    }
    void setAge(int age)
    {
        this->age=age;
    }
    int getAge()
    {
        return age;
    }
    string getName()
    {
        return name;
    }
    void print()
    {
        cout<<"Name  : "<<name<<endl;
        cout<<"Age   : "<<age<<endl;
    }
};
void print(auto val)
{
    cout<<val<<endl;
}
