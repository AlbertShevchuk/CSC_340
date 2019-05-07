/*
		Albert Shevchuk 
		CSC340 T/Th @ s2:10pm 
		4/23/17
		Dev-C++
*/

#ifndef Recursive_h
#define Recursive_h
#include <iostream>													//libraries 
#include <cstdlib>
#include <vector>
using namespace std;

class Recursive 
{

	public:															//public variables just cuz
	
		static const int SIZE;										
    	vector<int> array;											// vector as storage 

	    Recursive();
	    largestNum(int max, int counter);
	    quickRecursive(int left, int right);
	    partition(int left, int right);								//prototypes 
	    kSmall(int left, int right, int k);
	    void print() const;
    
};

#endif 
