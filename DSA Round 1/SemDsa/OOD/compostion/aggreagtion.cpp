#include <bits/stdc++.h>
using namespace std;
class brain
{
    int health;

public:
    brain(int health);
    brain()
    {
    }
    int getHealth();
};
brain::brain(int health)
{
    this->health = health;
}
int brain::getHealth()
{
    return health;
}
class heart
{
    int health;
    int pumpRate;

public:
    heart(int health, int pumpRate);
    heart()
    {
    }
    int getHealth();
    int getPumpRate();
};
heart::heart(int health, int pumpRate)
{
    this->health = health;
    this->pumpRate = pumpRate;
}
int heart::getHealth()
{
    return health;
}
int heart::getPumpRate()
{
    return pumpRate;
}
class kidney
{
    int noOfNepron;
    int health;

public:
    kidney(int noOfnepron, int health);
    kidney()
    {
    }
    int getHealth();
    int getNoOfNeprons();
};
kidney::kidney(int noOfNeprons, int health)
{
    this->noOfNepron = noOfNepron;
    this->health = health;
}
int kidney::getNoOfNeprons()
{
    return noOfNepron;
}
int kidney::getHealth()
{
    return health;
}

class aggreAperson
{
    string name;
    int age;
    heart hr;
    brain br;
    kidney kid;

public:
    aggreAperson(string name, int age, int hearthHealh, int pumpRate, int noOfNeprons, int kidHealth, int brainHealth);
    aggreAperson()
    {
    }
    void printPersonHealthReport();
};
aggreAperson::aggreAperson(string name, int age, int heartHealth, int pumpRate, int noOfNeprons, int kidHealth, int brainHealth) : hr(heartHealth, pumpRate), br(brainHealth), kid(noOfNeprons, kidHealth)
{
    this->name = name;
    this->age = age;
}
void aggreAperson::printPersonHealthReport()
{
    cout << "Person : " << name << endl;
    cout << "Age    : " << age << endl;
    cout << "Heart Health : " << hr.getHealth() << endl;
    cout << "Hearth Pump Rate : " << hr.getPumpRate() << endl;
    cout << "No Of Neprons : " << kid.getHealth() << endl;
    cout << "Kidney Health : " << kid.getHealth() << endl;
}
int main()
{
    aggreAperson ali("Ali", 21, 99, 72, 100000000, 100, 100);
    ali.printPersonHealthReport();
    return 0;
}
