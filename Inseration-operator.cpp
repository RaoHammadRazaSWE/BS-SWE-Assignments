#include<iostream>
#include<conio.h>
using namespace std;
class Test {
	//overloading Stream Insertion operator Overloading 19.3 lecture. 
	public:
		string name;
		Test()
		{
			name = " Rao ";
		}
		friend ostream &operator << (ostream &output, Test &o){
			output << "Your Name : " << o.name<<endl;
			return output;
		}
};
main()
{
	Test T1;
	cout <<T1;
	return 0;
}
