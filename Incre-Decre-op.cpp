#include<iostream>
using namespace std;
// Pre fix incre & decre operator overloading
class Test
{
	private:
		int a;
	public:
		Test()
		{
			a = 0;
		}
		Test(int a){
			this->a = a;
		}
		// Pre fix incre operator
		Test operator ++(){
			Test obj;
			obj.a  = ++a;
			return obj;
		}
		// Pre fix decr operator
		Test operator --(){
			Test obj;
			obj.a  = --a;
			return obj;
		}
		void display(){
			cout<<" a : "<<a<<endl;
		}
};
main()
{
	Test T1(10);
	Test T2 = ++T1;
	T2.display();
	T1 = --T2;
	T1.display();
	return 0;
}
