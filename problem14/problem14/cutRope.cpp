#include <iostream>
using namespace std;

int cutRopeDP(int len)
{
	if (len < 2)
		return 0;
	if (len == 2)
		return 1;
	if (len == 3)
		return 2;

	int* products = new int[len + 1];
	products[0] = 0;
	products[1] = 1;
	products[2] = 2;
	products[3] = 3;

	int max;
	for (int i = 4; i <= len; i++)
	{
		max = 0;
		for (int j = 1; j <= i / 2; ++j)
		{
			int product = products[j] * products[i - j];
			if (max < product)
				max = product;
			products[i] = max;
		}
	}
	max = products[len];
	delete[] products;
	return max;
}

int main()
{
	cout << cutRopeDP(8) << endl;
	return 0;
}