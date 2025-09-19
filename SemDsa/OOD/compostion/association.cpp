#include <bits/stdc++.h>
using namespace std;
class tyres
{
    int model;

public:
    tyres()
    {

    }
    tyres(int model);
    void printInformation();
    void changeTyre(int m);
};
tyres::tyres(int no)
{
    this->model=no;
}
void tyres::printInformation()
{
    cout<<"Tyres No : "<<model<<endl;
}
void tyres::changeTyre(int no)
{
    this->model=no;
}
class engine
{
    int power;
    int model;

public:
    engine(){

    }
    engine(int mode, int power);
    void printInformation();
    void changeEngine(int model,int changeEngine);
};
engine::engine(int mode,int power)
{
    this->model=mode;
    this->power=power;
}
void engine::printInformation()
{
    cout<<"Power : "<<power<<endl;
    cout<<"Model : "<<model<<endl;
}
void engine::changeEngine(int model,int power)
{
    this->model=model;
    this->power=power;
}
class car
{
private:
    int speed;
    string color;
    int no;
    engine eng;
    tyres tye;


public:
    car(int no,int speed,string color,int tyresNo,int power,int model);
    car();
    void printInfor();
    void changeTyreNo(int tyre);
    void changeEngine(int model,int power);
};
car::car(int no,int speed,string color,int tyreNo,int power,int model):tye(tyreNo),eng(power,model)
{
    this->no=no;
    this->color=color;
    this->speed=speed;
}
car::car()
{
    
}
void car::changeTyreNo(int tyre)
{
   tye.changeTyre(tyre);
}
void car::changeEngine(int model,int power)
{
    eng.changeEngine(model,power);
}
void car::printInfor()
{
    eng.printInformation();
    cout<<"Color : " << this->color<<endl;
    cout<<"Car No : " <<this->no<<endl;
    cout<<"Speed : " <<this->speed<<endl;
    tye.printInformation();
}
int main()
{
     car cr(12,3232,"Black",33,4000,40);
     cr.printInfor();


    return 0;
}
