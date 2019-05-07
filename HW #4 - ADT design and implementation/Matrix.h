/*
		Albert Shevchuk 
		CSC340 T/Th @ s2:10pm 
		3/27/17
		Dev-C++
*/

#include <iostream>
#include <vector>
using namespace std;
#ifndef Matrix_h
#define Matrix_h

class Matrix{
private:																				
    vector< vector<double> > values ;
public: 
	Matrix();
	SquareMatrix(vector< vector<double> > v2d);
	double getValue(int i, int j) const;
	void setValue(int i, int j, double value);
	Matrix operator*(const Matrix& rhs) const;
	Matrix operator-(const Matrix& rhs) const;
	friend ostream& operator << (ostream& oS, const Matrix& rhs);
	void input(int size);
   
};

#endif 
