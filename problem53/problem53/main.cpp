#include <vector>
using namespace std;

class Solution {
public:
	int GetNumberOfK(vector<int> data, int k) {
		int lower = GetFirstK(data, k);
		int upper = GetLastK(data, k);
		if (lower == -1)
			return 0;
		return upper - lower + 1;
	}

	int GetFirstK(const vector<int>& data, int k)
	{
		int start = 0, end = data.size() - 1;
		while (start <= end)
		{
			int mid = start + ((end - start) >> 1);
			int cur = data[mid];
			if (cur == k)
			{
				if ((mid > 0 && data[mid - 1] != k) || mid == 0)
					return mid;
				else
					end = mid - 1;
			}
			else if (cur > k)
				end = mid - 1;
			else
				start = mid + 1;
		}
		return -1;
	}

	int GetLastK(const vector<int>& data, int k)
	{
		int start = 0, end = data.size() - 1;
		while (start <= end)
		{
			int mid = start + ((end - start) >> 1);
			int cur = data[mid];
			if (cur == k)
			{
				if (mid == data.size() - 1 || (mid < data.size() - 1 && k != data[mid + 1]))
					return mid;
				else
					start = mid + 1;
			}
			else if (cur > k)
				end = mid - 1;
			else
				start = mid + 1;
		}
		return -1;
	}
};