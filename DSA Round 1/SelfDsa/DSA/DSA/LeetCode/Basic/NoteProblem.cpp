#include <iostream>
using namespace std;
int TotalNotesInAmount()
{
    int amount;
    cout << "Enter amount : " << endl;
    cin >> amount;
    int totalNotes = 0;
    int hurednotes;
    int totalfifity;
    int twenty;
    int ten;
    int totol500Notes = amount % 500;
    switch (totol500Notes)
    {
    case 0:
        totalNotes = amount / 500;
        cout<<"total : "<<500<<totalNotes<<endl;
        return totalNotes;
       
    default:
        totalNotes += amount / 500;

        hurednotes = totol500Notes % 100;

        switch (hurednotes)
        {
        case 0:
            totalNotes += totol500Notes / 100;
            cout<<"total : "<<100<<totalNotes<<endl;
            return totalNotes;
            break;

            /* code */

        default:
            totalNotes += amount / 100;

            totalfifity = hurednotes % 50;
            switch (totalfifity)
            {
            case 0:
                totalNotes += totalfifity / 50;
                cout<<"total : "<<50<<totalNotes<<endl;
                return totalNotes;
                /* code */
                break;

            default:
                totalNotes += totalfifity / 50;
                cout<<"total : "<<50<<totalNotes<<endl;
                twenty = totalfifity % 20;
                switch (twenty)
                {
                case 0:
                    totalNotes += twenty / 20;
                    cout<<"total : "<<20<<totalNotes<<endl;
                    return totalNotes;
                    break;
                    /* code */

                default:
                    totalNotes += twenty / 20;
                    cout<<"total : "<<20<<totalNotes<<endl;
                    ten = twenty % 10;
                    switch (ten)
                    {
                    case 0:
                        totalNotes += twenty / 10;
                        cout<<"total : "<<10<<totalNotes<<endl;
                        return totalNotes;
                        break;
                    default:
                        totalNotes += twenty / 10;
                        cout<<"total : "<<10<<totalNotes<<endl;
                        return totalNotes;

                    }
                    break;
                }
                break;
            }
            break;
        }
    }
}
int main()
{
    cout<<TotalNotesInAmount();
}