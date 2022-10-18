#include <iostream>
#include "mysparsematrix.h"


#pragma region SPARSE MATRIX FUNCTIONS

MySparseMatrix* initSparseMatrix(int row, int column) {
	MySparseMatrix* sparse = new MySparseMatrix();
	sparse->row = row;
	sparse->col = column;

	std::vector<std::vector<Data*>> vect(row, std::vector<Data*>(column, 0));
	sparse->arr = vect;

	Data* data = new Data(); data->key = 0; data->value = new char[2]{ '0' };
	for (int i = 0; i < sparse->row; i++)
		for (int j = 0; j < sparse->col; j++)
			sparse->arr[i][j] = data;

	return sparse;
}

Data* getSparseMatrix(MySparseMatrix* matrix, int row, int column) {
	return matrix->arr[row][column];
}

int insertSparseMatrix(MySparseMatrix* matrix, int row, int column, Data* data) {
	matrix->arr[row][column] = data;
	return 0;
}

int deleteSparseMatrix(MySparseMatrix* matrix, int row, int column) {
	Data* data = new Data(); data->key = 0; data->value = new char[2]{ '0' };
	matrix->arr[row][column] = data;
	return 0;
}

int copySparseMatrix(MySparseMatrix* source, MySparseMatrix* destination) {
	for (int i = 0; i < source->row; i++)
		for (int j = 0; j < source->col; j++)
			if (source->arr[i][j] != 0)
				destination->arr[i][j] = source->arr[i][j];
	return 0;
}

int deleteSparseMatrix(MySparseMatrix* matrix) {
	Data* data = new Data(); data->key = 0; data->value = new char[2]{ '0' };
	for (int i = 0; i < matrix->row; i++)
		for (int j = 0; j < matrix->col; j++)
			matrix->arr[i][j] = data;
	return 0;
}

void printMatrixToConsole(MySparseMatrix* matrix) {
	for (int i = 0; i < matrix->row; i++) {
		if (i != 0) std::cout << std::endl;
		for (int j = 0; j < matrix->col; j++) {
			if (matrix->arr[i][j] != 0)
				std::cout << matrix->arr[i][j] << " ";
			else std::cout << 0 << " ";
		}
	}
}
#pragma endregion