#include <iostream>
using namespace std;
//旋转数组中的最小数字
int findMin(int* arr, int left, int right)
{
	while (left != right-1)
	{	
		int mid = (right + left) / 2;
		if (arr[mid] >= arr[left])
			left = mid;
		else
			right = mid;
	}
	return arr[right];
}


int main()
{
	int array1[] = { 3,4,5,1,2 };
	int array2[] = { 3,4,5,5,6,1,2,3 };
	int array3[] = { 2,3,4,5,5,6,1,2 };
	cout << findMin(array1, 0, 4) << endl;
	cout << findMin(array2, 0, 7) << endl;
	cout << findMin(array3, 0, 7) << endl;
	cout << findMin(array4, 0, 4) << endl;
}