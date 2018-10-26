//hw4.cpp

#include <iostream>
#include <cstring>

using namespace std;

// Please provide the matrix class 
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

	void tranpose(void) {
		int tmp, i, j;
		if(this->size == 0) return;
		for(i = 0; i < this->size; i++) {
			for(j = 0; j < i; j++) {
				if(i != j) {
					tmp = this->matrix_local[i][j];
					this->matrix_local[i][j] = this->matrix_local[j][i];
					this->matrix_local[j][i] = tmp;
				}
			}
		}
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
	cout << "Please input the size of the square matrix." << endl;
	cin >> size;

	// create the matrix object
	matrix* m = new matrix(size);

	// assign the values to the created matrix
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			if(i == j) {
				m->setElement(i, j, 10);	
			} else {
				m->setElement(i, j, 1);	
			}
		}
	}

	// show the matrix on the screen
	cout << "m = " << endl;
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			cout << m->getElement(i, j) << " ";
		}
		cout << endl;
	}

	//testing standard constructors
	matrix* mArr1 = new matrix[10];	//calling default constructor
	matrix mArr2[5];				//calling default constructor
	matrix m1;						//calling default constructor
	matrix* m2 = new matrix(*m);	//calling copy constructor
	matrix m3 = matrix(*m);			//calling copy constructor

	m1 = *m;						//calling copy assignment operator
	
	//show the testing matrix objects
	cout << "m1 = " << endl;
	m1.printSelf();
	cout << "*m2 = " << endl;
	m2->printSelf();
	cout << "m3 = " << endl;
	m3.printSelf();


	// delete the dynamic allocated object
	delete m;
	delete [] mArr1;
	delete m2;

	system("pause");
	return 0;
}