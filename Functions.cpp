#include "Matrix.h"

// ¬вод и вывод
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

template<typename T>
ostream& operator<< (ostream& my_cout, const Matrix<T>& matrix_S)
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


// јрифметические операторы
template<typename T>
const Matrix<T> operator+(const Matrix<T>& matrix1, const Matrix<T>& matrix2)
{
	Matrix<int> matrix_res;

	for (int i{ 0 }; i < matrix1.row; i++)
	{
		for (int j{ 0 }; j < matrix1.col; j++)
		{
			matrix_res.matrix[i][j] = matrix1.matrix[i][j] + matrix2.matrix[i][j];
		}
	}

	return matrix_res;
}

template<typename T>
const Matrix<T> operator-(const Matrix<T>& matrix1, const Matrix<T>& matrix2)
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

template<typename T>
const Matrix<T> operator*(const Matrix<T>& matrix1, const Matrix<T>& matrix2)
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

template<typename T>
const Matrix<T> operator/(const Matrix<T>& matrix1, const Matrix<T>& matrix2)
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