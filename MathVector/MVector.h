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

	// avoid returning this objects memory to the outside world as you are effectively loosing control of it then
//	double* getData();

	void setDataElements(double dataValue, int index);

	void displayVector(MVector* vec);

	MVector* addVectors(MVector* vec2);

	double generateMagnitude();//MVector* vec);

	MVector* normaliseVector();//MVector* vec, double magnitude);	// normalise would usually result in a magnitude of 1, but perhaps a moot point as it is the code itself that is more interesting here than the mechanics

	double dotProductUsingCos(double magnitude1, double magnitude2, int angle);

	double dotProductByMultiplying(MVector* vec2);


};

