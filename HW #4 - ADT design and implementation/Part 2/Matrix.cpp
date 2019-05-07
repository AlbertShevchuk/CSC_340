/*
		Albert Shevchuk 
		CSC340 T/Th @ s2:10pm 
		3/27/17
		Dev-C++
*/

#include <iostream>
#include "Matrix.h"

Matrix::Matrix()
{ 
  values = vector<vector <double> >  (10 , vector<double> (10, 0.0)); //	array.resize(10,vector<double>(10,0.0));
}

Matrix::SquareMatrix(vector<vector<double> > v2d)
{
	values = vector<vector <double> >  (10 , vector<double> (10, 0.0));	
	
	bool check = 0;
	int row = 0;
	int collum = 0;

	for(int i = 0; i < v2d.size(); i++)
	{
		for(int ii = 0; ii < v2d.size(); ii++)
		{
			v2d[i][ii] = values[i][ii];	
			row++;	
		}
		collum++;
	}
	
	if(row == collum)
	{
		cout<<"Your Matrix is square!"<<endl;
	}
	else
	{
		cout<<"Your Matrix is not square!"<<endl;
	}
	
}

double Matrix::getValue(int i, int j) const
{
	cout<<"Enter position for i: ";
	cin>> i;
	cout<<"Enter position for j: ";
	cin>> j;
	
	return (this->values[i][j]);
}

void Matrix::setValue(int i, int j, double value)
{
	this->values[i][j] = value;	
}

Matrix Matrix::operator*(const Matrix& rhs) const
{ 
	Matrix m3;
	
	for(int i = 0; i < rhs.values.size(); ++i)
    {
	    for(int j = 0; j < rhs.values.size(); ++j)
        {
			for(int k = 0; k < rhs.values.size(); ++k)
            {
                m3.values[i][j] += this->values[i][k] * rhs.values[k][j];
            }
		}
	}
	
	return m3;
}

Matrix Matrix::operator-(const Matrix& rhs) const
{ 
	Matrix m3;
	
	for(int i = 0; i < rhs.values.size(); i++)
	{
		for(int j = 0; j < rhs.values.size(); j++)
		{
			m3.values[i][j]=this->values[i][j]-rhs.values[i][j];
		}
	}
	
	return m3;
}

ostream& operator<<(ostream& oS, const Matrix& matrix) 
{
	
	for(int i = 0; i < matrix.values.size(); i++)
	{
		for(int ii = 0; ii < matrix.values.size(); ii++)
		{
			cout<<"  "<<matrix.values[i][ii];	
		}
		cout<<endl;
	}
	
	return oS;
}

void Matrix::input(int size)
{
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			cout<<"Enter Element: ";
			cin>>this->values[i][j];
		}
	}
}
