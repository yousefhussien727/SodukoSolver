#include <iostream>
#include <cmath>
#define n 9
using namespace std;

bool findZero(int grid[n][n], int &row, int &col)
{
	for (row = 0; row < n; row++)
		for (col = 0; col < n; col++)
			if (grid[row][col] == 0)
				return true;
	return false;
}
bool checkRow(int grid[n][n], int row, int num)
{
	for (int i = 0; i < n; i++)
		if (grid[row][i] == num)
			return false;
	return true;
}
bool checkCol(int grid[n][n], int col, int num)
{
	for (int i = 0; i < n; i++)
		if (grid[i][col] == num)
			return false;
	return true;
}
bool checkBox(int grid[n][n], int row, int col, int num)
{
	int sq = sqrt(n);
	int startRow = row - (row % sq), startCol = col - (col % sq);
	for (int i = 0; i < sq; i++)
		for (int j = 0; j < sq; j++)
			if (grid[startRow + i][startCol + j] == num)
				return false;
	return true;
}

bool solve(int grid[n][n])
{
	int row, col;

	if (!findZero(grid, row, col))
		return true;

	for (int num = 1; num <= n; num++)
	{
		if (checkRow(grid, row, num) && checkCol(grid, col, num) && checkBox(grid, row, col, num))
		{
			grid[row][col] = num;

			if (solve(grid))
				return true;
			
			grid[row][col] = 0;
		}
	}
	return false;
}

void printAns(int grid[n][n])
{
	cout << "\nAnswer : \n\n";

	{ //upper border
		cout << "\t";
	cout << char(201);
	for (int i = 0; i < 9; i++)
		cout << char(205);
	cout << char(203);
	for (int i = 0; i < 9; i++)
		cout << char(205);
	cout << char(203);
	for (int i = 0; i < 9; i++)
		cout << char(205);
	cout << char(187) << endl;
	}
	
	for (int row = 0; row < n; row++)
	{
		cout << "\t";
		cout << char(186);
		for (int col = 0; col < n; col++)
		{
			cout << " " << grid[row][col] << " ";
			if (col == 2 || col == 5 || col == 8)
				cout << char(186);
		}
		cout << endl;
		if (row == 2 || row == 5) //middle borders
		{
			cout << "\t";
			cout << char(204);
			for (int i = 0; i < 9; i++)
				cout << char(205);
			cout << char(206);
			for (int i = 0; i < 9; i++)
				cout << char(205);
			cout << char(206);
			for (int i = 0; i < 9; i++)
				cout << char(205);
			cout << char(185) << endl;
		}
	}

	{ //lower border
		cout << "\t";
		cout << char(200);
		for (int i = 0; i < 9; i++)
			cout << char(205);
		cout << char(202);
		for (int i = 0; i < 9; i++)
			cout << char(205);
		cout << char(202);
		for (int i = 0; i < 9; i++)
			cout << char(205);
		cout << char(188) << endl;
	}
}

int main()
{
	{	for (int i = 0; i < 42; i++)
		cout << char(219);
	cout << endl << char(219) << char(223) << char(220) << char(219) << "  This Program Solves any Sudoku  " << char(219) << char(220) << char(223) << char(219) << "\n";
	for (int i = 0; i < 42; i++)
		cout << char(219);
	}
	int grid[n][n];
	cout << endl << "Enter Your Sudoku Puzzle : " << endl;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> grid[i][j]; 
	
	if (solve(grid))
		printAns(grid);
	else
		cout << endl << " ! NO CORRECT ANSWER !" << endl;

	cout << endl;
	system("pause");
	return 0;
}