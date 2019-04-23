#include <string>
using namespace std;
class Solution {
public:
	int StrToInt(string str) {
		int res = 0, n = str.size(), symbol = 1;
		if (n == 0)
			return 0;
		int start = 0;
		if (str[start] == '-')
		{
			symbol = -1;
			start++;
		}
		else if (str[start] == '+')
			start++;
		else if (str[start] < '0' || str[start] > '9')
			return 0;
		for (int i = start; i < n; i++)
		{
			if (str[i] < '0' || str[i] > '9')
				return 0;
			res = (res << 1) + (res << 3) + (str[i] & 0xf);
		}
		return symbol * res;
	}
};