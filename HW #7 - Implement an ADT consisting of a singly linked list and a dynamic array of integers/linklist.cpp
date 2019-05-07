/*
		Albert Shevchuk 
		CSC340 T/Th @ s2:10pm 
		5/09/17
		Dev-C++
*/

#include <iostream>
#include <new>
#include "linklist.h"

using namespace std; 

linklist::linklist():array(NULL),size_array(0),head(NULL),size_linkedList(0)
{ 
 capacity = 15;
    try{
        array = new int [capacity];
    }
    catch( bad_alloc& e)																		//initilize objexts and the array
    {
        std::cout << e.what();
    }
    for (int i=0; i<capacity; i++)
        array[i] = 0;        
}

linklist::~linklist()
{
    if (array!=NULL)
        delete [] array;
			
	Node *ptr; 
																							//delete both array and every emement of linked list
	while(head != NULL)
	{
		ptr = head;
		head = head->next;
		delete ptr;			
	}	
}

void linklist::push_back(int val)
{
	Node *tmp = head;
		
	if(!head)
	{
		head = new Node;
		head->value = val;																	//if head is not created
		head->next = NULL;
	}
	else																					
	{	
		while(tmp->next != NULL)
		{
			tmp = tmp->next; 
		}
																							//or add to the end
		Node* newNode = new Node();
		newNode->value = val;
		newNode->next = NULL;
		tmp->next = newNode;
	}
	
	array[size_array] = val;
	size_array++;																			//incrument/set variables 
	size_linkedList++;	
}

void linklist::pop_back()
{
	Node *tmp = head;
	Node *prev;

	if(head)
	{	
		if(head->next == NULL)
		{
			delete tmp;																		//if head is lonsome 
			head = NULL;
		}
		else
		{	
			while(tmp->next != NULL)
			{	prev = tmp;	
				tmp = tmp->next; 															//thraverce and delete 
			}
			
			delete tmp;
			prev->next = NULL;
		}
	}
	
	array[size_array] = 0;
	size_array--;
}

ostream & operator<<(ostream & os, const linklist & q)
{
	os<<endl<<"Linked List"<<endl;
    for(linklist::Node* n = q.head; n != NULL; n = n->next)									// print linked list
    {
       os << n->value<<" ";
    }
    
    os <<endl<< "Dynamic Array"<<endl;
    
    for(int i = 0; i <= q.capacity; i++)													// print array
    {
       os << q.array[i]<<" ";
    }
    	
    return os;
}

linklist::linklist(const linklist& clone)
{	
  Node* curr;
  Node* tr;
  
  head = new Node;
  head->value = clone.head->value;															//create the first node	and copy elements
  
  curr = head;
  tr = clone.head->next;
  
  while(tr != NULL)
  {
		curr->next = new Node;
		curr = curr->next;																		
		curr->value = tr->value;															// create more elements if needed and copy elements
		tr = tr->next;  	
  }	
  
  curr->next = NULL;
  
  this->size_array = clone.size_array;
      capacity = clone.capacity;
																						// copy elements and create new dynameic array    
    if (capacity >0)														
	{
        array = new int[capacity]; 
        for (int i=0; i<size_array; i++)
        array[i] = clone.array[i];
    }
}

linklist& linklist::operator=(const linklist& rhs)
{
	Node* curr;
  	Node* tr;
  
  head = new Node;
  head->value = rhs.head->value;
  
  curr = head;
  tr = rhs.head->next;																	//traverce and identify the items that needed to be copied.
  
  while(tr != NULL)
  {
		curr->next = new Node;
		curr = curr->next;
		curr->value = tr->value;
		tr = tr->next;  	
  }	
  
  curr->next = NULL;

  if (rhs.capacity == 0)
  { 
      if (array!=NULL)
	  {
         delete [] array;
         array = 0;
      }
        capacity = rhs.capacity;
        size_array = rhs.size_array;
  }
        
    if (capacity == rhs.capacity)
	{
        size_array = rhs.size_array;
        for  (int i=0; i<size_array; i++)
            array[i] = rhs.array[i];
    }																					//traverce and identify the items that need to be copied for dynamic array
   
    if (capacity != rhs.capacity)
    {	
		capacity = rhs.capacity;
		size_array = rhs.size_array;
		for  (int i=0; i<size_array; i++)
            array[i] = rhs.array[i];			
	}
    
    return *this; 
  
}
