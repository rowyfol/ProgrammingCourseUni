#include <iostream>

#define MAX_ARRAY_SIZE_COL 100

using namespace std;

void WelcomeBanner();
void FillUpTheMatrix(int matrix[][MAX_ARRAY_SIZE_COL], int row, int col);
void CreateTransposeOfMatrix(int matrix[][MAX_ARRAY_SIZE_COL], int n_matrix[][MAX_ARRAY_SIZE_COL], int row, int col);
bool CheckSymmetricStatus(int matrix[][MAX_ARRAY_SIZE_COL], int n_matrix[][MAX_ARRAY_SIZE_COL], int row, int col);
void AddM(int matrix[][MAX_ARRAY_SIZE_COL], int n_matrix[][MAX_ARRAY_SIZE_COL], int result[][MAX_ARRAY_SIZE_COL], int row, int col);
void MultiplyM(int matrix[][MAX_ARRAY_SIZE_COL], int n_matrix[][MAX_ARRAY_SIZE_COL], int result[][MAX_ARRAY_SIZE_COL], int row, int col);
void PrintMatrix(int matrix[][MAX_ARRAY_SIZE_COL], int row, int col);

int main()
{
	bool ProcessToNextStep = false;
	int row,col;
	do {
		WelcomeBanner();
		cout << "----> Enter the row of matrix: ";
		cin >> row;

		cout << "----> Enter the column of matrix: ";
		cin >> col;
	
		if (row != col)
		{
			cout << endl << "!!!! Warning !!!!" << endl;
			cout << "(INFO) row and colum must be equal.\n----> if you want to exit press 0 othervise press any number:";
			int command;
			cin >> command;
			if (command == 0)
			{
				return 0;
			}
		} else {
			ProcessToNextStep = true;
		}
	} while (ProcessToNextStep == false);

	int matrix[row][MAX_ARRAY_SIZE_COL];
	FillUpTheMatrix(matrix, row, col);

	int n_matrix[col][MAX_ARRAY_SIZE_COL];
	CreateTransposeOfMatrix(matrix, n_matrix, row, col);
	PrintMatrix(matrix, row, col);
	cout << endl;
	PrintMatrix(n_matrix, row, col);
	cout << endl;

	if (CheckSymmetricStatus(matrix, n_matrix, row, col) == false)
	{
		cout << "Matrix is not symmetric. \nrun the operation: Matrix+Marix" << endl;
		
		int add_matrix[row][MAX_ARRAY_SIZE_COL];
		AddM(matrix, matrix, add_matrix, row, col);
		PrintMatrix(add_matrix, row, col);
		cout << endl;

	} else {
		int m_matrix[row][MAX_ARRAY_SIZE_COL];

		for (int i = 0; i < row; i++)
		{
			int result = 0;
			int col_new;
			for (int j = 0; j < col; j++)
			{
				result = result + (matrix[i][j] * matrix[j][i]);
				if (j < col)
				{
					m_matrix[i][j] = result;
				}
			}
		}

		PrintMatrix(m_matrix, row, col);

	}
	
	return 0;
}

void WelcomeBanner()
{
	cout << R"(

╔╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╗
╠╬╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╬╣
╠╣Matrix Calculator╠╣
╠╣Written By       ╠╣
╠╣A.N              ╠╣
╠╬╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╬╣
╚╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╝

	)" << endl;
}


void FillUpTheMatrix(int matrix[][MAX_ARRAY_SIZE_COL], int row, int col)
{
	for (int i=0; i < row; i++)
	{
		cout << "Row: " << i+1 << endl;

		for (int j=0; j < col; j++)
		{
			cout << "Matrix[" << i+1 << "]" << "[" << j+1 << "] : ";
			cin >> matrix[i][j];
		}
	}
}

void CreateTransposeOfMatrix(int matrix[][MAX_ARRAY_SIZE_COL], int n_matrix[][MAX_ARRAY_SIZE_COL], int row, int col)
{
	for (int i=0; i < col; i++)
	{
		for (int j=0; j < row; j++)
		{
			n_matrix[i][j] = matrix[j][i];
		}
	}
}

bool CheckSymmetricStatus(int matrix[][MAX_ARRAY_SIZE_COL], int n_matrix[][MAX_ARRAY_SIZE_COL], int row, int col)
{
	bool equal = true;

	for (int i=0; i < row; i++)
	{
		for (int j=0; j < col; j++)
		{
			if (matrix[i][j] != n_matrix[i][j])
			{
				equal = false;
			}
		}
	}

	return equal;
}

void AddM(int matrix[][MAX_ARRAY_SIZE_COL], int n_matrix[][MAX_ARRAY_SIZE_COL], int result[][MAX_ARRAY_SIZE_COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			result[i][j] = matrix[i][j] + n_matrix[i][j];
		}
	}
}

void MultiplyM(int matrix[][MAX_ARRAY_SIZE_COL], int n_matrix[][MAX_ARRAY_SIZE_COL], int result[][MAX_ARRAY_SIZE_COL], int row, int col)
{
	cout << endl;
}

void PrintMatrix(int matrix[][MAX_ARRAY_SIZE_COL], int row, int col)
{

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
}
