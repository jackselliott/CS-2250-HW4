/*
Created by Jack Elliott, 10-22-2022
HW4 CS 2250

NumList class implementation
*/

#include "NumList.h"


//First constructor, takes list and size parameters
NumList::NumList(int *arr, int s )
{
	createArray(arr, s);
}

//Second constructor, no parameters
NumList::NumList()
{
	list = nullptr;
	size = 0;
}


//Third constructor, copy constructor
NumList::NumList(const NumList& obj)
{
	createArray(obj.list, obj.size);
}

//Destructor
NumList::~NumList()
{
	delete[] list;
	list = nullptr;
}


//Function to display each element of an array held by a NumList object
void NumList::display()
{
	cout << "\n\n" << "* ";

	for (int i = 0; i < size; i++)
	{
		cout << list[i] << " ";
	}
	cout << "*" << "\n\n";	
}




