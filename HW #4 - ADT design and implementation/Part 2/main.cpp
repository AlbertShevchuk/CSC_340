/*
		Albert Shevchuk 
		CSC340 T/Th @ s2:10pm 
		3/27/17
		Dev-C++
*/

#include <iostream>
#include "Matrix.h"

int main(int argc, char **argv)
{	

vector< vector<double> > v2d;
	int SIZE;
	cout<<"#1"<<endl;	
	Matrix m;
	cout<<"#1 done"<<endl<<endl;
	cout<<"#2"<<endl;
	m.SquareMatrix(v2d);
	cout<<"#2 done"<<endl<<endl;
	cout<<"What is the size of your square matrix?";
	cin>>SIZE;
	m.input(SIZE);
	cout << m;
	
	//didnt have time to finish menu but its pretty straight foward
	

    return 0;
}
