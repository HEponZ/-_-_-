#include "Matrix.h"


int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	Matrix<int> matrix;
	Matrix<int> matrix2;
	int row, col;

	cout << "������� ������� 1\n";
	cin >> matrix;
	cout << "������� 1\n";
	cout << matrix;

	matrix2.rand_matrix();
	cout << "������� 1\n";
	cout << matrix2;

	return 0;
}