#include <iostream>
using std::cout;
using std::endl;

void insertArray(int* a, int* b, int aLen, int bLen)
{
	int* p = a + aLen - 1;
	int* q = b + bLen - 1;
	int* k = p + bLen;
	while (p >= a && q >= b)
		*k-- = (*p > *q) ? *p-- : *q--;
	while (p >= a)
		*k-- = *p--;
	while (q >= b)
		*k-- = *q--;
}

int main()
{
	int arr1[18] = { 0, 1,2, 3, 3, 4, 5, 7, 8 };
	int arr2[9] = {0, 1, 1, 2, 3, 6, 6, 8, 9 };
	insertArray(arr1, arr2, 9, 9);
	for (auto i : arr1)
		cout << i << " ";
	cout << endl;
}