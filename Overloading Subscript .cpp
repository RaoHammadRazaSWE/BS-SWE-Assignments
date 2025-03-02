#include<iostream>
using namespace std;

// Overloading Subscript [] Operator

class Test {
	private:
		int arr[10];
	public:
		Test()
		{
			for(int i=0; i<= 9; i++)
			{
				arr[i] = i+2;
			}
		}
		int &operator [](int index)	{
			if(index > 9){
				cout << "\n\n Index out of Bound ";
			}
			else{
				return arr[index];
			}
		}
};

int main(){
	
	Test T;
	cout<<"\n\n T[0] -> " << T[0];
	cout<<"\n\n T[6] -> " << T[6];
	cout<<"\n\n T[11] -> " << T[11];
	
	return 0;
}
