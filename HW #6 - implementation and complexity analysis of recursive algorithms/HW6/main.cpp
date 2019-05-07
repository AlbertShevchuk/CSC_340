/*
		Albert Shevchuk 
		CSC340 T/Th @ s2:10pm 
		4/23/17
		Dev-C++
*/

#include "Recursive.h"

int main(int argc, const char * argv[]) 																							
{
	int SIZE = 20;															//global variable to set size of array, if changed also change in Recursive.cpp
	
	int max,k,val = 0;
	
	cout<<"Welcome to Albert's Homework 6"<<endl<<endl;
	cout<<"A default constructor that initializes all the elements in this array1 to random numbers "<<endl<<endl;
	Recursive r1;																															//part1
	cout<<"Array1: "<<endl;
	r1.print();
	
	cout<<"A member function that recursively searches the largest number in the array1."<<endl;
	max = r1.largestNum(0,0);																												//part2
	cout<<"This function returns "<<max<<" as the value of the largest number."<<endl<<endl;
		
	cout<<"A member function that recursively finds the value of the k-th smallest number in the array2."<<endl;
	cout<<"Enter the k'th number: ";
	cin>>k;																																	//part3
	val = r1.kSmall(0,SIZE,k);
	cout<<"k'th Value: "<<val<<endl<<endl;
	
	cout<<"A member function that implements the recursive QuickSort algorithm to sort the array2 in increasing order. Array2 befor recursive QuickSort: "<<endl<<endl;
	Recursive r2;
	r2.print();
	r2.quickRecursive(0,SIZE);																												//part4
	cout<<"Array2 after recursive QuickSort: "<<endl<<endl;
	r2.print();

    return 0;
}
