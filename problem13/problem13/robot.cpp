#include <iostream>
using namespace std;
bool canEnter(int threshold, int row, int rows, int col, int cols, bool* visited)
{
	if (row<0 || row>=rows || col<0 || col>=cols)
		return false;

	if (visited[row*cols + col])
		return false;

	int cnt = 0;
	while (row)
	{
		cnt += row % 10;
		row /= 10;
	}
	while (col)
	{
		cnt += col % 10;
		col /= 10;
	}
	return cnt <= threshold;
}

int movingCount(int threshold, int rows, int cols)
{
	if (rows < 1 || cols < 1 || threshold < 0)
		return 0;
	bool* visited = new bool[rows*cols];
	memset(visited, false, rows*cols);
	int	count = moving(threshold, 0, rows, 0, cols, visited);
	delete[] visited;
	return count;
}

int moving(int threshold, int row, int rows, int col, int cols, bool* visited)
{
	int cnt = 0;
	if (canEnter(threshold, row, rows, col, cols, visited))
	{
		cnt++;
		visited[row*cols + col] = true;
		cnt += moving(threshold, row - 1, rows, col, cols, visited)
			+  moving(threshold, row, rows, col - 1, cols, visited)
			+  moving(threshold, row + 1, rows, col, cols, visited)
			+  moving(threshold, row, rows, col + 1, cols, visited);
	}
	return cnt;
}