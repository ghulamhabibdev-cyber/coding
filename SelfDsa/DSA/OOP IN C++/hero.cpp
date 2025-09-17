class Hero
{
private:
    string name;
    int age;

public:
    Hero(string n, int a)
    {
        this->name = n;
        this->age = a;
    }
    void Print()
    {
        cout<<"Name : "<<name<<endl;
        cout<<"Age  : "<<age<<endl;
    }
};