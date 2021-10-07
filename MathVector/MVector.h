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

	// Accessor methods
	int getSize();
	double* getData();

	//mutator method
	void setSize(int theSize);

	// Set elements of the data variable
	void setDataElements(double dataValue, int index);

	// Display vector to the screen
	void displayVector(double* dataptr, int size);

	// Method to add two vectors together
	MVector* addVectors(MVector* vec1, MVector* vec2);


};

