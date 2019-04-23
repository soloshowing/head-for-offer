#include <vector>
using namespace std;

long getCount(vector<int>& data, vector<int> &copy, long start, long end)
{
	if (start == end)
		return 0;
	long mid = start + ((end - start) >> 1);
	long lCount = getCount(copy, data, start, mid);
	long rCount = getCount(copy, data, mid + 1, end);
	long crossCount = 0; //记录交叉的逆序对数
	long i = mid, j = end, tempIdx = end;

	while (i >= start && j > mid)
	{
		if (data[i] > data[j])
		{
			copy[tempIdx--] = data[i--];
			crossCount += j - start - (mid - start);
		}
		else
		{
			copy[tempIdx--] = data[j--];
		}
	}

	while (i >= start)
		copy[tempIdx--] = data[i--];
	while (j > mid)
		copy[tempIdx--] = data[j--];
	return (lCount + rCount + crossCount) % 1000000007;
}

int InversePairs(vector<int>& data)
{
	if (data.size() == 0)
		return 0;
	else if (data.size() == 1)
		return 1;
	else
	{
		vector<int> copy(data);
		return getCount(data, copy, 0, data.size() - 1);
	}
}