#include <vector>
using namespace std;

class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		int count = 0, stage;
		for (const int i : numbers)
		{
			if (count == 0)
			{
				count = 1;
				stage = i;
			}
			else if (stage == i)
			{
				count++;
			}
			else
			{
				count--;
			}
		}
		count = 0;
		for (const int i : numbers) {
			if (i == stage)
				count++;
		}
		return (count > numbers.size() / 2) ? stage : 0;
	}
};