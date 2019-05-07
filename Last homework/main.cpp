/*
		Albert Shevchuk 
		CSC340 T/Th @ s2:10pm 
		5/16/17
		Dev-C++
*/
#include "Person.h"
#include "Employee.h"
#include <iostream>																//headers
#include <string>
using namespace std;

int main()
{
	Employee dude(916561456, "Albert","6/19/1991",2013,1000);
	Employee dude2(dude);
	dude.set_id(123456);
	dude.set_name("Gainsta");
	                                                                            //TESTING
//	dude.addIncreaseRate(.16);
//	dude.addIncreaseRate(.7);
	dude.addIncreaseRate(.19);
	cout<<dude<<endl;
	cout<<dude2<<endl;

return 0;
}
