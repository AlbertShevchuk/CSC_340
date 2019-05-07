/*
		Albert Shevchuk 
		CSC340 T/Th @ s2:10pm 
		5/09/17
		Dev-C++
*/

#ifndef linklist_h
#define linklist_h
#include <iostream>

using namespace std;

class linklist
{
	private:
		int *array;
		int size_array;
		int capacity;
    	struct Node																			//class, variables and struct 
		{
			int value;
			Node *next;
		};
		
		Node *head;
		int size_linkedList;
    	
	
	public:
    	linklist();
    	~linklist();
    	linklist(const linklist& clone);
    	void push_back(int val);													     //prototypes 
    	void pop_back();
    	void print();
    	friend ostream & operator<<(ostream & os, const linklist &);
    	linklist& operator=(const linklist& rhs);
		 

    
};

#endif 
