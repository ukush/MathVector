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

double* MVector::getData()
{
	return this->data; // returns the location address of our array
}

void MVector::setDataElements(double dataValue, int index)
{
	this->data[index] = dataValue;

}

//Display vector data to the screen
void MVector::displayVector(double* vecArr, int size)
{

	cout << "Vector size: " << this->getSize();
	cout << "\nVector data: ";
	for (int i = 0; i < size; i++)
	{
		cout << vecArr[i] << ", ";
	}
	cout << "\n\n";
}

MVector* MVector::addVectors(double* vec1Arr, double* vec2Arr, int size)
{
	// loop through vec1 and vec 2, adding the value of the indexes together and assign to vec3
	// i.e vec3[i] = ve1[i] + vec2[i]

	MVector* vec3 = new MVector(size);

	double val;

	for (int i = 0; i < size; i++)
	{
		val = vec1Arr[i] + vec2Arr[i];
		vec3->setDataElements(val, i);
	}
	return vec3;
}

double MVector::generateMagnitude(double* vecArr, int size)
{
	double sum = 0;

	//iterate through the array and sum all the elements
	for (int i = 0; i < size; i++)
	{
		// calculate sum
		// square the elements and add to sum
		sum += (vecArr[i] * vecArr[i]);
	}
	return sqrt(sum);
}

MVector* MVector::normaliseVector(double* vecArr, double magnitude, int size)
{
	// Normalise vector means to divide each element by it's magnitde to get 1
	// Take in a vector
	// Copy all elements to a newly created vector
	// calcualte its magnitude 
	// divide each element by the magnitude


	// create a new vector with the same size as the original vector
	MVector* normalisedVector = new MVector(size);

	// set all elements of new vector to be same as the original
	// and divide by 
	for (int i = 0; i < size; i++)
	{
		normalisedVector->setDataElements(vecArr[i]/magnitude, i);
	}

	return normalisedVector;
}

double MVector::dotProductUsingCos(double magnitude1, double magnitude2, int angle)
{
	// The dot product is also known as the scalar value
	// it is calculated by multiplying magnitudes of the two vectors and the cosign of the angle between the two vectors

	return magnitude1 * magnitude2 * (cos(angle));
}

double MVector::dotProductByMultiplying(double* vec1Arr, double* vec2Arr, int size)
{
	// We can also calcualte the dot products by simply multiplying the vectors together
	double dotProduct = 0;

	for (int i = 0; i < size; i++)
	{
		dotProduct += (vec1Arr[i] * vec2Arr[i]);
	}

	return dotProduct;
}





