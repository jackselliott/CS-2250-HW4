/*
Created by Jack Elliott, 10-22-2022
HW4 CS 2250

Declaration for NumList class
*/


#ifndef NUMLIST_H
#define NUMLIST_H

#include <iostream>

using namespace std;

class NumList
{
private:
	int *list;
	int size;

	//Creates a dynamic array based on private members. Used throughout NumList class declaration and implementation
	void createArray(int *arr, int s)
	{
		if (list != nullptr)
			delete [] list;

		size = s;
		list = new int[size];

		for (int listS = 0; listS < s; listS++)
			list[listS] = arr[listS];
	}

public:

	//First constructor, two parameters
	NumList(int*, int);

	//Second constructor, no parameters
	NumList();

	//Copy Constructor
	NumList(const NumList& obj);

	//Destructor
	~NumList();


	//Getters
	int* getList()
	{return list;}
		
	int getSize()
	{return size;}

	//Prototype for function to display contents of "list" dynamic array
	void display();


	//Setter
	void setList(int* arr, int s)
	{createArray(arr, s);}


	//Overloaded = operator
	const NumList operator=(const NumList& instToCopy)
	{
		if (this != &instToCopy)
		{
			createArray(instToCopy.list, instToCopy.size);
		}
		return *this;
	}

	//Overloaded += operator
	void operator+=(NumList& instToAdd)
	{
		if (size != instToAdd.size)
		{
			cout << "\n\nError, the two arrays are not the same size.\n\n";
		}
		else if (this != &instToAdd)
		{
			int* temp = nullptr;
			temp = new int[size];

			for (int i = 0; i < size; i++)
				temp[i] = (list[i] + instToAdd.list[i]);

			createArray(temp, size);

			delete[] temp;
		}
	}
};

#endif
