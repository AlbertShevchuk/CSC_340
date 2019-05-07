/*
		Albert Shevchuk 
		CSC340 T/Th @ s2:10pm 
		5/09/17
		Dev-C++
*/
#include <iostream>
#include <new>
#include "linklist.h"

using namespace std;

int main(int argc, const char * argv[]) 										//TESTING
{
int input;    
cout<<"Welcome to Albert's HW7, lets make 2 ojects"<<endl;  
cout<<"Made: linklist a1, populate 5 items"<<endl;

linklist a1;
for(int i = 1; i<=5; i++)
{
	cout<<"Input "<<i<<": ";
	cin>>input;
	a1.push_back(input);	
}

linklist a2;
cout<<"Made: linklist a2, populate 4 items"<<endl;

for(int i = 1; i<=4; i++)
{
	cout<<"Input "<<i<<": ";
	cin>>input;
	a2.push_back(input);	
}

cout<<endl<<"a1: ";
cout << a1;
cout<<endl<<"a2: ";
cout << a2;

cout<<endl<<endl<<"Lets pop back once from both"<<endl;					//TESTING
a1.pop_back();
a2.pop_back();

cout<<endl<<"a1: ";
cout << a1;
cout<<endl<<"a2: ";
cout << a2;

cout<<endl<<endl<<"Lets create a duplicate a3 from a1"<<endl;			
linklist a3(a1);

cout<<endl<<"a1: ";
cout << a1;
cout<<endl<<"a3: ";
cout << a3;

cout<<endl<<endl<<"Lets Set a3 = a1"<<endl;							//TESTING
a3 = a1;
cout<<endl<<"a3: ";
cout << a3;
cout<<endl<<"a1: ";
cout << a1;

    return 0;
}
