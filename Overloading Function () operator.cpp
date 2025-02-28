#include <iostream>
using namespace std;

// Overloading Function () operator 
class Test {
private:
    int age;
    string name;

public:
    // Default constructor
    Test() {
        age = 0;
        name = "";
    }

    // Parameterized constructor
    Test(int a, string n) {
        age = a;
        name = n;
    }

    // Overloading () operator
    Test operator()(int a, string n) {
        Test obj;
        obj.age = a;  // Corrected: Assign `a` to `obj.age`
        obj.name = n; // Assign `n` to `obj.name`
        return obj;
    }

    // Display function
    void display() {
        cout << "\nName: " << name;
        cout << "\tAge: " << age;
    }
};

int main() {
    Test T1(22, "Rao"), T2; // Run parameterized constructor
    T1.display();           // Display T1 details
    T2 = T1(23, "Raza");    // Use the overloaded () operator
    T2.display();           // Display T2 details
    return 0;
}

