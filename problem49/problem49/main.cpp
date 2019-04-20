#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int GetUglyNumber_Solution(int index) {
		if (index == 0)
			return 0;
		int p2 = 0, p3 = 0, p5 = 0, newNum = 1;
		vector<int> arr;
		arr.push_back(newNum);
		while (arr.size() < index) {
			newNum = min(arr[p2] * 2, (min(arr[p3] * 3, arr[p5] * 5)));

			if (arr[p2] * 2 == newNum) p2++;
			if (arr[p3] * 3 == newNum) p3++;
			if (arr[p5] * 5 == newNum) p5++;

			arr.push_back(newNum);
		}
		return newNum;
	}
};