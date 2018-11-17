//hw6.cpp

#include <iostream>
#include <assert.h>

using namespace std;

class matrix {
private:
	// add data members
	int **matrix_local;
	int size;

public:
	matrix(void) {
		this->size = 0;
	}

	// add functiom members
	matrix(int size) {
		int tmp;
		this->size = size;
		matrix_local = new int*[size];
		for(tmp = 0; tmp < size; tmp++) {
			matrix_local[tmp] = new int[size]; 
		}
	}

	//copy constructor
	matrix(const matrix &other) {
		int tmp;
		this->size = other.size;
		this->matrix_local = new int*[this->size];
		for(tmp = 0; tmp < this->size; tmp++) {
			this->matrix_local[tmp] = new int[this->size];
			memcpy(this->matrix_local[tmp], other.matrix_local[tmp], this->size * sizeof(int));
		}
	}

	//copy assignment operator
	matrix &operator=(const matrix &other) {
		int tmp;
		if(this != &other) {
			if(this->size > 0) {
				for(tmp = 0; tmp < this->size; tmp++) {
					delete[] this->matrix_local[tmp]; 
				}
				delete[] this->matrix_local;
			}
			this->size = other.size;
			this->matrix_local = new int*[this->size];
			for(tmp = 0; tmp < this->size; tmp++) {
				this->matrix_local[tmp] = new int[this->size]; 
				memcpy(this->matrix_local[tmp], other.matrix_local[tmp], this->size * sizeof(int));
			}
		}
		return *this;
	}

	~matrix(void) {
		int tmp;
		if(this->size > 0) {
			for(tmp = 0; tmp < this->size; tmp++) {
				delete[] this->matrix_local[tmp]; 
			}
			delete[] this->matrix_local;
		}
		this->size = 0;
	}

	void setElement(int x, int y, int value) {
		this->matrix_local[x][y] = value;
	}

	int getElement(int x, int y) {
		return this->matrix_local[x][y];
	}

	void printSelf(void){
		for(int i = 0; i < this->size; i++) {
			for(int j = 0; j < this->size; j++) {
				cout << this->matrix_local[i][j] << " ";
			}
			cout << endl;
		}
	}
};

class vector {
	private:
	// add data members
	int *vector_local;
	int size;

public:
	vector(void) {
		this->size = 0;
	}

	// add functiom members
	vector(int size) {
		int tmp;
		this->size = size;
		vector_local = new int[size];
	}

	//copy constructor
	vector(const matrix &other) {
		int tmp;
		this->size = other.size;
		this->matrix_local = new int*[this->size];
		for(tmp = 0; tmp < this->size; tmp++) {
			this->matrix_local[tmp] = new int[this->size];
			memcpy(this->matrix_local[tmp], other.matrix_local[tmp], this->size * sizeof(int));
		}
	}

	//copy assignment operator
	vector &operator=(const vector &other) {
		int tmp;
		if(this != &other) {
			if(this->size > 0) {
				for(tmp = 0; tmp < this->size; tmp++) {
					delete[] this->matrix_local[tmp]; 
				}
				delete[] this->matrix_local;
			}
			this->size = other.size;
			this->matrix_local = new int*[this->size];
			for(tmp = 0; tmp < this->size; tmp++) {
				this->matrix_local[tmp] = new int[this->size]; 
				memcpy(this->matrix_local[tmp], other.matrix_local[tmp], this->size * sizeof(int));
			}
		}
		return *this;
	}

	~vector(void) {
		int tmp;
		if(this->size > 0) {
			for(tmp = 0; tmp < this->size; tmp++) {
				delete[] this->matrix_local[tmp]; 
			}
			delete[] this->matrix_local;
		}
		this->size = 0;
	}

	void setElement(int x, int y, int value) {
		this->matrix_local[x][y] = value;
	}

	int getElement(int x, int y) {
		return this->matrix_local[x][y];
	}

	void printSelf(void){
		for(int i = 0; i < this->size; i++) {
			for(int j = 0; j < this->size; j++) {
				cout << this->matrix_local[i][j] << " ";
			}
			cout << endl;
		}
	}
};

int main() {
	// obtain the matrix size from user
	int size;
	cout << "Please input the size of the matrix and vector." << endl;
	cin >> size;

	// create the matrix and vector object
	matrix* m = new matrix(size);
	vector* v = new vector(size);

	// assign the values to the created matrix and vector
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			if(i == j) {
				m->setElement(i, j, 10);
			} else {
				m->setElement(i, j, 1);
			}
		}
	}

	for(int i = 0; i < size; i++) {
		v->setElement(i, i + 1);
	}

	//show the matrix and vector on the screen
	cout << "m = " << endl;
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			cout << m->getElement(i, j) << " ";
		}
		cout << endl;
	}

	cout << "v = " << endl;
	for(int i = 0; i < size; i++) {
		cout<<v->getElement(i)<<" ";
	}
	cout << endl;

	//test the standard constructors
	matrix* mArr1 = new matrix[10];	//calling default constructor
	matrix mArr2[5];				//calling default constructor
	matrix m1;						//calling default constructor
	matrix* m2 = new matrix(*m);	//calling copy constructor
	matrix m3 = matrix(*m);			//calling copy constructor
	m1 = *m;						//calling copy assignment operator
	vector* vArr1 = new vector[10];	//calling default constructor
	vector vArr2[5];				//calling default constructor
	vector v1;						//calling default constructor
	vector* v2 = new vector(*v);	//calling copy constructor
	vector v3 = vector(*v);			//calling copy constructor
	v1 = *v;						//calling copy assignment operator

	
	//test MmultV and VmultM
	vector& ans1 = MmultV(*m, *v);
	cout << "ans1=" << endl;
	ans1.printSelf();

	vector ans2 = VmultM(*v, *m);
	cout << "ans2=" << endl;
	ans2.printSelf();


	//test counting object
	cout << "You have create " << matrix::getCount() << " matrices and " 
		<< vector::getCount() << " vectors in this program." << endl;


	// delete the dynamic allocated object
	delete m;
	delete [] mArr1;
	delete m2;
	delete v;
	delete [] vArr1;
	delete v2;

	//test counting object
	cout << "After deleting, there are " << matrix::getCount() << " matrices and "
		<< vector::getCount() << " vectors in this program." << endl;
}

