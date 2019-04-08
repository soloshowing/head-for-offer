#include <iostream>


bool find(int arr[][4], int rows, int cols, int key)
{
	int row = 0, col = cols-1;
	while (row < rows && col >=0) {
		//右上角的数
		int upRight = arr[row][col];
		if (upRight == key)
			return true;
		else if (upRight > key)
			col--;
		else
			row++;
	}
	return false;
}

bool find2(int arr[][4], int rows, int cols, int key)
{
	int row = rows - 1, col = 0;
	while (row >= 0 && col <= cols-1) {
		//左下角的数
		int downLeft = arr[row][col];
		if (downLeft == key)
			return true;
		else if (downLeft < key)
			col++;
		else
			row--;
	}
	return false;
}

int main()
{
	int arr[4][4] = { {1,2,8,9}, {2,4,9,12}, {4,7,10,13}, {6,8,11,15} };
	std::cout << std::boolalpha << find(arr, 4, 4, 7) << std::endl;
	std::cout << std::boolalpha << find(arr, 4, 4, 5) << std::endl;
	std::cout << std::boolalpha << find(arr, 4, 4, 9) << std::endl;
	std::cout << std::boolalpha << find(arr, 4, 4, 16) << std::endl;

	std::cout << std::boolalpha << find2(arr, 4, 4, 7) << std::endl;
	std::cout << std::boolalpha << find2(arr, 4, 4, 5) << std::endl;
	std::cout << std::boolalpha << find2(arr, 4, 4, 9) << std::endl;
	std::cout << std::boolalpha << find2(arr, 4, 4, 16) << std::endl;
	return 0;
}