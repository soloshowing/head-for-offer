#include <iostream>
using namespace std;

bool increment(char* number);
void printNumber(char* number);
void printOneToMax(int n)
{
	if (n <= 0)
		return;
	char* number = new char[n + 1];
	memset(number, '0', n);
	number[n] = '\0';
	while (increment(number))
	{
		printNumber(number);
	}
	delete[] number;
	return;
}

bool increment(char* number)
{
	bool inc = true;
	int takeOver = 0;
	const int len = strlen(number);

	for (int i = len - 1; i >= 0; i--)
	{
		int sum = number[i] - '0' + takeOver;
		if (i == len - 1)
			sum++;

		if (sum == 10)
		{
			if (i == 0)
				inc = false;
			else
			{
				takeOver = 1;
				number[i] = '0';
			}
		}
		else
		{
			number[i] = '0' + sum;
			break;
		}
	}
	return inc;
}

void printNumber(char* number)
{
	char* s = number;
	while (*s == '0')
		s++;
	if (*s == '\0')
		cout << '0' << endl;
	else
		cout << s << endl;
}


//使用递归全排列
void perm(char* numbers, int index, int len);
void printNumberPerm(int n)
{
	char* numbers = new char[n + 1];
	numbers[n] = '\0';
	for (int i = 0; i < 10; i++)
	{
		numbers[0] = i + '0';
		perm(numbers, 0, n);
	}
	delete[] numbers;
	return;
}

void perm(char* numbers, int index, int len)
{
	if (index == len - 1)
		printNumber(numbers);
	else
	{
		for (int i = 0; i < 10; i++)
		{
			numbers[index + 1] = i + '0';
			perm(numbers, index + 1, len);
		}
	}
}
int main() {
	//printOneToMax(2);
	//printOneToMax(3);
	printNumberPerm(3);
	//printNumberPerm(4);
	return 0;
}