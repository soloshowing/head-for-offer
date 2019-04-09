#include <iostream>
#include <memory>
using namespace std;

class Solution {
public:
	bool hasPath(char* matrix, int rows, int cols, char* str)
	{
		if (!matrix || rows < 1 || cols < 1 || !str)
			return false;
		int pathLen = 0;
		bool* visited = new bool[rows*cols];
		for (int i = 0; i < rows*cols; i++)
			visited[i] = false;

		for (int row = 0; row < rows; row++)
		{
			for (int col = 0; col < cols; col++)
			{
				if (doHasPath(matrix, row, rows, col, cols, str, pathLen, visited))
				{
					delete[] visited;
					return true;
				}
			}
		}
		delete[] visited;
		return false;

	}

	bool doHasPath(char* matrix, int row, int rows, int col, int cols, char* str, int pathLen, bool visited[])
	{
		if (str[pathLen] == '\0')
			return true;

		bool hasPath = false;
		if (row >= 0 && row <= rows && col >= 0 && col <= cols && matrix[row*cols + col] == str[pathLen] && !visited[row*cols + col])
		{
			++pathLen;
			visited[row*cols + col] = true;
			hasPath = doHasPath(matrix, row - 1, rows, col, cols, str, pathLen, visited)
				|| doHasPath(matrix, row + 1, rows, col, cols, str, pathLen, visited)
				|| doHasPath(matrix, row, rows, col - 1, cols, str, pathLen, visited)
				|| doHasPath(matrix, row, rows, col + 1, cols, str, pathLen, visited);

			//»ØËÝ
			if (!hasPath)
			{
				--pathLen;
				visited[row*cols + col] = false;
			}
		}
		return hasPath;
	}
};


int main()
{
	Solution s;
	char matrix[] = "abtgcfcsjdeh";
	char str1[] = "bfce";
	char str2[] = "abfb";
	cout << boolalpha << s.hasPath(matrix, 3, 4, str1) << endl;
	cout << boolalpha << s.hasPath(matrix, 3, 4, str2) << endl;
}