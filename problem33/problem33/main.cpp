#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	bool VerifySquenceOfBST(vector<int> sequence) {
		if (sequence.empty())
			return false;
		return isPostOrder(sequence, 0, sequence.size() - 1);
	}
	bool isPostOrder(const vector<int>& seq, int left, int right)
	{
		if (left >= right)
			return true;

		int root = seq[right];
		int pos = left;
		while (pos < right)
		{
			if (seq[pos] > root)
				break;
			pos++;
		}
		for (int i = pos; i < right; i++)
		{
			if (seq[i] < root)
				return false;
		}
		return isPostOrder(seq, left, pos - 1) && isPostOrder(seq, pos, right - 1);
	}
};

int main()
{
	vector<int> seq = {1,2,3};
	Solution s;
	cout << boolalpha << s.VerifySquenceOfBST(seq) << endl;
	return 0;
}