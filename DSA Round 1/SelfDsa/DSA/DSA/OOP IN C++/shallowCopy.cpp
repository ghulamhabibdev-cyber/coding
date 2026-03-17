#include <iostream>
using namespace std;

class Hero {
public:
    int* health;

    Hero(int h) {
        health = new int(h);
    }

    // Shallow Copy Constructor
    Hero(const Hero& h) {
        health = h.health;  // Both point to same memory
    }

    void display() {
        cout << "Health: " << *health << endl;
    }
    ~Hero()
    {
        cout<<"I am  constrcutor : ";
    }
};

int main() {
    // Hero h1(100);
    // Hero h2 = h1; // Shallow Copy
    // *h2.health = 200;

    // h1.display(); // Health: 200
    // h2.display(); // Health: 200 (both changed!)
    Hero ali(230);
    Hero *aliw=new Hero(32);
    aliw->display();
    delete aliw;
}
