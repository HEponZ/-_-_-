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

	template<typename T> friend istream& operator>> (istream& my_cin, Matrix<T>& matrix_S);
	template<typename T> friend ostream& operator<< (ostream& my_cout, const Matrix<T>& matrix_S);

	template<typename T> friend const Matrix<T> operator+(const Matrix<T>& matrix1, const Matrix<T>& matrix2);
	template<typename T> friend const Matrix<T> operator-(const Matrix<T>& matrix1, const Matrix<T>& matrix2);
	template<typename T> friend const Matrix<T> operator*(const Matrix<T>& matrix1, const Matrix<T>& matrix2);
	template<typename T> friend const Matrix<T> operator/(const Matrix<T>& matrix1, const Matrix<T>& matrix2);

	T Min_matrix();
	T Max_matrix();

	~Matrix();
};