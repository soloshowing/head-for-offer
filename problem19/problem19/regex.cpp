#include <iostream>

using namespace std;

class Solution {
public:
	bool match(char* str, char* pattern);
};

bool Solution::match(char* str, char* pattern)
{
	if (*str == '\0' && *pattern == '\0')
		return true;
	if (*str != '\0' && *pattern == '\0')
		return false;

	if (*(pattern + 1) != '*')
	{
		if (*str == *pattern || (*pattern == '.' && *str != '\0'))
		{
			return match(str + 1, pattern + 1);
		}
		else
			return false;
	}
	else
	{
		if (*str == *pattern || (*pattern == '.' && *str != '\0'))
		{
			return match(str + 1, pattern + 2)
				|| match(str + 1, pattern)
				|| match(str, pattern + 2);
		}
		else
			return match(str, pattern + 2);
	}
}


int main()
{
	char str[] = "aaa";
	char pattern1[] = "a.a";
	char pattern2[] = "aa.a";
	char pattern3[] = "ab*ac*a";
	char pattern4[] = "ab*a";
	Solution s;
	cout << s.match(str, pattern1) << endl;
	cout << s.match(str, pattern2) << endl;
	cout << s.match(str, pattern3) << endl;
	cout << s.match(str, pattern4) << endl;
	return 0;
}