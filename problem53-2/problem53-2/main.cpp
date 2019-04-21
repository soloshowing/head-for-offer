#include <vector>
#include <iostream>
using namespace std;

int getMissing(const vector<int>& v)
{
	int start = 0, end = v.size() - 1;
	while (start <= end)
	{
		int mid = start + ((end - start) >> 1);
		if (mid == v[mid])
			start = mid + 1;
		else
		{
			if (mid == 0 || (mid > 0 && mid - 1 == v[mid - 1]))
				return mid;
			else
				end = mid - 1;
		}
	}
	if (start == v.size())
		return v.size();
	return -1;
}

int main()
{
	vector<int> v{ 0};
	cout << getMissing(v) << endl;
	return 0;
}