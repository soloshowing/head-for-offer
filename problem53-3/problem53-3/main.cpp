#include <vector>
#include <iostream>
using namespace std;

int GetNumberSameAsIndex(const vector<int>& array)
{
	int left = 0, right = array.size() - 1;
	while (left <= right)
	{
		int mid = left + ((right - left) >> 1);
		int cur = array[mid];
		if (cur == mid)
			return mid;
		else if (cur < mid)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return -1;
}

int main()
{
	vector<int> v{ -3,-1,1,2,3,4,5,6,7,8 };
	cout << GetNumberSameAsIndex(v) << endl;
	return 0;
}