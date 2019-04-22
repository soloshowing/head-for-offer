#include <string>
using namespace std;

class Solution {
public:
	string LeftRotateString(string str, int n) {
		int len = str.size();
		if (len == 0)
			return "";
		str += str;
		return str.substr(n, len);
	}

	string LeftRotateString2(string str, int n) {
		int len = str.size();
		if (len == 0)
			return "";
		Reverse(str, 0, n - 1);
		Reverse(str, n, len - 1);
		Reverse(str, 0, len - 1);
		return str;
	}

	void Reverse(string& str, int b, int e)
	{
		while (b < e)
			swap(str[b++], str[e--]);
	}
};