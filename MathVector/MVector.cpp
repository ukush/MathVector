#include "MVector.h"
#include <malloc.h>
#include <iostream>

using namespace std;

MVector::MVector(int size)
{
	this->size = size;
	this->data = (double*)malloc(sizeof(double) * size);
}

MVector::~MVector()
{
	free(this->data);

}


int MVector::getSize()
{
	return this->size;
}

double* MVector::getData()
{
	return this->data; // returns the location address of our array
}
void MVector::setSize(int theSize)
{
	this->size = theSize;
}

void MVector::setDataElements(double dataValue, int index)
{
	this->data[index] = dataValue;
	
}

//Display vector to the screen
void MVector::displayVector(double* dataptr, int size)
{

	cout << "Vector size: " << this->getSize() << "\n";
	cout << "Vector data: ";
	for (int i = 0; i < size; i++)
	{
		cout << dataptr[i] << ", ";
	}
	cout << "\n";
}

MVector* MVector::addVectors(MVector* vec1, MVector* vec2)
{
	MVector* vec3 = new MVector(10);

	// loop through vec1 and vec 2, adding the value of the indexes together and assign to vec3
	// i.e vec3[i] = ve1[i] + vec2[i]

	for (int i = 0; i < vec1->getSize(); i++)
	{
		// access the values of the vector
		vec3->getData()[i] = vec1->getData()[i] + vec2->getData()[i];
	}

	return vec3;
}

int main()
{
	// create pointers for the newly created vector objects 
	MVector* vec1 = new MVector(10);
	MVector* vec2 = new MVector(10);

	// Set the elements of the data array to 1,2,3....10
	for (int i = 0; i < vec1->getSize(); i++)
	{
		vec1->setDataElements(i, i);
	}

	// print out vector 
	vec1->displayVector(vec1->getData(), vec1->getSize());

	cout << "\n";

	cout << "This vector has " << vec2->getSize() << " elements\n"; // show number of elements

	// set values for vec2 data
	for (int i = 0; i < vec2->getSize(); i++)
	{
		// Allow user to set the values for the vector themselves
		cout << "Enter value #" << (i+1) << " to set the vector element: ";
		int val;
		cin >> val;
		vec2->setDataElements(val, i); // set values
	}

	vec2->displayVector(vec2->getData(), vec2->getSize());

	// add two vectors together
	

	return 0;
}

