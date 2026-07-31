#include <iostream>
#include "queue.h"
using namespace std;
int main()
{

    queque qt;
    int choice;
    while (true)
    {
        cout<<"Insert Element into Queue(Press 1)\n";
         cout<<"Delete element from queue(Press 2)\n";
        cout<<"Display the queue(Press 3)\n";
        cout<<"Exit(Press 4)\n";
        cin>>choice;
        if(choice==1)
        {
            int data;
            cout<<"Enter Data \n";
            cin>>data;
            qt.enqueue(data);
        }
        else if(choice==2)
        {

            qt.dequeue();
            cout<<"Element is Removed \n";

        }
        else if(choice==3)
        {
            qt.printQueue();
        }
        else if(choice==4)
        {
            break;
        }
    }


    return 0;
}
