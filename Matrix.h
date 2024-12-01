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

	void rand_matrix();

	friend istream& operator>> (istream& my_cin, Matrix<T>& matrix_S);
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

	friend const Matrix<T> operator+(const Matrix<T>& matrix1, const Matrix<T>& matrix2);
	friend const Matrix operator-(const Matrix<T>& matrix1, const Matrix<T>& matrix2)
	{
		Matrix<int> matrix_res;

		for (int i{ 0 }; i < matrix1.row; i++)
		{
			for (int j{ 0 }; j < matrix1.col; j++)
			{
				matrix_res.matrix[i][j] = matrix1.matrix[i][j] - matrix2.matrix[i][j];
			}
		}

		return matrix_res;
	}
	friend const Matrix operator*(const Matrix<T>& matrix1, const Matrix<T>& matrix2)
	{
		Matrix<int> matrix_res;

		for (int i{ 0 }; i < matrix1.row; i++)
		{
			for (int j{ 0 }; j < matrix1.col; j++)
			{
				matrix_res.matrix[i][j] = matrix1.matrix[i][j] * matrix2.matrix[i][j];
			}
		}

		return matrix_res;
	}
	friend const Matrix operator/(const Matrix<T>& matrix1, const Matrix<T>& matrix2)
	{
		Matrix<int> matrix_res;

		for (int i{ 0 }; i < matrix1.row; i++)
		{
			for (int j{ 0 }; j < matrix1.col; j++)
			{
				matrix_res.matrix[i][j] = matrix1.matrix[i][j] / matrix2.matrix[i][j];
			}
		}

		return matrix_res;
	}

	T Min_matrix();
	T Max_matrix();

	~Matrix();
};

template<typename T> T Matrix<T>::Min_matrix()
{
	T min = matrix[0][0];

	for (int i{ 0 }; i < row; i++)
	{
		for (int j{ 0 }; j < col; j++)
		{
			if (matrix[i][j] < min)
			{
				min = matrix[i][j];
			}
		}
	}
	return min;
}
template<typename T> T Matrix<T>::Max_matrix()
{
	T max = matrix[0][0];

	for (int i{ 0 }; i < row; i++)
	{
		for (int j{ 0 }; j < col; j++)
		{
			if (matrix[i][j] > max)
			{
				max = matrix[i][j];
			}
		}
	}
	return max;
}

template<typename T> void Matrix<T>::rand_matrix()
{
	for (int i{ 0 }; i < row; i++)
	{
		for (int j{ 0 }; j < col; j++)
		{
			matrix[i][j] = rand() % 9 + 1;
		}
	}
}

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

template<typename T> Matrix<T>::~Matrix()
{
	for (int i{ 0 }; i < row; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

template<typename T> 
istream& operator>>(istream& my_cin, Matrix<T>& matrix_S)
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

//template<typename T>
//const Matrix<T> operator+(const Matrix<T>& matrix1, const Matrix<T>& matrix2)
//{
//	Matrix<int> matrix_res;
//
//	for (int i{ 0 }; i < matrix1.row; i++)
//	{
//		for (int j{ 0 }; j < matrix1.col; j++)
//		{
//			matrix_res.matrix[i][j] = matrix1.matrix[i][j] + matrix2.matrix[i][j];
//		}
//	}
//
//	return matrix_res;
//}
