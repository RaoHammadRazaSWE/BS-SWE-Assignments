#include<iostream>
using namespace std;
class Base
{
	string name;
//	public:
	protected:
		void getName(){
			cout<<"\n my Name is Rao";
		}
	
};
class Drived: public Base{
	public:
		void getRollno()
		{
			getName();
		}
	};
main(){
	Drived d;
	d.getRollno();
	return 0;
}
