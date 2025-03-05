#include<iostream>
using namespace std;
class Base
{
	public:
		void getName(){
			cout<<"\n my Name is Rao";
		}
//		virtual void getMarks() = 0;
		
//		void getMarks(){
//			cout<<"\n Base Class Function ";
//		}
	
};
class Drived: public Base{
	public:
		void getRollno()
		{
			cout<<"\n my Roll no. is BT-23 ";
		}
//		void getMarks(){
//			cout<<"Drived Class Function " <<endl;
//		}
	};
main(){
	// Explicite: 
//	Base *p;
//	Drived d; // Explicit Typecasting
//	p = &d;
//	p -> getName();
//	p -> getMarks();
	
	// 	Amplicite 
	Base *p, obj1;
	Drived *d, obj2;
	p = &obj1; // Implicit type Casting
	d = &obj2; // Implicite type casting
	p -> getName();
	d -> getRollno();
	return 0;
}
