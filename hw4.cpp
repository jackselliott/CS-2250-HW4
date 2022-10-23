/*
Created by Jack Elliott, 10-22-2022
HW4 CS 2250

Main function to test NumList class
*/



#include "NumList.h"

int main()
{
	//These arrays will be used to test member functions, constructors, and overloaded operators of the NumList class
	const int ASIZE = 10;
	const int BSIZE = 5;
	int arrA[ASIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; //arrayA
	int arrB[BSIZE] = { 0, 1, 1, 2, 3 }; //arrayB

	//Explanation of program and display arrays used for testing
	cout << "This program will create objects of the NumList class, which handle arrays of integers of arbitrary size.\n"
		<< "The following arrays of numbers will be used for testing:\n"

		<< "arrayA: ";
			for (int i = 0; i < ASIZE; i++) //Display arrayA
				cout << arrA[i] << " ";

			cout << endl << "arrayB: ";
			for (int i = 0; i < BSIZE; i++) //Display arrayB
				cout << arrB[i] << " ";
			//This is probably way more work than just typing out both arrays in a cout statement, but whatever
			//It's more easily modified this way I guess, kinda

	cout << endl << endl
		<< "I will used the NumList \"display\" member function to output the arrays stored in various NumList objects." << endl
		<< "Output from this function is enclosed in \"*\" for clarity.";
						


	//TEST 1, CONSTRUCTOR WITH 2 PARAMETERS
	NumList obj1(arrA, 10); //Object 1 created with arrayA

	cout << "\n\nObject1, created with arrayA's elements and size. This will invoke the constructor that takes 2 parameters." << endl
		<< "arrayA should be displayed: ";
	 obj1.display();


	//TEST 2, DEFAULT CONSTRUCTOR
	NumList obj2; //No parameters provided, so the default constructor should be invoked

	cout << "Object2, created with the default constructor. Should display nothing: ";
	obj2.display();


	//TEST 3, COPY CONSTRUCTOR
	NumList obj3 = obj1; //Object 3 initialized as equal to Object 1, so the copy constructor should be invoked

	cout << "Object3 initialized as \"=\" to Object1, so the copy constructor will be used." << endl;
	cout << "arrayA should be displayed: ";
	obj3.display();


	//TEST 4, SETTER FUNCTION
	NumList obj4; //Again, default constructor will create a "blank" object
	
	obj4.setList(arrB, 5); //And we can set it to hold arrayB with the setter function

	cout << "Object4, initialized as empty, but passed arrayB using the setter function." << endl
		<< "arrayB should be displayed: ";
	obj4.display();

	
	//TEST 5, OVERLOADED = OPERATOR
	obj2 = obj4;

	cout << "Now, I assigned \"empty\" Object2 equal to Object4. (obj2 = obj4)" << endl
		<< "This should use the overloaded = operator. arrayB should be displayed: ";
	obj2.display();


	//TEST 6, OVERLOADED += OPERATOR

	obj2 += obj4; //This essentially adds all elements of arrayB to themselves

	cout << "Now, I will update Object2 += Object4. This will use the overloaded += operator" << endl
		<< "Because of our previous test, Object2 and Object4 now both hold arrayB. " << endl
		<< "Every element of arrayB added to itself should be displayed: ";
	obj2.display(); 

	cout << "We will also attempt to execute Object1 += Object2." << endl
		<< "Object1 holds arrayA, and Object2 now holds (arrayB + arrayB)." << endl
		<< "Because the arrays are different sizes, an error message should be produced, "
		<< "and neither array should be changed";

	obj1 += obj2; //Should cause an error, because the arrays are different sizes

	cout << "And now we will display Object1 and Object2 again to make sure they are unaltered." << endl
		<< "arrayA and (arrayB + arrayB) should be displayed: ";

	obj1.display();
	obj2.display();

}