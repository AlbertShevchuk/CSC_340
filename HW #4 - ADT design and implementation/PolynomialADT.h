/*
		Albert Shevchuk 
		CSC340 T/Th @ s2:10pm 
		3/27/17
		Dev-C++
*/

#include <iostream>
using namespace std;
#ifndef PolynomialADT_h
#define PolynomialADT_h

class PolynomialADT{
private:
    unsigned int maxDegree;
    double coef[200];																					//class variables
    int power[200];
public: 
	PolynomialADT();
    PolynomialADT(unsigned int degree);
    void input(int terms);
    double getCoef(int i) const;																	
    int getPower(int i) const;																		//prototypes 
    double getCoeff(int power) const;
    int degree() const;
    void setCoeff(int power, double newCoefficient);
    PolynomialADT operator/(const double& scalar);
    void print(int terms) const;
    PolynomialADT operator-();
    PolynomialADT operator+(const PolynomialADT& rhs ) const;
    
};

#endif 
