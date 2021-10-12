#pragma once
class MVector
{

private:

	int size; // the size of the vector
	double* data; // a pointer to the data

public:
	
	// Constructor
	MVector(int size);

	// Destructor
	~MVector();

	int getSize();

	double* getData();

	void setDataElements(double dataValue, int index);

	void displayVector(double* vecArr, int size);

	MVector* addVectors(double* vec1Arr, double* vec2Arr, int size);

	double generateMagnitude(double* vecArr, int size);

	MVector* normaliseVector(double* vecArr, double magnitude, int size);

	double dotProductUsingCos(double magnitude1, double magnitude2, int angle);

	double dotProductByMultiplying(double* vec1Arr, double* vec2Arr, int size);


};

