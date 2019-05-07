/*
		Albert Shevchuk 
		CSC340 T/Th @ s2:10pm 
		3/27/17
		Dev-C++
*/

#include <iostream>
#include "PolynomialADT.h"

int main(int argc, char **argv)
{	
	int terms;
 	int num = 0;
 	int power;																				//variables for passes and calls
 	double newCoefficient;
 	double scalar;
 	
 	cout<<"      Hello and Welcome to Alberts Polonomial Manipulation"<<endl<<endl;
 	cout<<"Please enter a number to test..."<<endl;
 	cout<<"1 : Default constructor"<<endl;
 	cout<<"2 : Highest degree constructor "<<endl;
 	cout<<"3 : Accessor degree()"<<endl;
 	cout<<"4 : Accessor getCoeff(int power)"<<endl;											//menu
 	cout<<"5 : Obtain a polynomial"<<endl;
 	cout<<"6 : Mutator setCoeff(int power, double newCoefficient)"<<endl;
 	cout<<"7 : Overloaded division operator (/)"<<endl;
 	cout<<"8 : Overloaded negation operator (-)"<<endl;
 	cout<<"9 : Overloaded addition (+)"<<endl;
 	cout<<"10 : Operator (<<) as a friend"<<endl;
 	
 	cin>>num;
 	
	switch (num)																			//switch statements for menu, could of looped it but oh well
	{
	 	case 1:
	 	{
	 		PolynomialADT c;	
	 		cout<<endl<<"Object c has been created!"<<endl;
	 		break;
		}
		case 2:
		{
			PolynomialADT c1(200);
			cout<<endl<<"Polinomial max size was set to 200"<<endl;
			break;
		}
		case 3:
		{
			cout<<endl<<"Need to create a polynomial first!"<<endl;
			cout<<"How many terms does the polynomial have? ";
 			cin>>terms;
 			PolynomialADT c;
 			c.input(terms);
 			cout<<endl<<"The highest degree of the polynomial you entered is: "<<c.degree();
 			break;
		}
		case 4:
		{
			cout<<endl<<"Need to create a polynomial first!"<<endl;
			cout<<"How many terms does the polynomial have? ";
 			cin>>terms;
 			PolynomialADT c;
 			c.input(terms);
 			cout<<"Enter a power: ";
			cin>>power;
			if(c.getCoeff(power) == -1)
			{
				cout<<"no coefficient to the X ^ "<<power<<" exists in the polynomial entered"<<endl;
			}
			else
			{
				cout<<"Coefficient Found: "<<c.getCoeff(power)<<endl;
			}
			break;
		}
		case 5:
		{
			PolynomialADT c;
 			c.input(terms);		
			c.print(terms);	
			break;
		}
		case 6:
		{
			cout<<endl<<"Need to create a polynomial first!"<<endl;
			cout<<"How many terms does the polynomial have? ";
 			cin>>terms;
 			PolynomialADT c;
 			c.input(terms);
 			cout<<"Power: ";
 			cin>>power;
 			cout<<"New coefficient: ";
 			cin>>newCoefficient;
 			c.print(terms);
 			c.setCoeff(power,newCoefficient);
 			c.print(terms);
 			break;
		}
		case 7:
		{
			cout<<endl<<"Need to create a polynomial first!"<<endl;
			cout<<"How many terms does the polynomial have? ";
 			cin>>terms;
 			PolynomialADT c;
 			PolynomialADT c1;
 			c.input(terms);
 			cout<<"Enter scalar you wish do devide your polynomial by: ";
 			cin>>scalar;
 			c.print(terms);
 			c1 = c / scalar;
 			c1.print(terms);
 			break;
		}
 		case 8:
 		{
 			cout<<endl<<"Need to create a polynomial first!"<<endl;
			cout<<"How many terms does the polynomial have? ";
 			cin>>terms;
 			PolynomialADT c;
 			c.input(terms);
 			c.print(terms);
			c = -c;	
			c.print(terms);
			break;
		}
		case 9:
		{
			PolynomialADT c;
			PolynomialADT c1;
			PolynomialADT c2;
			cout<<endl<<"Need to create 2 polynomial's first!"<<endl;
			cout<<"How many terms does polynomial 1 have? ";
			cin>>terms;
			c.input(terms);
			cout<<"How many terms does polynomial 2 have? ";
			cin>>terms;
			c1.input(terms);
			c2 = c + c1;
			c.print(terms);
			c1.print(terms);
			c2.print(terms);
			break;
		}
		case 10:
		{
			cout<<endl<<"Need to create a polynomial first!"<<endl;
			cout<<"How many terms does the polynomial have? ";
 			cin>>terms;
 			PolynomialADT c;
 			c.input(terms);
 			c.print(terms);
 			break;
		}
	}

    return 0;
}
