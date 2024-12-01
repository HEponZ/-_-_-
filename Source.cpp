#include "Matrix.h"


int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	Matrix<int> matrix;
	Matrix<int> matrix2;
	int row, col;

	cout << "Введите матрицу 1\n";
	cin >> matrix;
	cout << "Матрица 1\n" << matrix;

	matrix2.rand_matrix();
	cout << "Матрица 1\n" << matrix2;
	
	cout << "Сумма матриц\n" << matrix + matrix2;
	cout << "Разница матриц\n" << matrix - matrix2;
	cout << "Произведение матриц\n" << matrix * matrix2;
	cout << "Частное матриц\n" << matrix / matrix2;

	return 0;
}