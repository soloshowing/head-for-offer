#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void reOrderArray(vector<int> &array) {
		if (array.size() <= 1)
			return;
		vector<int>::iterator iLeft = array.begin();
		vector<int>::iterator iRight = array.end() - 1;
		while (iLeft < iRight)
		{
			if (*iLeft & 1)
				iLeft++;
			else
			{
				int temp = *iLeft;
				*iLeft = *iRight;
				*iRight = temp;
				iRight--;
			}
		}
	}

	void reOrderArrayStable(vector<int> &array)
	{
		vector<int> temp(array.size());
		int cntOdds = 0;
		for (const int i : array)
		{
			if (i & 1)
				cntOdds++;
		}
		int left = 0;
		for (const int i : array)
		{
			if (i & 1)
				temp[left++] = i;
			else
				temp[cntOdds++] = i;
		}
		array = temp;
	}

	void reOrderArrayStable2(vector<int> &array)
	{
		if (array.size() <= 1)
			return;
		//基于插入排序：前偶后奇则交换
		for (int i = 0; i < array.size() - 1; i++)
		{
			int j = i + 1;
			while (j >= 1)
			{
				//前偶后奇
				if ((array[j] & 1) == 1 && (array[j - 1] & 1) == 0)
				{
					swap(array[j], array[j - 1]);
					j--;
				}
				else
					break;
			}
		}
	}
};
void printVector(const vector<int> &array)
{
	for (const int i : array)
		cout << i << " ";
	cout << endl;
}

int main()
{
	Solution s;
	vector<int> arr = { 2,1,2,3,3,4,4,4,5,6 };
	printVector(arr);
	//s.reOrderArray(arr);
	//printVector(arr);
	s.reOrderArrayStable2(arr);
	printVector(arr);
	return 0;
}