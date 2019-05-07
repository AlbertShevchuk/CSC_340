/*
		Albert Shevchuk 
		CSC340 T/Th @ s2:10pm 
		2/14/17
		Dev-C++
*/
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

void getLetterFreq(string s)
{
	cout<<endl;																
												
	for(int counter = 97; counter != 123; counter++)							// loop threw 'a' - 'z'
	{
		int freq=0;																//frequentcy counter
		for(int counter1 = 0 ; s[counter1] != NULL; counter1++)					//inner loop's threw s untill '/n' found
			{
				if(s[counter1]>=97 && s[counter1]<=122)							//filters only 'a'-'z'					
				{
					if(s[counter1] == counter)									//equivalance ckeck
					{
						freq++;													//incrument 		
					}
				}
			}
		if(freq>0)
		cout<<"Frequency of "<< (char)counter <<": "<<freq<<endl;				//filters all the zeors out and prints 
	}
}

//above function loops from a-z and while inner loop loop's threw string to see how many times first loop's letter appears in string 
																				
void StrToTokens(string s)
{
	cout<<endl;
	char temp[99];																// array to store the filtered values
	int i = 0;																	// to move threw the array		
	
	for(int counter1 = 0 ; s[counter1] != NULL; counter1++)						// read the string untill '/n'
	{
		if(s[counter1]>=97 && s[counter1]<=122)									// identifys 'a'-'z'		
		{					
			temp[i] = s[counter1];												//adds value to array and incuments i
			i++;
		}
		else if((s[counter1]==32)||(s[counter1]==46))						    // if a ' ' or a '.' 
		{																		//then also adds to array and incument i	
				temp[i] = s[counter1];
				i++;	
		}
	}
	
	temp[i] = NULL;																//once finish, a '/n' is placed at the end of the array to identiy the end of string
	
	for(int counter2 = 0 ; temp[counter2] != NULL; counter2++)					//loops threw the created array and prints contents ubtill '/n'	
	{
		cout<<temp[counter2];
	}
}
	
int main()
{
string s;																			

do
{
	cout<< "Enter up to 100 'a' - 'z' (case sensitive) characters includes spaces's and period's: ";
	getline (cin,s);																		//read keybord into string s
	getLetterFreq(s);																		//functions calls passing s
	StrToTokens(s);
	cout<<endl<<endl<<"Loop again? Enter yes or no: ";
	getline (cin,s);
	cout<<endl;
}
while(s[0] == 'y');
  return 0;
}
