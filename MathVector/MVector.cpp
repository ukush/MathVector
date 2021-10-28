#include "MVector.h"
#include <malloc.h>
#include <cmath>


MVector::MVector(int size) : size(size)
{
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

void MVector::setDataElements(double dataValue, int index)
{
	this->data[index] = dataValue;

}

MVector* MVector::addVectors(MVector* vec)
{
	// loop through vec1 and vec 2, adding the value of the indexes together and assign to vec3
	// i.e vec3[i] = ve1[i] + vec2[i]

	// what if the sizes are not the same??
	// make sure they are the same!
	assert(size == vec->size);

	MVector* res = new MVector(size); // dont need to free up memory in this fucntion

	for (int i = 0; i < size; i++)
	{
		res->data[i] = data[i] + vec->data[i];	// we haven't covered this yet, but instances of the same class can access private data members because you are still IN THE CLASS
	}
	return res;
}

// overloaded addVector method
MVector* MVector::addVectors(int value)
{
	MVector* vector2 = new MVector(size);

	for (int i = 0; i < size; i++)
	{
		vector2->data[i] = data[i] + value;
	}
	return vector2;
}


double MVector::generateMagnitude()
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

MVector* MVector::normaliseVector()
{
	// Normalise vector means to divide each element by it's magnitde to get 1
	// Take in a vector
	// Copy all elements to a newly created vector
	// calcualte its magnitude 
	// divide each element by the magnitude


	// create a new vector with the same size as the original vector
	MVector* normalisedVector = new MVector(size);
	double mag = generateMagnitude();

	// set all elements of new vector to be same as the original
	// and divide by 
	for (int i = 0; i < size; i++)
	{
		//normalisedVector->setDataElements(vec->getData()[i]/magnitude, i);
		normalisedVector->data[i] = data[i] / mag;
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





