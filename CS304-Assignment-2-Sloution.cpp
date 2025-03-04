#include <iostream>
#include <string>
using namespace std;

// Abstract Employee class
class Employee {
protected:
    string employeeId;
    string employeeName;
    double salary;

public:
    Employee() : salary(0.0) {}
    virtual void calculateSalary() = 0;
    virtual void displaySalary() {
        cout << "Salary: " << salary << endl;
    }
    virtual ~Employee() {} // Correct destructor syntax
};

// Regular Employee Class
class RegularEmployee : public Employee {
private:
    double basicSalary;
    double allowances;
    double incomeTax;

public:
    RegularEmployee(double basic, double allow, double tax)
        : basicSalary(basic), allowances(allow), incomeTax(tax) {}

    void calculateSalary() override {
        salary = basicSalary + allowances - incomeTax;
    }

    void displaySalary() override {
        cout << "Salary of Regular Employee with basic pay: " << basicSalary
             << ", allowances: " << allowances
             << ", and income tax: " << incomeTax << " is given below:" << endl;
        Employee::displaySalary();
    }
};

// Hourly Employee class
class HourlyEmployee : public Employee {
private:
    int noOfHours;
    double hourlyRate;

public:
    HourlyEmployee(int hours, double rate) : noOfHours(hours), hourlyRate(rate) {}

    void calculateSalary() override {
        salary = hourlyRate * noOfHours;
    }

    void displaySalary() override {
        cout << "Salary of Hourly Employee with hourly rate: " << hourlyRate
             << " and no. of hours: " << noOfHours << " is given below:" << endl;
        Employee::displaySalary();
    }
};

int main() {
    // Dynamic array of Employee pointers
    Employee* employees[2];

    // Dataset Values no : 1
//    employees[0] = new RegularEmployee(75000, 25000, 8000);
//    employees[1] = new HourlyEmployee(2000, 15);
    
    // Dataset Values no : 2
    employees[0] = new RegularEmployee(65000, 30000, 6000);
    employees[1] = new HourlyEmployee(2500, 10);

    // Calculate and display salaries
    for (int i = 0; i < 2; ++i) {
        employees[i]->calculateSalary();
        employees[i]->displaySalary();
        cout << "--------------------------" << endl;
    }

    // Cleanup
    for (int i = 0; i < 2; ++i) {
        delete employees[i];
    }

    return 0;
}

