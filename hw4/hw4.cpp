//hw4.cpp

#include <iostream>

using namespace std;

// Please provide the matrix class 







void main()
{
	// obtain the matrix size from user
	int size;
	cout<<"Please input the size of the square matrix."<<endl;
	cin>>size;

	// create the matrix object
	matrix* m = new matrix(size);

	// assign the values to the created matrix
	for(int i=0; i<size; i++)
		for(int j=0; j<size; j++)
		{
			if(i==j)
				m->setElement(i,j,10);	
			else
				m->setElement(i,j,1);	
		}

	// show the matrix on the screen
	cout<<"m = "<<endl;
	for(int i=0; i<size; i++)
	{
		for(int j=0; j<size; j++)
			cout<<m->getElement(i,j)<<" ";

		cout<<endl;
	}


	//testing standard constructors
	matrix* mArr1 = new matrix[10];	//calling default constructor
	matrix mArr2[5];				//calling default constructor
	matrix m1;						//calling default constructor
	matrix* m2 = new matrix(*m);	//calling copy constructor
	matrix m3 = matrix(*m);			//calling copy constructor

	m1 = *m;						//calling copy assignment operator
	
	
	//show the testing matrix objects
	cout<<"m1 = "<<endl;
	m1.printSelf();
	cout<<"*m2 = "<<endl;
	m2->printSelf();
	cout<<"m3 = "<<endl;
	m3.printSelf();


	// delete the dynamic allocated object
	delete m;
	delete [] mArr1;
	delete m2;
}

