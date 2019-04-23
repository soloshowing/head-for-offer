#include <iostream>
#include <vector>
using namespace std;

int maxDiff(const vector<int> numbers)
{
	int len = numbers.size();
	int min = numbers[0];
	int maxDiff = numbers[1] - min;
	for (int i = 2; i < len; i++)
	{
		if (numbers[i - 1] < min)
			min = numbers[i - 1];
		int curDiff = numbers[i] - min;
		if (curDiff > maxDiff)
			maxDiff = curDiff;
	}
	return maxDiff;
}