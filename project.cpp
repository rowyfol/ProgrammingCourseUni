#include <iostream>


/* use this maximum size for matrix colum to avoid compiler errors. instead of this metod 
I could use std::array but in this programm i perfer to use more basic cpp style (old school style :) )
*/
#define MAX_ARRAY_SIZE_COL 100

using namespace std;

void WelcomeBanner();
void FillUpTheMatrix(int matrix[][MAX_ARRAY_SIZE_COL], int row, int col);
void CreateTransposeOfMatrix(int matrix[][MAX_ARRAY_SIZE_COL], int n_matrix[][MAX_ARRAY_SIZE_COL], int row, int col);
bool CheckSymmetricStatus(int matrix[][MAX_ARRAY_SIZE_COL], int n_matrix[][MAX_ARRAY_SIZE_COL], int row, int col);
void AddM(int matrix[][MAX_ARRAY_SIZE_COL], int n_matrix[][MAX_ARRAY_SIZE_COL], int result[][MAX_ARRAY_SIZE_COL], int row, int col);
void MultiplyM(int matrix[][MAX_ARRAY_SIZE_COL], int n_matrix[][MAX_ARRAY_SIZE_COL], int result[][MAX_ARRAY_SIZE_COL], int row, int col);
void PrintMatrix(int matrix[][MAX_ARRAY_SIZE_COL], int row, int col);

/*
Logic that I follow on my main function:
1. get the matrix
2. create transpose of the matrix
3. check if matrix and transpose is equal or not
	if yes --> multiply it by itself
	if no  --> add it by itself
*/

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


	if (CheckSymmetricStatus(matrix, n_matrix, row, col) == false)
	{
		cout << "!!! Matrix is not symmetric !!! \n----> run the operation: Add matrix to itself" << endl;
		
		int add_matrix[row][MAX_ARRAY_SIZE_COL];
		AddM(matrix, matrix, add_matrix, row, col);

		cout << "Final result (add): " << endl;

		PrintMatrix(add_matrix, row, col);
		cout << endl;

	} else {

		int result[row][MAX_ARRAY_SIZE_COL];
		MultiplyM(matrix, matrix, result, row, col);

		cout << "Final result(multipy): " << endl;

		PrintMatrix(result, row, col);

	}

	char pause;
	cout << "\nPress any key to exit the programm... ";
	cin >> pause;
	
	return 0;
}

void WelcomeBanner()
{
	// INFO: Banner created with this application you can check it out here! ( https://www.asciiart.eu/ascii-draw-studio/app )

	cout << "\n╔╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╗\n╠╬╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╬╣\n╠╣Matrix Calculator╠╣\n╠╣Written By       ╠╣\n╠╣A.N              ╠╣\n╠╬╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╬╣\n╚╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╝\n" << endl;
}


void FillUpTheMatrix(int matrix[][MAX_ARRAY_SIZE_COL], int row, int col)
{
	for (int i=0; i < row; i++)
	{
		cout << "Row: " << i+1 << endl;

		for (int j=0; j < col; j++)
		{
			cout << "Matrix[" << i << "]" << "[" << j << "] : ";
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
	for (int i =0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			result[i][j] = 0;
			for (int k = 0; k < col; k++)
			{
				result[i][j] += matrix[i][k] * n_matrix[k][j];
			}
		}
	}
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
