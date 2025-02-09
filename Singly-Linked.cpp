#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next_add;
};

class Linked_List {
public:
    Node *head = NULL;

    void insert() {
        int n;
        cout << "Enter value: ";
        cin >> n;
        Node *new_node = new Node;
        new_node->data = n;
        new_node->next_add = NULL;

        if (head == NULL) {
            head = new_node;
        } else {
            Node *ptr = head;
            while (ptr->next_add != NULL) {
                ptr = ptr->next_add;
            }
            ptr->next_add = new_node;
        }
        cout << "New node inserted successfully." << endl;
    }

    void count() {
        if (head == NULL) {
            cout << "\nLinked list is empty." << endl;
        } else {
            int n = 0;
            Node *ptr = head;
            while (ptr != NULL) {
                n++;
                ptr = ptr->next_add;
            }
            cout << "\nTotal nodes: " << n << endl;
        }
    }

    void search() {
        if (head == NULL) {
            cout << "\nLinked list is empty." << endl;
        } else {
            int n, found = 0;
            cout << "\nEnter value to search: ";
            cin >> n;
            Node *ptr = head;
            while (ptr != NULL) {
                if (n == ptr->data) {
                    found = 1;
                    cout << "\nValue found." << endl;
                    break;
                }
                ptr = ptr->next_add;
            }
            if (found == 0) {
                cout << "\nValue " << n << " not found." << endl;
            }
        }
    }

    void update() {
        if (head == NULL) {
            cout << "\nLinked list is empty." << endl;
        } else {
            int n, found = 0;
            cout << "\nEnter value to update: ";
            cin >> n;
            Node *ptr = head;
            while (ptr != NULL) {
                if (n == ptr->data) {
                    cout << "\nEnter new value: ";
                    cin >> ptr->data;
                    found = 1;
                    cout << "\nValue updated successfully." << endl;
                    break;
                }
                ptr = ptr->next_add;
            }
            if (found == 0) {
                cout << "\nValue " << n << " not found." << endl;
            }
        }
    }

    void del() {
        if (head == NULL) {
            cout << "\nLinked list is empty." << endl;
        } else {
            int n, found = 0;
            cout << "\nEnter value to delete: ";
            cin >> n;
            if (n == head->data) {
                Node *ptr = head;
                head = head->next_add;
                delete ptr;
                found = 1;
                cout << "\nNode deleted." << endl;
            } else {
                Node *pre = head;
                Node *ptr = head->next_add;
                while (ptr != NULL) {
                    if (n == ptr->data) {
                        pre->next_add = ptr->next_add;
                        delete ptr;
                        found = 1;
                        cout << "\nNode deleted." << endl;
                        break;
                    }
                    pre = ptr;
                    ptr = ptr->next_add;
                }
            }
            if (found == 0) {
                cout << "\nValue " << n << " not found." << endl;
            }
        }
    }

    void show() {
        if (head == NULL) {
            cout << "\nLinked list is empty." << endl;
        } else {
            Node *ptr = head;
            cout << "\nLinked list elements: ";
            while (ptr != NULL) {
                cout << ptr->data << " ";
                ptr = ptr->next_add;
            }
            cout << endl;
        }
    }
};

int main() {
    Linked_List obj;
    while (true) {
        int choice;
        cout << "\n\n1. Insert Node";
        cout << "\n2. Count Nodes";
        cout << "\n3. Search Node";
        cout << "\n4. Update Node";
        cout << "\n5. Delete Node";
        cout << "\n6. Show Nodes";
        cout << "\n7. Exit";
        cout << "\n\nYour choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                obj.insert();
                break;
            case 2:
                obj.count();
                break;
            case 3:
                obj.search();
                break;
            case 4:
                obj.update();
                break;
            case 5:
                obj.del();
                break;
            case 6:
                obj.show();
                break;
            case 7:
                return 0;
            default:
                cout << "\nInvalid choice. Please try again." << endl;
        }
    }
    return 0;
}

