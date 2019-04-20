#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
	//Insert one char from stringstream
	string s;
	char hash[256] = { 0 };
	void Insert(char ch)
	{
		s += ch;
		hash[ch]++;
	}
	//return the first appearence once char in current stringstream
	char FirstAppearingOnce()
	{
		for (const char c : s)
			if (hash[c] == 1)
				return c;
		return '#';
	}
};

class Solution2
{
public:
	//Insert one char from stringstream
	string s;
	unordered_map<char, int> m;
	void Insert(char ch)
	{
		s += ch;
		m[ch]++;
	}
	//return the first appearence once char in current stringstream
	char FirstAppearingOnce()
	{
		for (const char c : s)
			if (m[c] == 1)
				return c;
		return '#';
	}
};