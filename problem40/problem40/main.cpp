#include <set>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
	{
		vector<int> result;
		int len = input.size();
		if (input.empty() || k <= 0 || len < k)
			return result;

		multiset<int, greater<int>> leastNumbers;
		multiset<int, greater<int>>::iterator iterGreater;

		vector<int>::iterator iter = input.begin();
		for (; iter != input.end(); ++iter)
		{
			if (leastNumbers.size() < k)
				leastNumbers.insert(*iter);
			else
			{
				iterGreater = leastNumbers.begin();
				if (*iter < *(iterGreater))
				{
					leastNumbers.erase(iterGreater);
					leastNumbers.insert(*iter);
				}
			}
		}
		for (const int i : leastNumbers)
			result.push_back(i);
		return result;
	};
};