#include <bits/stdc++.h>
using namespace std;
class pointClass
{
    int *dy;
    int x;

public:
    pointClass()
    {
        dy=new int[4];
    }
    pointClass(int x)
    {
        dy = new int[4];
        this->x = x;
    }
    void print();
    void seetPoint()
    {
        for (int i = 0; i < 4; i++)
        {
            cout<<"Enter Values :\n";
            cin >> dy[i];
        }
    }
    ~pointClass()
    {
        delete[] dy;
    }
     pointClass& operator=(pointClass &p)
    {
        if(this!=&p)
        {
            for(int i=0;i<4;i++)
            {
                this->dy[i]=p.dy[i];
            }
        }
        return *this;
    }
    pointClass(pointClass &p)
    {
        dy=new int[4];
        x=p.x;
        for(int i=0;i<4;i++)
        {
            dy[i] = p.dy[i];
        }

    }
};
void pointClass::print()
{
    cout << x << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << dy[i] << endl;
    }
}

int main()
{
    pointClass cl(10);
    cl.seetPoint();
    cl.print();
    
    pointClass p;

    cout<<"============\n";
    p.seetPoint();

    p=cl;
    p.print();
    cl.print();

    return 0;
}
