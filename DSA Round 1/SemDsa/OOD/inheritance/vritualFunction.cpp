#include <bits/stdc++.h>
using namespace std;
class shape
{
private:
    int x;
    int *p;

public:
    virtual void draw()=0;
    virtual  void print();
   virtual~shape()
    {
        delete [] p;
    }
};
class rectangle:public shape
{
    public:
    void draw()override 
    {
        cout<<"Rectange is drawing \n";
    }
    void print()override 
    {
        cout<<"Child print \n";
    }
    ~rectangle()
    {

    }
    

};
void shape::print()
{
    cout<<"PArent print\n";
}
int main()
{
    shape *sh=new rectangle();
    // shape *sh1=new shape();
    sh->print();
    // sh1->print();
    rectangle *rec = new rectangle();
    sh->draw();
    sh->print();
    rec->print();

    return 0;
}
