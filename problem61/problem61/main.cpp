#include <algorithm>
#include <vector>
using namespace std;

bool IsContinuous(vector<int> numbers)
{
	int len = numbers.size();
	if (len != 5)
		return false;
	sort(numbers.begin(), numbers.end());
	int jokers = 0;
	for (int i = 0; i < 5 && numbers[i] == 0; i++)
		jokers++;
	if (jokers > 4)
		return false;

	for (int i = jokers + 1; i < 5; i++)
	{
		if (numbers[i] == numbers[i - 1])
			return false;
	}
	int dis = numbers[4] - numbers[jokers];

	return dis <= 4 ? true : false;
}