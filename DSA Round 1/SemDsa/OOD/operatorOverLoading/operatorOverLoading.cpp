#include<bits/stdc++.h>
using namespace std;
class  point
{
    private:
        int xPoint;
        int yPoint;
    public:
        point();
        point(int xPoint,int yPoint);
        bool operator>(point &p1);
        bool operator<(point &p1);
        bool operator==(point &p1);
        bool operator!=(point &p1);
        void print();
};
point::point(int xPoint,int yPoint)
{
    this->xPoint=xPoint;
    this->yPoint=yPoint;
}
void point::print()
{
    cout<<"X axis : "<<xPoint<<endl;
    cout<<"Y axix : "<<yPoint<<endl;
}
bool point::operator>(point &p1)
{
    if(p1.xPoint<this->xPoint)
    {
        return true;
    }
    return false;
}
bool point::operator<(point &p1)
{
   return !(*this>p1);
}
bool point::operator==(point &p1)
{
    if(this->xPoint==p1.xPoint && this->yPoint==p1.yPoint)
    {
        return true;
    }
    return false;
}
bool point::operator!=(point & p1)
{
    return !(*this==p1);
}
int main()
{
    cout<<"Hello World\n";


    return 0;
}
