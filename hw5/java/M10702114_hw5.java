import java.io.*;
import java.util.Scanner;

class matrix implements Cloneable {

	// add data members
	private int[][] matrix_local;
	private int size;

	public matrix() {
		this.size = 0;
	}

	// add functiom members
	public matrix(int size) {
		int tmp;
		this.size = size;
		matrix_local = new int[size][size];
	}

	//copy constructor
	public matrix(final matrix other) {
		int tmp1, tmp2;
		this.size = other.size;
		this.matrix_local = new int[this.size][this.size];
		for(tmp1 = 0; tmp1 < this.size; tmp1++) {
			for(tmp2 = 0; tmp2 < this.size; tmp2++) {
				this.matrix_local[tmp1][tmp2] =  other.matrix_local[tmp1][tmp2];
			}
		}
	}
	public matrix clone() { 
		return new matrix(this);

	}
	public void setElement(int x, int y, int value) {
		this.matrix_local[x][y] = value;
	}

	public int getElement(int x, int y) {
		return this.matrix_local[x][y];
	}

	public void printSelf(){
		for(int i = 0; i < this.size; i++) {
			for(int j = 0; j < this.size; j++) {
				System.out.print(this.matrix_local[i][j] + " ");
			}
			System.out.println();
		}
	}
}


class M10702114_hw5
{
	public static void main(String[] args)
	{
		// obtain the matrix size from user
		int size;
		System.out.println("Please input the size of the square matrix.");
		Scanner cin = new Scanner(System.in);
		size = cin.nextInt();

		// create the matrix object
		matrix m = new matrix(size);

		// assign the values to the created matrix
		for(int i = 0; i < size; i++) {
			for(int j = 0; j < size; j++) {
				if(i == j) {
					m.setElement(i, j, 10);	
				} else {
					m.setElement(i, j, 1);	
				}
			}
		}

		// show the matrix on the screen
		System.out.println("m = ");
		for(int i = 0; i < size; i++) {
			for(int j = 0; j < size; j++) {
				System.out.print(m.getElement(i, j) + " ");
			}
			System.out.println();
		}

		//testing standard constructors
		matrix[] mArr1 = new matrix[10];	//calling default constructor
		matrix[] mArr2 = new matrix[5];				//calling default constructor
		matrix m1;						//calling default constructor
		matrix m2 = new matrix(m);	//calling copy constructor
		matrix m3 = new matrix(m);			//calling copy constructor

		m1 = m.clone();						//calling copy assignment operator
		
		//show the testing matrix objects
		System.out.println("m1 = ");
		m1.printSelf();
		System.out.println("*m2 = ");
		m2.printSelf();
		System.out.println("m3 = ");
		m3.printSelf();

	}
}