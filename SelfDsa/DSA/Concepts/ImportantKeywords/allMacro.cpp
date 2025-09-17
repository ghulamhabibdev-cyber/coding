#include <iostream>
using namespace std;

// 1️⃣ Object-like Macro
#define PI 3.14159

// 2️⃣ Function-like Macro
#define SQUARE(x) ((x) * (x))
#define PRINT(x) cout << "Value is: " << x << endl

// 3️⃣ Multiline Macro
#define PRINT_RECTANGLE(width, height)           \
    for (int i = 0; i < height; i++) {           \
        for (int j = 0; j < width; j++) {        \
            cout << "*";                         \
        }                                        \
        cout << endl;                            \
    }

// 4️⃣ Chain Macros
#define BASE_VALUE 100
#define BONUS BASE_VALUE

int main() {
    cout << "----- Object-like Macro -----" << endl;
    double radius = 4.0;
    double area = PI * radius * radius;
    cout << "Area of circle with radius " << radius << " is " << area << endl;

    cout << "\n----- Function-like Macro -----" << endl;
    int val = 5;
    cout << "Square of " << val << " is " << SQUARE(val) << endl;
    PRINT(val);

    cout << "\n----- Multiline Macro -----" << endl;
    cout << "Rectangle (4x3):" << endl;
    PRINT_RECTANGLE(4, 3);

    cout << "\n----- Chain Macros -----" << endl;
    cout << "BONUS value (via chain macro): " << BONUS << endl;

    cout << "\n----- Predefined Macros -----" << endl;
    cout << "This is line: " << __LINE__ << endl;
    cout << "In file: " << __FILE__ << endl;
    cout << "Compiled on: " << __DATE__ << " at " << __TIME__ << endl;

    return 0;
}
