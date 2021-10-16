#include "MVector.h"
#include <iostream>

using namespace std;

struct AllocationMetrics
{
	uint32_t TotalAllocated = 0;
	uint32_t TotalFreed = 0;

	uint32_t CurrentUsage() { return TotalAllocated - TotalFreed;  }

};

static AllocationMetrics s_AllocationMetrics;

void* operator new (size_t size)
{
	cout << "Allocating " << size << " bytes for MVector Object\n";
	s_AllocationMetrics.TotalAllocated += size;

	return malloc(size);
}

void operator delete(void* memory, size_t size)
{
	cout << "Freeing " << size << " bytes for MVector Object\n";
	s_AllocationMetrics.TotalFreed += size;

	free(memory);
}

static void PrintMemoryUsage()
{
	cout << "Cuurent Memory Usage: " << s_AllocationMetrics.CurrentUsage() << " bytes\n";
}

int main()
{
	//---------------------Detect Memory Leaks--------------------------------//

	#ifdef _DEBUG
		//_CrtSetBreakAlloc(200);
		_onexit(_CrtDumpMemoryLeaks);
	#endif

	


	// create pointers for the newly created vector objects 
	MVector* vec1 = new MVector(10);
	MVector* vec2 = new MVector(10);
	
	PrintMemoryUsage();

	cout << "Setting vector elements...\n";

	// Set the elements of the data array to 1,2,3....10
	for (int i = 0; i < vec1->getSize(); i++)
	{
		vec1->setDataElements(i, i);
	}

	// print out vector 
	vec1->displayVector(vec1);

	// set values for vec2 data
	for (int i = 0; i < vec2->getSize(); i++)
	{
		// Allow user to set the values for the vector themselves
		cout << "Enter value #" << (i + 1) << " to set the vector element: ";
		int val;
		cin >> val;
		vec2->setDataElements(val, i); // set values
	}

	// Display values of new vector
	vec2->displayVector(vec2);

	// Add vec1 and vec2 and return a new vector called vec3
	cout << "Adding vectors...\n";
	MVector* vec3 = vec1->addVectors(vec2);

	PrintMemoryUsage();

	//print out vec3
	vec3->displayVector(vec3);

	// get rid of dangling vec3 pointer
	delete vec3;

	PrintMemoryUsage();

	// generate magnitude
	cout << "Calculating Magnitude...\n";
	double magnitude = vec2->generateMagnitude(vec2);

	//print magnitude
	cout << "Vector Magnitude: " << magnitude << "\n\n";

	// Normalise vec2 
	cout << "Normalising vector...\n";
	MVector* normalisedVector = vec2->normaliseVector(vec2, magnitude);

	PrintMemoryUsage();

	// print out normalised vector elements
	normalisedVector->displayVector(normalisedVector);

	// delete dangling pointer
	delete normalisedVector;

	PrintMemoryUsage();

	// calculate dot product (multiplication) of two vectors (vec1 and 2)
	// First calculate the two magnitudes
	// magnitude for vec2 has already been calculated
	double mag1 = vec1->generateMagnitude(vec1);
	double mag2 = magnitude;

	cout << "Calculating the dot product using the cosign method...\n";
	double dotProduct = vec1->dotProductUsingCos(mag1, mag2, 0);
	cout << "The dot product (scalar) of vector 1 and vector 2 is: " << dotProduct << "\n\n";

	cout << "Calculating the dot product using the multiplication method...\n";
	double dotProd = vec1->dotProductByMultiplying(vec2);
	cout << "The dot product (scalar) of vector 1 and vector 2 is: " << dotProd << "\n";

	// delete dangling pointers
	delete vec1;
	
	PrintMemoryUsage();

	delete vec2;

	PrintMemoryUsage();



	return 0;
}