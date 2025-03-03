#include <iostream>
using namespace std;

// Unary Operators:
class Test {
private:
    int a, b;

public:
    // Default constructor
    Test() {
        a = 0;
        b = 0;
    }

    // Parameterized constructor
    Test(int a, int b) {
        this->a = a;
        this->b = b;
    }

    // Overloading unary - operator
    Test operator-() {
        this->a = -this->a; // Negate a
        this->b = -this->b; // Negate b
        return *this;       // Return the current object
    }

    // Display function
    void display() {
        cout << "\na: " << a << "\tb: " << b << endl;
    }
};

int main() {
    Test T1(-23, 5), T2(10, -3);

    -T1; // Apply unary - operator on T1
    T1.display(); // Display the negated values of T1

    -T2; // Apply unary - operator on T2
    T2.display(); // Display the negated values of T2

    return 0;
}

