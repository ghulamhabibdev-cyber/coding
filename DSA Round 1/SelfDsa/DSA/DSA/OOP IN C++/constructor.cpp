#include <bits/stdc++.h>
using namespace std;

class Hero {
private:
    char* name;
    int age;

public:
    Hero(const char* n, int a) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        age = a;
        cout << "Address of Obj: " << this << endl;
    }

    // Shallow Copy Constructor (copy pointer only)
    // Hero(const Hero &h) {
    //     name = h.name; // SHALLOW COPY: both objects share same memory
    //     age = h.age;
    // }

    // ✅ Deep Copy Constructor (creates new memory)
    Hero(const Hero &h) {
        name = new char[strlen(h.name) + 1];
        strcpy(name, h.name);  // deep copy of data
        age = h.age;
    }

    void SetName(const char* newName) {
        strcpy(name, newName);
    }

    void Print() const {
        cout << "Name: " << name << ", Age: " << age << ", Address: " << this << endl;
    }

    ~Hero() {
        delete[] name;
    }
};

int main() {
    Hero a("Habib", 20);
    Hero b = a;         // Copy constructor

    cout << "\nBefore changing name:\n";
    a.Print();
    b.Print();

    a.SetName("Qayyum");

    cout << "\nAfter changing a's name:\n";
    a.Print();
    b.Print();  // If shallow copy: this will also change (BAD)
}
