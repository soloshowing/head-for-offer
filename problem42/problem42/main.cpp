#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		int maxSum = INT32_MIN;
		int curSum = 0;

		for (int i = 0; i < array.size(); i++)
		{
			if (curSum <= 0)
				curSum = array[i];
			else
				curSum += array[i];

			if (curSum > maxSum)
				maxSum = curSum;
		}
		return maxSum;
	}

	//dynamic processing
	int FindGreatestSumOfSubArrayDP(vector<int> array) {
		int maxSum = array[0];
		int curSum = array[0];
		for (int i = 1; i < array.size(); i++)
		{
			curSum = max(curSum + array[i], array[i]);
			maxSum = max(curSum, maxSum);
		}
		return maxSum;
	}
};