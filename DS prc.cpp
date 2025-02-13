#include<iostream>
#include<conio.h>
using namespace std;
int size = 0;
class Node {
    public:
        int data;
        Node *next_add;

        void setData(int n) {
            data = n;
        }

        int getData() {
            return data;
        }

        void setNext(Node *next) {
            next_add = next;
        }

        Node* getNext() {
            return next_add;
        }
};

class List {
    public:
        Node *head;
        Node *lastNode;

        List() {
            head = NULL;
            lastNode = NULL;
        }

        void add() {
            int n;
            cout << "\n\n Enter Add Value: ";
            cin >> n;

            Node *currentNode = new Node;
            currentNode->setData(n);
            currentNode->setNext(NULL);

            if (head == NULL) {
                head = currentNode;
                lastNode = currentNode;
            } else {
                lastNode->setNext(currentNode);  // Corrected from setNest to setNext
                lastNode = currentNode;
            }

            size++;
            cout << "\n\n New node inserted\n";
        }
};
		
main(){
//	int a[5] = {10, 20 , 30 , 40 , 50};
//	int found = 0, search_value;
//	cout<<"\n Enter Value For Search: ";
//	cin>>search_value;
//	for(int i=0; i<=4; i++)
//	{
//		if(search_value == a[i])
//		{
//			cout<<"\n value is found...";
//			found++;
//			break;
//		}
//	}
//	if (found == 0)
//	 {
//	 	cout<<"\n\n Value Can't found...";
//	 }

// Run above code :
	List obj;
	obj.add();
	obj.add();
	obj.add();
	
	return 0;
}
