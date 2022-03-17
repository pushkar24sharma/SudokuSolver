#include <iostream>
#include <cmath>
using namespace std;
bool solveSudoku(int mat[][9], int i, int j, int n);
bool canPlace(int mat[][9], int i, int j, int n, int num);
int main()
{
	int mat[9][9] = {5, 3, 0, 0, 7, 0, 0, 0, 0, 6, 0, 0, 1, 9, 5, 0, 0, 0, 0, 9, 8, 0, 0, 0, 0, 6, 0, 8, 0, 0, 0, 6, 0, 0, 0, 3, 4, 0, 0, 8, 0, 3, 0, 0, 1, 7, 0, 0, 0, 2, 0, 0, 0, 6, 0, 6, 0, 0, 0, 0, 2, 8, 0, 0, 0, 0, 4, 1, 9, 0, 0, 5, 0, 0, 0, 0, 8, 0, 0, 7, 9};
	solveSudoku(mat, 0, 0, 9);
	return 0;
}
bool solveSudoku(int mat[][9], int i, int j, int n)
{
	// base case
	if(i==n)
	{
		for(int i = 0; i<n; ++i)
		{
			for(int j = 0; j<n; ++j)
				cout<<mat[i][j]<<" ";
			cout<<endl;
		}
		return true;
	}
	if(j==n) return solveSudoku(mat, i+1, 0, n);
	if(mat[i][j]!=0) return solveSudoku(mat, i, j+1, n);
	// recursive case
	for(int num = 1; num<=n; ++num)
	{
		if(canPlace(mat, i, j, n, num)) 
		{
			mat[i][j] = num;
			bool couldWePlace = solveSudoku(mat, i, j+1, n);
			if(couldWePlace)
				return true;
		}
	}
	// backtrack
	mat[i][j] = 0;
	return false;
}
bool canPlace(int mat[][9], int i, int j, int n, int num)
{
	for(int x = 0; x<n; ++x)
		if(mat[x][j]==num || mat[i][x]==num) return false;
	int rn = sqrt(n), sx = (i/rn)*rn, sy = (j/rn)*rn;
	for(int x = sx; x<sx+rn; ++x)
		for(int y = sy; y<sy+rn; ++y)
			if(mat[x][y]==num) return false;
	return true;
}