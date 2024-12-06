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

	cout << "������� ������� 1\n";
	cin >> matrix;
	cout << "������� 1\n" << matrix;

	matrix2.rand_matrix();
	cout << "������� 2\n" << matrix2;
	
	cout << "����� ������\n" << matrix + matrix2;
	cout << "������� ������\n" << matrix - matrix2;
	cout << "������������ ������\n" << matrix * matrix2;
	cout << "������� ������\n" << matrix / matrix2;

	cout << "����������� ����� �� 2 �������: " << matrix2.Min_matrix() << "\n";
	cout << "������������ ����� �� 2 �������: " << matrix2.Max_matrix() << "\n";

	return 0;
}