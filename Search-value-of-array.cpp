#include<iostream>
#include<conio.h>
using namespace std;
main()
{
	// Using Search Method.
	int a[5] = {1,3,4,5,6};
	int found = 0, search_value;
	cout<<"\n Enter Value For Search: ";
	cin>>search_value;
	for(int i= 0; i<=4; i++)
	{
		if(search_value == a[i])
		{
			cout<<"\n\n Value is found ....";
			found++;
			break;
		}
	}
	if(found == 0)
	{
		cout<<"\n\n Value Can't found...";
	}
	getch();
	return 0;
}
