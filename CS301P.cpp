#include <iostream>
#include <string>
using namespace std;

class Part {
public:
    int partID;
    string partName;
    int quantity;
    Part* next;

    Part(int partID, string partName, int quantity) 
        : partID(partID), partName(partName), quantity(quantity), next(NULL) {}
};

class Inventory {
public:
    Part* head;

    Inventory() : head(NULL) {}

    // Add a part to the inventory
    void addPart(int partID, string partName, int quantity) {
        Part* newPart = new Part(partID, partName, quantity);
        if (!head) {
            head = newPart;
        } else {
            Part* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newPart;
        }
    }

    // Delete a part from the inventory
    void deletePart(int partID) {
        if (!head) return;

        Part* current = head;
        Part* previous = NULL;

        if (head->partID == partID) {
            head = head->next;
            delete current;
            return;
        }

        // Traverse to find the part
        while (current != NULL && current->partID != partID) {
            previous = current;
            current = current->next;
        }

        // Part not found
        if (!current) return;

        // Remove the part
        previous->next = current->next;
        delete current;
    }

    // Update the quantity of a part
    void updateQuantity(int partID, int newQuantity) {
        Part* current = head;
        while (current != NULL) {
            if (current->partID == partID) {
                current->quantity = newQuantity;
                return;
            }
            current = current->next;
        }
        cout << "Part not found." << endl;
    }

    // Find and display a part by ID
    void findPart(int partID) {
        Part* current = head;
        while (current != NULL) {
            if (current->partID == partID) {
                cout << "Part ID: " << current->partID << ", Part Name: " << current->partName
                     << ", Quantity: " << current->quantity << endl;
                return;
            }
            current = current->next;
        }
        cout << "Part not found." << endl;
    }

    // Print all parts in the inventory
    void printInventory() {
        cout << "Part ID    Part Name         Quantity" << endl;
        cout << "-------------------------------------" << endl;
        Part* current = head;
        while (current != NULL) {
            cout << current->partID << "         " << current->partName;
            cout << "                " << current->quantity << endl;
            current = current->next;
        }
        cout << endl; // For better spacing after the list
    }
};

int main() {
    cout << "----------------------------------------------" << endl;
    cout << "Computer Parts Management System [BC240415463]" << endl; // Just change your ID here in brackets.
    cout << "----------------------------------------------" << endl;
    
    Inventory storeInventory;

    // Pre-populated data for demonstration
    storeInventory.addPart(101, "SSD", 25);
    storeInventory.addPart(102, "RAM", 40);
    storeInventory.addPart(103, "HDD", 15);

    cout << endl << "Inventory Added." << endl;
    storeInventory.printInventory();  // Print initial inventory

    cout << "Finding Part ID 101:" << endl;
    storeInventory.findPart(101);     // Test finding part with ID 101
    cout << endl;

    cout << "After deleting SSD and updating RAM quantity..." << endl << endl;

    storeInventory.deletePart(101);  // Delete part with ID 101
    storeInventory.updateQuantity(102, 50); // Update quantity for RAM

    storeInventory.printInventory();  // Print updated inventory

    return 0;
}

