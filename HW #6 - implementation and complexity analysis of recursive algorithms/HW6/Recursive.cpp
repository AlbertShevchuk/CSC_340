/*
		Albert Shevchuk 
		CSC340 T/Th @ s2:10pm 
		4/23/17
		Dev-C++
*/

#include "Recursive.h"

const int Recursive::SIZE = 20;									//global variable to set size of array, if changed also change in Main

Recursive::Recursive():array(SIZE)
{ 
	for(int i = 0; i <= SIZE; i++)
	{															//Defalut Constructor Setting vector size and pupulating with random numbers
		array[i] = rand();
	}	
}

Recursive::largestNum(int max, int counter)		//using counter to run threw array while re-iterating 
{
	if(array[counter]>max)
	{
		max = array[counter];					//compare whats larger then store 
	}
	
	if(counter < SIZE)														
	{
		largestNum(max, counter+1);				//if you reach the end of the array, stop re-iterating
	}
	else
		return max;								
}

void Recursive::print() const
{
	for(int i = 0; i <= SIZE; i++)
	{
		cout<<array[i]<<" ";				//Print function
	}
	
	cout<<endl<<endl;
}

Recursive::quickRecursive(int left, int right) 
{

    int i = left, j = right;									//duplicate values, gonna use original later
    int tmp;													//Variables
    int pivot = array[(left + right) / 2];						//pivot in the middle
	
	while (i <= j) 												// loop while left is bigger or equal to right
	{
        while (array[i] < pivot)								//if value is smaller then pivot then incument
        {   
		    i++;
		}

        while (array[j] > pivot)
		{
            j--;												//if value is bigger then pivot the decrumetn
		}
        
		if (i <= j) 
		{
            tmp = array[i];
            array[i] = array[j];								//if left is <= right then swap L++,R--
            array[j] = tmp;
            i++;
            j--;
        }
	}
	
    if (left < j)
    {
    	quickRecursive(left, j);
	}														//sorting mechanism calls the finction over again untill j,i swich with Right,Left 
    if (i < right)
	{
	    quickRecursive(i, right);
	}
}


Recursive::partition(int left, int right)
{
	
    int range=(right-left+1);
    int pivot=(left+right)/2;							//pivot in the middle again										
 
    
    while(left<right)									// loop while left is bigger or equal to right
    {
        while(array[left]<array[pivot])					//if value is smaller then pivot then incument
        {
		   left++;
		}
        while(array[right]>array[pivot])			//if value is bigger then pivot the decrumetn
        {
			right--;
		}
        if(array[left]==array[right])				//if left and right met incrument left
        {
        	left++;
		}
        else if(left<right) 
		{
           int tmp = array[left];
           array[left]=array[right];				//if left is < right then swap 
           array[right]=tmp;
        }
    }
    return right;									//return right to use for kSmall()
}

Recursive::kSmall(int left, int right, int k)
{
    if (left == right)
	{
		return array[left];								//if left and right met return value of left
	}
        
    int pivot = partition(left, right);			//use partiton to come up with index
    int length = (pivot - left + 1);
    
    if (length == k)
	{
		return array[pivot];						//if the k value equals to the length return index
	}   
    else if (k < length)
	{
		return kSmall(left, (pivot--), k);					//if k less then over all lennght, decrument pivot recall ksmall till return
	} 
    else  
    {
    	return kSmall((pivot++), right, (k - length));		//if k bigger over all lennght, incrument, subract form k and recall ksmall till return
	}  
}



