#include <iostream>

using namespace std;

int main()
{
	main:
	int row,col;
	cout << "Enter the row of matrix: ";
	cin >> row;

	cout << "Enter the column of matrix: ";
	cin >> col;
	
	if (row != col)
	{
		cout << "---- Warning ----" << endl;
		cout << "row and colum must be equal.\nif you want to exit press 0 othervise press any number:";
		int command;
		cin >> command;
		if (command == 0)
		{
			return 0;
		}
		goto main;
	}

	int matrix[row][col];

	for (int i=0; i < row; i++)
	{
		cout << "Row: " << i+1 << endl;

		for (int j=0; j < col; j++)
		{
			cout << "Matrix[" << i+1 << "]" << "[" << j+1 << "] : ";
			cin >> matrix[i][j];
		}
	}

	int n_matrix[col][row];

	for (int i=0; i < col; i++)
	{
		for (int j=0; j < row; j++)
		{
			n_matrix[i][j] = matrix[j][i];
		}
	}

	bool n_equal = false;

	for (int i=0; i < row; i++)
	{
		for (int j=0; j < col; j++)
		{
			if (matrix[i][j] != n_matrix[i][j])
			{
				n_equal = true;
			}
		}
	}

	if (n_equal == true)
	{
		cout << "Matrix is not symmetric. \nrun the operation: Matrix+Marix" << endl;
		
		int add_matrix[row][col];
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				add_matrix[i][j] = matrix[i][j] + matrix[i][j];
			}
		}

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				cout << add_matrix[i][j] << "\t";
			}
			cout << endl;
		}
	} else {
		int m_matrix[row][col];

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

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				cout << m_matrix[i][j] << "\t";
			}
			cout << endl;
		}
		cout << endl;
	}
	
	return 0;
}
