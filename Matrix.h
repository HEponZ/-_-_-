#pragma once
#include <iostream>

using namespace std;

template <class T> class Matrix
{              
private:    
	T** matrix;
	int row = 3;
	int col = 2;    
public:
	Matrix() : Matrix(nullptr) {};
	Matrix(const T** matrix_S);

	T** get_matrix() { return matrix; }

	void set_matrix(const T** matrix_S);

	void rand_matrix()
	{
		for (int i{ 0 }; i < row; i++)
		{
			for (int j{ 0 }; j < col; j++)
			{
				matrix[i][j] = rand() % 10;
			}
		}
	}

	friend istream& operator>> (istream& my_cin, Matrix<T>& matrix_S)
	{
		for (int i{ 0 }; i < matrix_S.row; i++)
		{
			for (int j{ 0 }; j < matrix_S.col; j++)
			{
				my_cin >> matrix_S.matrix[i][j];
			}
		}

		return my_cin;
	}

	friend ostream& operator<< (ostream& my_cout, const Matrix<T>& matrix_S)
	{
		for (int i{ 0 }; i < matrix_S.row; i++)
		{
			for (int j{ 0 }; j < matrix_S.col; j++)
			{
				my_cout << matrix_S.matrix[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "\n";

		return my_cout;
	}

	~Matrix()
	{
		for (int i{ 0 }; i < row; i++)
		{
			delete[] matrix[i];
		}
		delete[] matrix;
	}
};

template<typename T> Matrix<T>::Matrix(const T** matrix_S) : matrix{ new T * [row] }
{
	matrix = new T * [row];

	for (int i = 0; i < row; i++)
	{
		matrix[i] = new T[col];
	}

	if (matrix_S)
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				matrix[i][j] = matrix_S[i][j];
			}
		}
	}
}

template<typename T> void Matrix<T>::set_matrix(const T** matrix_S)
{
	if (matrix)
	{
		for (int i{ 0 }; i < row; i++)
		{
			delete[] matrix[i];
		}
		delete[] matrix;
	}

	matrix = new T * [row];

	for (int i{ 0 }; i < row; i++)
	{
		matrix[i] = new T[col];
	}

	for (int i{ 0 }; i < row; i++)
	{
		for (int j{ 0 }; j < col; j++)
		{
			matrix[i][j] = matrix_S[i][j];
		}
	}
}