/*
		Albert Shevchuk 
		CSC340 T/Th @ s2:10pm 
		5/16/17
		Dev-C++
*/

#include "Employee.h"
#include "Person.h"																						  					//headers
#include <iostream>
#include <string>
Employee::Employee():Person()
{
	joinedYear = 0;
	bSal = 0;																												//consrtuctor of  person
	capacity = 100;
	increaseRate = new double[capacity];
	size = 0;
}

Employee::Employee(int new_id, string new_name, string date,int jyear,double bsal):Person(new_id, new_name, date)
{
	joinedYear = jyear;
	bSal = bsal;
	capacity = 100;																											//initilize of person 
	increaseRate = new double[capacity];
	size=0;
}

Employee::Employee(const Employee & someone):Person(someone.get_id(), someone.get_name(), someone.get_birthday())
{
	joinedYear = someone.joinedYear;
	bSal = someone.bSal;
	capacity = someone.capacity;																						//initilize the copr conster
	increaseRate = new double[capacity];
	for(int i=0;i<someone.size;i++)
	{
		increaseRate[i] = someone.increaseRate[i];
	}
	size=someone.size;
}

void Employee::operator=(const Employee & someone)//:Person(someone.get_id(), someone.get_name(), someone.get_birthday())
{
	joinedYear=someone.joinedYear;
	bSal=someone.bSal;
	capacity=someone.capacity;
	increaseRate=new double[capacity];																				//operator = func 
	for(int i=0;i<someone.size;i++)
	{
		increaseRate[i]=someone.increaseRate[i];																	// add all the rate increases
	}
	size = someone.size;
}

double Employee::getCurrentSalary()
{
	double tmp = bSal;
	double rate = 1;
	if(size > 0)
	{																												//getter function of the totals salery
		for(int i = 0;i<size;i++)
			rate = rate *(1+increaseRate[i]);
			tmp = bSal * rate;
	}

return tmp;
}
/*
void Employee::setJoinedYear(int year)
{joinedYear = year;}																								//getter
*/
void Employee::addIncreaseRate(double newRate)
{
	if(size < capacity)
	{
		increaseRate[size] = newRate;																				// add a new rate to existing rate
		size++;
	}
}

int Employee::getJoinedYear() const
{return joinedYear;}																								//getter

ostream& operator<<(ostream &cout, const Employee & rhs)//:Person(rhs.get_id(), rhs.get_name(), rhs.get_birthday())
{
	cout<<"Id:"<<rhs.get_id()<<endl;
	cout<<"Name:"<<rhs.get_name()<<endl;
	cout<<"Birthday:"<<rhs.get_birthday()<<endl;
//	cout<<"Joined Year:"<<Employee::getJoinedYear()<<endl;															// put operator for the printing 
//	cout<<"Base Salary:"<<rhs.bSal()<<endl;
//	cout<<"Current Salary:"<<rhs.getCurrentSalary()<<endl;
return cout;
}
