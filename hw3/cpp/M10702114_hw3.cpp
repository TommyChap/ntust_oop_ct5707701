//hw3.cpp

#include <iostream>

using namespace std;

// add the matrix simple class/structure here
class matrix {
	public:
	matrix()
	{

	}
	// add data members
	int **matrix_local;
	int size;

	// add functiom members
	void init(int size) {
		int tmp;
		this->size = size;
		matrix_local = new int*[size];
		for(tmp = 0; tmp < size; tmp++) {
			matrix_local[tmp] = new int[size]; 
		}
	}

	void destroy(void) {
		int tmp;
		if(this->size == 0) return;
		for(tmp = 0; tmp < this->size; tmp++) {
			delete[] matrix_local[tmp]; 
		}
		delete[] matrix_local;
		this->size = 0;
	}

	void tranpose(void) {
		int tmp, i, j;
		if(this->size == 0) return;
		for(i = 0; i < this->size; i++) {
			for(j = 0; j < i; j++) {
				if(i != j) {
					tmp = matrix_local[i][j];
					matrix_local[i][j] = matrix_local[j][i];
					matrix_local[j][i] = tmp;
				}
			}
		}
	}
};



int main(void) {
	// obtain the matrix size from user
	int size;
	int i, j;
	cout << "Please input the size of the square matrix." << endl;
	cin >> size;

	// create the matrix object
	matrix m;

	// using init to setup the matrix object
	m.init(size);

	// assign the values to the created matrix
	int count = 1;
	for(i = 0; i < size; i++) {
		for(j = 0; j < size; j++) {
			m.matrix_local[i][j] = count;	// this will not work. correct it // 錯誤
			count++;
		}
	}

	// show the matrix on the screen
	cout << "show the matrix on the screen" << endl;
	for(i = 0; i < size; i++) {
		for(j = 0; j < size; j++) {
			cout << m.matrix_local[i][j] << "\t";	// this will not work. correct it	// 錯誤
		}
		cout << endl << endl;
	}

	// call transpose() to calculate its transpose
	m.tranpose();

	// show the matrix after transpose on the screen
	cout << "show the matrix after transpose on the screen" << endl;
	for(i = 0; i < size; i++) {
		for(j = 0; j < size; j++) {
			cout << m.matrix_local[i][j] << "\t";	// this will not work. correct it	// 錯誤
		}
		cout << endl << endl;
	}

	// call destroy to free the object
	m.destroy();

	system("pause");
	return 0;
}