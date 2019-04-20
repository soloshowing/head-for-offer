#include <cmath>
#include <iostream>
using namespace std;

int countOfIntegers(int digits);
int digitAtIndex(int index, int digits);
int beginNumber(int digits);
int digitAtIndex(int index)
{
	if (index < 0)
		return -1;
	int digits = 1;
	while (1) {
		int numbers = countOfIntegers(digits);
		if (index < numbers * digits)
			return digitAtIndex(index, digits);

		index -= digits * numbers;
		digits++;
	}
	return -1;
}

int countOfIntegers(int digits)
{
	if (digits == 1)
		return 10;
	return 9 * std::pow(10, digits - 1);
}

int digitAtIndex(int index, int digits)
{
	int number = beginNumber(digits) + index / digits;
	int indexFromRight = digits - index % digits;
	for (int i = 1; i < indexFromRight; i++)
		number /= 10;
	return number % 10;
}

int beginNumber(int digits)
{
	if (digits == 1)
		return 0;
	return std::pow(10, digits - 1);
}

int main()
{
	cout << digitAtIndex(13) << endl; 
	cout << digitAtIndex(5) << endl;
	cout << digitAtIndex(19) << endl;
	cout << digitAtIndex(1001) << endl;
}