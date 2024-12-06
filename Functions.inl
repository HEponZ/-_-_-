#include "Matrix.h"

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

// Конструктор
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
// Деструктор
template<typename T> Matrix<T>::~Matrix()
{
	for (int i{ 0 }; i < row; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
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