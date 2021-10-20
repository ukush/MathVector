#pragma oncex
#include <iostream>


using namespace std;

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
   //double* getData();

	void setDataElements(double dataValue, int index);

	// inline display method
	void displayVector(/*MVector* vec*/)
	{
		cout << "Vector size: " << getSize();
		cout << "\nVector data: ";
		for (int i = 0; i < size; i++)
		{
			//		cout << vec->getData()[i] << ", ";
			cout << data[i] << ", ";	// you don't need to use the get methods within the class and it is usually more efficient (and effective) to directly use the data members
		}
		cout << "\n\n";
	};

	MVector* addVectors(MVector* vec2);

	//overload addVectors method
	MVector* addVectors(int value);

	double generateMagnitude();//MVector* vec);

	MVector* normaliseVector();//MVector* vec, double magnitude);	// normalise would usually result in a magnitude of 1, but perhaps a moot point as it is the code itself that is more interesting here than the mechanics

	static double dotProductUsingCos(double magnitude1, double magnitude2, int angle);

	double dotProductByMultiplying(MVector* vec2);

};