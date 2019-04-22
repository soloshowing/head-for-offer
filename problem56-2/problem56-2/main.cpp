#include <vector>
#include <iostream>
using namespace std;

int FindNumber(vector<int> nums)
{
	int length = nums.size();
	vector<int> bitSum(32, 0);
	for (int i = 0; i < length; i++)
	{
		int bitMask = 1;
		for (int j = 31; j >= 0; j--)
		{
			int bit = nums[i] & bitMask;
			if (bit != 0)
				bitSum[j] += 1;
			bitMask <<= 1;
		}
	}
	int result = 0;
	for (int i = 0; i < 32; i++)
	{
		result <<= 1;
		result += bitSum[i] % 3;
	}
	return result;
}

int main()
{
	vector<int> v{ 3, 2, 2, 2 ,1,1,1};
	cout << FindNumber(v) << endl;
	return 0;
}