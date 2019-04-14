#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
//回溯法
class Solution {
public:
	vector<string> Permutation(string str) {
		vector<string> result;
		Permutation(str, 0, result);
		sort(result.begin(), result.end());
		return result;
	}

	void Permutation(string& s, int left, vector<string>& result)
	{
		if (left == s.length() - 1)
		{
			result.push_back(s);
			return;
		}
		for (int i = left; i < s.length(); i++)
		{
			if (i != left && s[i] == s[left])
				continue;
			swap(s[left], s[i]);
			Permutation(s, left + 1, result);
			swap(s[i], s[left]);
		}
	}
};

int main()
{
	string str = "abc";
	Solution s;
	auto result = s.Permutation(str);

	for (const string& s : result)
		cout << s << endl;
	return 0;
}