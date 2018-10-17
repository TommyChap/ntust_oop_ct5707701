//hw3.cpp

#include <iostream>

using namespace std;

// add the matrix simple class/structure here
class matrix
{
public:
	//add data members

	//add functiom members
};



void main()
{
	// obtain the matrix size from user
	int size;
	cout<<"Please input the size of the square matrix."<<endl;
	cin>>size;

	// create the matrix object
	matrix m;

	// using init to setup the matrix object
	m.init(size);

	// assign the values to the created matrix
	int count = 1;
	for(int i=0; i<size; i++)
	{
		for(int j=0; j<size; j++)
		{
			m[i][j] = count;	//this will not work. correct it
			count++;
		}
	}

	// show the matrix on the screen
	for(int i=0; i<size; i++)
	{
		for(int j=0; j<size; j++)
			cout<<m[i][j]<<" ";	//this will not work. correct it

		cout<<endl;
	}

	// call transpose() to calculate its transpose
	m.tranpose();

	// show the matrix after transpose on the screen
	for(int i=0; i<size; i++)
	{
		for(int j=0; j<size; j++)
			cout<<m[i][j]<<" ";	//this will not work. correct it

		cout<<endl;
	}

	// call destroy to free the object
	m.destroy();

	system("pause");
}

