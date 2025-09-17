#include <iostream>
using namespace std;
int main()
{
    int raceNo = 0;
   
    double avergeOfTen;
    int arr[10];
    int runer = 0;
    int wordPerMintes;
    double sum=0;
    double alltimeSum=0;
    double avgflastTenRaces = 0;
    double alltimeAvg = 0;
    while (true)
    {
        if (raceNo < 10)
        {
            cout << "1 :Enter Word Per Mintes : \n";
            cin >> wordPerMintes;
            arr[raceNo] = wordPerMintes;
            int j=1;
            for (int i = 0; i <j; i++)
            {

                sum += arr[i];
            }
            avergeOfTen = sum / 10.0;
            cout << "1  :Last Ten Race Averg : " << avergeOfTen << endl;
            raceNo++;
            j++;
            alltimeSum+=wordPerMintes;
            alltimeAvg = alltimeSum / raceNo;
            cout << "1  :All Time Average WPM : " << alltimeAvg << endl;
            
        }
        if (raceNo >= 10)
        {
            cout << "2 :Enter Word Per Mintes : \n";
            cin >> wordPerMintes;
            arr[0] = arr[1];
            arr[1] = arr[2];
            arr[2] = arr[3];
            arr[3] = arr[4];
            arr[4] = arr[5];
            arr[5] = arr[6];
            arr[6] = arr[7];
            arr[7] = arr[8];
            arr[8] = arr[9];
            arr[9] = wordPerMintes;
            sum=0;
            for (int i = 0; i < 10; i++)
            {

                sum += arr[i];
               
            }
            avergeOfTen = avergeOfTen / 10;
            cout <<"1  :Last Ten Race Averg"<< avergeOfTen << endl;
            alltimeAvg += alltimeAvg;
             raceNo++;
            alltimeAvg = alltimeAvg / raceNo;
            cout<<"ALl Time Average : "<<alltimeAvg<<endl;
           
        }
    }
}