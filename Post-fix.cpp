#include <iostream>
using namespace std;

// Prefix increment and decrement operator overloading
class Test {
private:
    int a;

public:
    // Default constructor
    Test() {
        a = 0;
    }

    // Parameterized constructor
    Test(int a) {
        this->a = a;
    }

    // Postfix increment operator
    Test operator++(int) {
        Test obj(*this); // Save current state
        a++;             // Increment the value
        return obj;      // Return the original state
    }

    // Postfix decrement operator
    Test operator--(int) {
        Test obj(*this); // Save current state
        a--;             // Decrement the value
        return obj;      // Return the original state
    }

    // Display function
    void display() {
        cout << "a: " << a << endl;
    }
};

int main() {
    Test T1(10);          // Initialize with value 10
    Test T2 = T1++;       // Postfix increment
    T2.display();         // Display T2
    T1 = T2--;            // Postfix decrement
    T1.display();         // Display T1

    return 0;
}

