#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	static bool compare(const string& s1, const string& s2)
	{
		return (s1 + s2) < (s2 + s1);
	}
	string PrintMinNumber(vector<int> numbers) {
		vector<string> strNums;
		for (const int i : numbers)
		{
			strNums.push_back(to_string(i));
		}
		sort(strNums.begin(), strNums.end(), compare);
		string result;
		for (const string& s : strNums)
			result += s;
		return result;
	}
};