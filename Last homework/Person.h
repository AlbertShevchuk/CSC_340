/*
		Albert Shevchuk 
		CSC340 T/Th @ s2:10pm 
		5/16/17
		Dev-C++
*/
#ifndef _PERSON_H
#define _PERSON_H
#include <iostream>																		//headers
#include <string>
using namespace std;

class Person
{
	public:
	    Person(); 																		//constructor
		~Person(); 																		//destructor
		equalID();																	    // ID check
		friend bool equalID(const Person & person1, const Person &Person2);
		Person( int new_id, string new_name, string date); 								//initializations
		Person(const Person & someone); 												//copy constructor
		void operator= (const Person &rhs); 											//assignment = operator
  
		int get_id() const; 
		string get_name() const; 														//Getters
		const string get_birthday() const;  
  
		void set_id(int new_id); 														
		void set_name(string new_name); 												//Setters
		void set_birthday(string new_Date); 												
  
	private:
		int id;
		string name;																	//Variables 
		string birthday;
};

void print( const Person& someone); 													//print func

#endif	
