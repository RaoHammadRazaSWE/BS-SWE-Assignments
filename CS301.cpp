#include <iostream>
using namespace std;

class Product {
private:
    int data;
    Product* next;
    int productId;

public:
    
    Product() : data(0), next(NULL), productId(0) {}

    
    void set(int data) {
        this->data = data;
    }
    int get() const {
        return data;
    }

    
    void setNext(Product* nextNode) {
        this->next = nextNode;
    }
    Product* getNext() const {
        return next;
    }

    
    void setProductId(int pid) {
        productId = pid;
    }
    int getProductId() const {
        return productId;
    }
};

class Stack {
private:
    Product* head;

public:
    
    Stack() : head(NULL) {}

    void push(int x) {
        Product* newProduct = new Product();
        newProduct->set(x);
        newProduct->setNext(head);
        head = newProduct;
        cout << "Pushed digit " << x << " onto the stack ."<<endl;
    }

    
    int top() const {
        if (head != NULL) {
            return head->get();
        }
        cout << "Stack is empty!" << endl;
        return -1;
    }

    
    int pop() {
        if (head != NULL) {
            int value = head->get();
            Product* temp = head;
            head = head->getNext();
            delete temp;
            return value;
        }
        cout << "Stack is empty, cannot pop!" << endl;
        return -1;
    }
};

int main() {
    
    Product product;

    int studentIdLastTwoDigits = 70; 
    int productId = 2400 + studentIdLastTwoDigits;
    product.setProductId(productId);
    
    cout << "The Product id is : " << product.getProductId() << endl;
    cout <<"--------------------------"<<endl;

    Stack stack;
    int tempProductId = product.getProductId();
    while (tempProductId > 0) {
        int digit = tempProductId % 10;
        stack.push(digit);
        tempProductId /= 10;
    }

    cout <<"--------------------------"<<endl;
    cout << "The Top element of the stack is : " << stack.top() <<endl;
    cout <<"--------------------------"<<endl;

    cout << "The first element popped from the stack is : " <<stack.pop()<<endl;
   
 	cout << "The Sencond element popped from the stack is : " <<stack.pop()<<endl;
    
    cout <<"--------------------------"<<endl;
    
    cout << "The top element of the stack is : " << stack.top() << endl;
    
	cout <<"--------------------------"<<endl;
	cout <<"--------------------------"<<endl;
    return 0;
}

