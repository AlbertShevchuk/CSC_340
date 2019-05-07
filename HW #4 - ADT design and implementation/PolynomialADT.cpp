/*
		Albert Shevchuk 
		CSC340 T/Th @ s2:10pm 
		3/27/17
		Dev-C++
*/

#include <iostream>
#include "PolynomialADT.h"

PolynomialADT::PolynomialADT()
{
	for(int i = 0; i < 200; i++)
	{coef[i]=0.0;}																				//set arrays to 0
	for(int i = 0; i < 200; i++)
	{power[i]=0;}
}

PolynomialADT::PolynomialADT(unsigned int degree):maxDegree(degree)								// set max degree to 200
{ }

void PolynomialADT::input(int terms)
{
	for(int i = 0; i<terms; i++)
	{
		cout<<"Enter the coefficient for term "<<i+1<<" : ";
		cin>>coef[i];
		cout<<"Enter the power for term "<<i+1<<" : ";											//populate elements
		cin>>power[i];
		
	}
	coef[terms] = '\n';																			// '\n' stopping inficator
	power[terms] = '\n';																		
}

void PolynomialADT::print(int terms) const
{
	for(int i = 0; i < terms; i++)
   	{
   		if((((getPower(i))==0)&&(i==0))||(((getPower(i))==0)&&(i!=0)&&(getCoef(i)<0)))
   		{	
   			cout<<getCoef(i);	
		}
		else if(((getPower(i))==0)&&(i!=0)&&(getCoef(i)>0))
   		{	
   			cout<<"+"<<getCoef(i);	
		}
		else if(getCoef(i)<0)
		{
			cout<<" "<<getCoef(i)<<" * X ^ "<<getPower(i);													//printing finction
		}
		else if((getCoef(i)>0)&&(i==0))
		{
			cout<<getCoef(i)<<" * X ^ "<<getPower(i);
		}
   		else if((getCoef(i)>0)&&(i!=0))
		{
			cout<<" + "<<getCoef(i)<<" * X ^ "<<getPower(i);
		}
	}
cout<<endl;
}

double PolynomialADT::getCoef(int i) const
{
	return coef[i];																						//getters for coef and power
}

int PolynomialADT::getPower(int i) const
{
	return power[i];
}

double PolynomialADT::getCoeff(int power) const
{
	for(int i = 0; getCoef(i)!='\n'; i++)
	{
		if(getPower(i)==power)
		{
			return coef[i];																				//loop threw array and identify mathced power
		}																								// send back coef of power or -1 for not found
	}
	
	return -1; 
}

int PolynomialADT::degree() const           
{
	int Power = 1;
	for(int i = 0; power[i]!='\n'; i++)
	{
		if(power[i] > Power)																			//loop threw array and find max degree and send back	
		{
			Power = power[i];
		}
	}
	return Power;
}

void PolynomialADT::setCoeff(int power, double newCoefficient)
{
	bool changed = 0;
	
	for(int i = 0; getCoef(i)!='\n'; i++)
	{
		if(getPower(i)==power)
		{
			coef[i] = newCoefficient ;																	// loop threw array and find power and change coef
			changed = 1;
		}
	}
	
	if(changed == 0)
	{
		cout<<" Power: "<<power<<" was not found in the polynomial, nothing was changed!"<<endl;       //nothing founc statement 
	}
}

PolynomialADT PolynomialADT::operator/(const double& scalar)
{
	int counter = 0;
	PolynomialADT p1;
	if(scalar == 0)
	{
		cout<<"Scalar can not be zero";
	}
	else
	{ 
		for(int i = 0; coef[i] != '\n' ; i++)
		{
			p1.coef[i] = coef[i] / scalar;																//loop threw array and devide by scalar
			p1.power[i] = power[i];																		//store into a new object
			counter++;
		}
		
		p1.coef[counter+1] = '\n';																		//end of array indecator
		p1.power[counter+1] = '\n';
	}
return  p1;
}

PolynomialADT PolynomialADT::operator-()
{
	int counter = 0;
	
	for(int i = 0; coef[i] != '\n' ; i++)
	{
		coef[i] = coef[i] * -1;
		power[i] = power[i];
		counter++;
	}																							//store contents back into passed array and multiplying
		coef[counter+1] = '\n';																	//by -1 then return contents via this poerator 
		power[counter+1] = '\n';
return  *this;
}

PolynomialADT PolynomialADT::operator+(const PolynomialADT& rhs ) const
{ 
	int polyDegThis, polyDegRhs, poly = 1;
	PolynomialADT temp;
	int counter = 0;																		//variables 
	bool bCnt = 0;
	
	polyDegThis = this->degree();
	polyDegRhs = rhs.degree();																//get degree from both polys
		
	if(polyDegThis < polyDegRhs)
	{
		poly = polyDegRhs;
	}
	else																					//figuer what has higher degree
	{
		poly = polyDegThis;
	}

	double add[poly];
	for(int i = 0; i <= poly; i++)
	{
		add[i] = 0; 																		//make arry woth highest degree as size
	}

	for(int i = 0; i <= poly ; i++)
	{
		for(int ii = 0; this->coef[ii]!='\n'; ii++)
		{
			if(this->power[ii] == i)
			{
				add[i] = add[i] + this->coef[ii];
			}																				//nested double loop to add contents by power
		}																					//in new array for both polys
		for(int ii = 0; rhs.coef[ii]!='\n'; ii++)											
		{
			if(rhs.power[ii] == i)
			{
				add[i] = add[i] + rhs.coef[ii];
			}
		}
	}

counter = 0;

	for(int i = poly; i >= 0; i--) 
	{
		 if(add[i] != 0)
		 {
		 	temp.coef[counter] = add[i];													//store contents into a temp variable and return
		 	temp.power[counter] = i;
		 	counter++;
		 }
	}
	temp.coef[counter] = '\n';
	temp.power[counter] = '\n';
return temp;	
}
