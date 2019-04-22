#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int> > FindContinuousSequence(int sum) {
		vector<vector<int>> result;
		if (sum <= 1)
			return result;
		int lower = 1, upper = 2;
		while (upper > lower)
		{
			int cur = (lower + upper) * (upper - lower + 1) / 2;
			if (cur == sum)
			{
				vector<int> curRes;
				for (int i = lower; i <= upper; i++)
					curRes.push_back(i);
				result.push_back(curRes);
				lower++;
			}
			else if (cur < sum)
				upper++;
			else
				lower++;
		}
		return result;
	}
};