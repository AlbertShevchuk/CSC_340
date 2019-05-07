/*
		Albert Shevchuk 
		CSC340 T/Th @ s2:10pm 
		5/16/17
		Dev-C++
*/
#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H
#include "Person.h"
#include <iostream>																							//headers
#include <string>
using namespace std;

class Employee: public Person
{
	public:
		Employee();																						//constructor
		Employee(int new_id, string new_name, string date,int jyear,double bsal);						//
		Employee(const Employee & someone);
		void operator=(const Employee & rhs);															//equal operator
		double getCurrentSalary();																	
		void setJoinedYear(int year);																	//setters
		void addIncreaseRate(double newRate);									
		int getJoinedYear()const;																		//geter
		friend ostream &operator <<(ostream &cout, const Employee & rhs);								//put operator 
		
	private:
		int joinedYear;
		double bSal;	
		double *increaseRate;																			//variables 
		int capacity;
		int size;
};
#endif
