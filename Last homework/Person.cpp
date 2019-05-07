/*
		Albert Shevchuk 
		CSC340 T/Th @ s2:10pm 
		5/16/17
		Dev-C++
*/
#include "Person.h"
#include <iostream>																					//headers
#include <string>

Person::~Person()																					//desctructor
{ }

Person::Person()
{
	id = -1;
	name = "NA";																					//default constructor
	birthday = "1/1/2017";   
}

Person::Person(int new_id, string new_name, string date)
{
	id = new_id;
	name = new_name;																				//initilizations
	birthday = date;
}

Person::Person(const Person & someone)
{
	id = someone.id;
	name = someone.name;																			//mutator sfunctio
	birthday = someone.birthday;
}

void Person::operator=(const Person & rhs)
{
	id = rhs.id;
	name = rhs.name;																				//operator= const func
	birthday = rhs.birthday; 
}

int Person::get_id() const
{return id;}																					// getter


string Person::get_name() const
{return name;}																					//getter

const string Person::get_birthday() const
{return birthday;}

void Person::set_id(int new_id)
{id = new_id;}

void Person::set_name(string new_name)															//setters
{name = new_name;}

void Person::set_birthday(string date)
{birthday = date;}

void print(const Person& someone)
{
   cout << "****"<<someone.get_id() << "\n" << someone.get_name() <<endl;
   cout<<someone.get_birthday()<<endl;															//print func
}

bool equalID(const Person& person1, const Person& person2)										//id check
{return (person1.id == person2.id);}
