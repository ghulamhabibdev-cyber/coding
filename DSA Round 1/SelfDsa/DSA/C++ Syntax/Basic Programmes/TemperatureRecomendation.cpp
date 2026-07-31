#include <iostream>
using namespace std;
void TemperatureReccommendation(double temperature)
{
    if (temperature < 0)
    {
        cout << "It is Freezing outside  ! " << endl;
    }
    if (temperature < 20)
    {
        cout << "Wear Jacket ! " << endl;
    }
    else
    {
        cout << "It is Warm Today ! " << endl;
    }
}
int main()
{

    double temperature;
    cout<<"Enter Temperature : "<<endl;
    cin>>temperature;
    TemperatureReccommendation(temperature);
    return 0;
}