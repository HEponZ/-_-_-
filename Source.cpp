#include "Matrix.h"
#include "Functions.cpp"
#include "Functions.inl"

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
	cout << "Матрица 2\n" << matrix2;
	
	cout << "Сумма матриц\n" << matrix + matrix2;
	cout << "Разница матриц\n" << matrix - matrix2;
	cout << "Произведение матриц\n" << matrix * matrix2;
	cout << "Частное матриц\n" << matrix / matrix2;

	cout << "Минимальное число во 2 матрице: " << matrix2.Min_matrix() << "\n";
	cout << "Максимальное число во 2 матрице: " << matrix2.Max_matrix() << "\n";

	return 0;
}