#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > matrix)
	{
		if (matrix.size() == 1)
			return matrix[0];
		vector<int> result;
		int rows = matrix.size() - 1;
		int cols = matrix[0].size() - 1;
		int row = 0;
		int col = 0;
		while (col <= cols && row <= rows)
		{
			cout << "row = " << row << " rows = " << rows << " col = " << col << " cols= " << cols << endl;
			if (col == cols)
			{
				while(row<=rows)
					result.push_back(matrix[row++][col]);
				break;
			}
			else if(row == rows)
			{
				while (col <= cols)
					result.push_back(matrix[row][col++]);
				break;
			}

			for (int i = col; i <= cols - 1; i++)
				result.push_back(matrix[row][i]);
			for (int i = row; i <= rows - 1; i++)
				result.push_back(matrix[i][cols]);
			for (int i = cols; i > col; i--)
				result.push_back(matrix[rows][i]);
			for (int i = rows; i > row; i--)
				result.push_back(matrix[i][col]);

			row++;
			col++;
			rows--;
			cols--;
		}
		return result;
	}
};

int main()
{
	vector<vector<int>> matrix = {
		{1,2,3,4,5},
		{6,7,8,9,10},
		{11,12,13,14,15},
		{16,17,18,19,20},
		{21,22,23,24,25},
	};
	Solution s;
	auto result = s.printMatrix(matrix);

	for (const int i : result)
		cout << i << " ";
	cout << endl;
	return 0;
}