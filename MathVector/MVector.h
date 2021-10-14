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

	void displayVector(MVector* vec);

	MVector* addVectors(MVector* vec2);

	double generateMagnitude(MVector* vec);

	MVector* normaliseVector(MVector* vec, double magnitude);

	double dotProductUsingCos(double magnitude1, double magnitude2, int angle);

	double dotProductByMultiplying(MVector* vec2);


};

