#include <iostream>
#include <queue>
#include <string>
using namespace std;
class Call
{
public:
    string callerName;
    int arrivalTime;
    int serviceTime;
    Call(string name, int arrival, int service)
    {
        callerName = name;
        arrivalTime = arrival;
        serviceTime = service;
    }
};
void simulateCallCenter(queue<Call> qt)
{
    int currentTime = 0;
    while (!qt.empty())
    {

        Call c = qt.front();
        qt.pop();
        if (currentTime < c.arrivalTime)
            currentTime = c.arrivalTime;
        int waitingTime = currentTime - c.arrivalTime;
        int completionTime = currentTime + c.serviceTime;

        cout << "Processing call from: " << c.callerName << endl;
        cout << "Arrival time: " << c.arrivalTime
             << ", Waiting time: " << waitingTime
             << ", Service duration: " << c.serviceTime
             << ", Completion time: " << completionTime << endl
             << endl;
        currentTime += c.serviceTime;
    }
}

int main()
{
    queue<Call> callQueue;
    callQueue.push(Call("Ali", 0, 3));
    callQueue.push(Call("habib", 2, 4));
    callQueue.push(Call("Tom", 4, 2));
    callQueue.push(Call("Jerry", 5, 3));
    cout << "--- Call Center Simulation ---\n\n";
    simulateCallCenter(callQueue);

    return 0;
}
