/*
		Albert Shevchuk 
		CSC340 T/Th @ s2:10pm 
		2/28/17
		Dev-C++
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>

using namespace std;
ifstream inFile;																						//read / write stream 
ofstream outFile;

struct TokenFreq
{
	string value;																						//structure
	int freq;
};

vector<TokenFreq> getTokenFreq(vector<TokenFreq>, string  inFile_name);
void selectionSort( vector<TokenFreq> & tokFreqVector);													//proto types for all functions 
void insertionSort( vector<TokenFreq> & tokFreqVector);
void writeToFile( vector<TokenFreq> &tokFreqV, string outFileName);

int main()
{
	vector<TokenFreq> Vector;																			// Vector created in main
	string fileName;																					
	
	cout<<"What is the exact name of the file that you would like to read?: ";																						
	cin>> fileName;																						//user filename input and call	
	Vector = getTokenFreq(Vector, fileName);															
	cout<<endl;	
	
	selectionSort(Vector);
	fileName.resize(0);
	cout<<"What is the name of the file that you would like to write after Selection Sort? (Dont forget extention .txt) : ";	//call and user filename output 
	cin>> fileName;
	writeToFile(Vector,fileName);
	cout<<endl;
	
	insertionSort(Vector);
	fileName.resize(0);
	cout<<"What is the name of the file that you would like to write after Insertion Sort? (Dont forget extention .txt)"<<endl;
	cout<<"MAKE SURE TO NAME THIS FILE SOMETHING DIFFERENT FROM WHAT YOU NAMED IT IN Selection Sort OTHERWISE YOU WILL OVERWRITE THE EXISTING FILE ) : ";	//call and user filename output 
	cin>> fileName;
	writeToFile(Vector,fileName);

	return 0; 
}

void writeToFile( vector<TokenFreq> &tokFreqV, string outFileName)
{
	outFile.open(outFileName.c_str());															//automatic conversion to const char*
	
	for(unsigned int i = 0; i < tokFreqV.size(); i++)
	{
		outFile<< tokFreqV.at(i).value<<": "<<tokFreqV.at(i).freq<<endl;						// loops threw the vector and writes
	}
		
	outFile.close();																			// close and clear outstream
	outFile.clear();
}

void insertionSort( vector<TokenFreq> & tokFreqVector)
{
	int j;
	
	for(int i = 1; i < tokFreqVector.size(); i++)												// loop once starting from the second token assuming first is already sorted
	{
		j = i;																					// j used for 2nd loop to seperate sorted from not sorted
		
		while((j>0) && (tokFreqVector.at(j-1).freq < tokFreqVector.at(j).freq))					// compares past varable if smaller then current then swap 
		{																						// keeps swapping untill is bigger, so all bigger end up at the beggining  
			swap(tokFreqVector.at(j),tokFreqVector.at(j-1));
			j--;	
		}
	}
}

void selectionSort( vector<TokenFreq> & tokFreqVector )
{	
	int min;

	for(int pos = 0; pos < tokFreqVector.size(); ++pos)
	{
		min = pos;																				// 1st variable is considered smallest 
		
		for(int i = pos + 1; i < tokFreqVector.size(); ++i)										//2nd loop starts with next position after 1st loops
		{
			if(tokFreqVector.at(i).freq < tokFreqVector.at(min).freq)							// if next smaller then min then set new min position			
			{
				min = i;
			}
		}
		if(min != pos)																			//if the position and minimum does not equal to each other then swap
		{
			swap(tokFreqVector.at(min),tokFreqVector.at(pos));
		}
	}
}

vector<TokenFreq> getTokenFreq(vector<TokenFreq> Vector, string  inFile_name)
{	
	TokenFreq Token;
	string temp;																									
	string filtTemp;
	
	inFile.open(inFile_name.c_str());         																		//automatic conversion to const char*
		
	if (inFile.fail())
	{
		cout<<"Failed to open the file: "<<inFile_name<<" , Please check the following and try again!!!"<<endl;		//File check
		cout<<"-Correct Spelling"<<endl;
		cout<<"-Make shure the file has the extention (.txt) at the end"<<endl;
		cout<<"-Make shure the file your trying to open is in the same folder as the executable"<<endl;
		exit(-1);
	}

	while (!inFile.eof())
	{
    	getline(inFile, temp);																						//begin reading the file (since getline reads by blocks, filtering mechanizm is looped inside)
    		
		for(unsigned int i = 0; i < temp.length(); i++ )															// filteres everything out but 'a'-'z' ' ' and converts 'A'-'Z' to lowercase and stores into filtered string  
		{
			if((temp[i]>='a'&&temp[i]<='z')||(temp[i]==' '))															 		
			{					
				filtTemp.push_back(temp[i]);																																
			}
			else if((temp[i]>='A'&&temp[i]<='Z'))
			{
				filtTemp.push_back(tolower(temp[i]));
			}
		}
	
		filtTemp.push_back(' ');																					//since getline reads by blocks, there needs to be a space between blocks so words are not morfed 2gether 																	 
	}
	
	inFile.close();																									// close and clear instream 	
	inFile.clear();																										

	temp.resize(0);																									// resize temp b4 use just in case
		
	for(unsigned int i = 0; i <= filtTemp.length(); i++ )																
	{ 
		if((filtTemp[i]==' ')||(filtTemp[i]==NULL))
		{
			Token = {temp,0};
			Vector.push_back(Token);																				// use spaces between words to identify words and pack every word insde the vector setting default freq to zero
			temp.resize(0);																							// NULL is an exeption for the very last word 
		}																											// this will allow empty words to be registered but i delete them later	
		else
		{
			temp.push_back(filtTemp[i]);
		}
	}
	
	for(unsigned int i = 0; i < Vector.size(); i++)
	{
		if(Vector.at(i).value == "")
		{
			Vector.erase(Vector.begin()+i);																			// Takes care of any empty spaces that were allowed because of the ' ' and/or NULL
			i--;	
		}
	}
	
	int counter = 1;																								// counter for words there is always 1 word

	for(unsigned int i = 0; i < Vector.size(); i++)																			
	{
		for(unsigned int j = i+1; j < Vector.size(); j++)
		{
			if(Vector.at(i).value == Vector.at(j).value)
			{
				counter++;
				Vector.erase(Vector.begin()+j);																		// identifys each reaccuring word, dellets thats section off the vector, adds to counter, backtracks position by one since 
				j--;																								// section was delletd, once inner loop identifys #of words and delletes em, freq of the original word is stored @ orifinal vector 
			}	
		}
		Vector.at(i).freq = counter;
		counter = 1;
	}

	return (Vector); 																								// returns vector																							
}
