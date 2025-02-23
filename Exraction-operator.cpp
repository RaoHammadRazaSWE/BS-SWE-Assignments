#include<iostream>
using namespace std;

class Test {
	 // Exraction Operator Overloading
	public:
		int age;
		string name;
		friend istream &operator >> (istream &input, Test &i){
			input >> i.name >> i.age;
			return input;
		}		
		friend ostream &operator << (ostream &output, Test &o){
			output << "Your Name : " << o.name<<endl;
			output << "\t Age : " << o.age;
			return output;
		}
};
main()
{
	Test T1;
	cout << "\n\n Enter Name & Age : ";
	cin>>T1;
	cout <<T1;
	return 0;
}
