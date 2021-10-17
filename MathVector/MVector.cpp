#include "MVector.h"
#include <malloc.h>
#include <iostream>
#include <cmath>


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
/*
double* MVector::getData()
{
	return this->data; // returns the location address of our array
}*/

void MVector::setDataElements(double dataValue, int index)
{
	this->data[index] = dataValue;

}

//Display vector data to the screen
void MVector::displayVector(MVector* vec)
{
	cout << "Vector size: " << getSize();
	cout << "\nVector data: ";
	for (int i = 0; i < size; i++)
	{
//		cout << vec->getData()[i] << ", ";
		cout << data[i] << ", ";	// you don't need to use the get methods within the class and it is usually more efficient (and effective) to directly use the data members
	}
	cout << "\n\n";
}

MVector* MVector::addVectors(MVector* vec2)
{
	// loop through vec1 and vec 2, adding the value of the indexes together and assign to vec3
	// i.e vec3[i] = ve1[i] + vec2[i]

	MVector* vec3 = new MVector(size);

	double val;

	for (int i = 0; i < size; i++)
	{
//		val = data[i] + vec2->getData()[i];
//		vec3->setDataElements(val, i);
		vec3->data[i]=data[i]+vec2->data[i];	// we haven't covered this yet, but instances of the same class can access private data members
	}
	return vec3;
}

double MVector::generateMagnitude(/*MVector* vec*/)	// you want to calculate the magnitue of "this" vector
{
	double sum = 0;

	//iterate through the array and sum all the elements
	for (int i = 0; i < size; i++)
	{
		// calculate sum
		// square the elements and add to sum
		sum += (data[i] * data[i]);
	}
	return sqrt(sum);
}

MVector* MVector::normaliseVector()//MVector* vec, double magnitude)
{
	// Normalise vector means to divide each element by it's magnitde to get 1
	// Take in a vector
	// Copy all elements to a newly created vector
	// calcualte its magnitude 
	// divide each element by the magnitude


	// create a new vector with the same size as the original vector
	MVector* normalisedVector = new MVector(size);
	double mag=generateMagnitude();

	// set all elements of new vector to be same as the original
	// and divide by 
	for (int i = 0; i < size; i++)
	{
		//normalisedVector->setDataElements(vec->getData()[i]/magnitude, i);
		normalisedVector->data[i]=data[i]/mag;
	}

	return normalisedVector;
}

// this can be a static member function as it doesn't use any of the class data (we will cover this in week 4)
double MVector::dotProductUsingCos(double magnitude1, double magnitude2, int angle)
{
	// The dot product is also known as the scalar value
	// it is calculated by multiplying magnitudes of the two vectors and the cosign of the angle between the two vectors

	return magnitude1 * magnitude2 * (cos(angle));
}

double MVector::dotProductByMultiplying(MVector* vec2)
{
	// We can also calcualte the dot products by simply multiplying elements in corresponding indexes together
	double dotProduct = 0;

	for (int i = 0; i < size; i++)
	{
		dotProduct += (data[i] * vec2->data[i]);
	}

	return dotProduct;
}





