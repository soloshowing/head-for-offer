#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string ReverseSentence(string str) {
		Reverse(str, 0, str.size() - 1);
		int s = 0, e = 0;
		int i = 0;
		while (i < str.size())
		{
			while (i < str.size() && str[i] == ' ')
				i++;
			e = s = i;//记录单词的第一个单词的位置
			while (i < str.size() && str[i] != ' ')
			{
				i++;
				e++;
			}
			Reverse(str, s, e - 1);
		}
		return str;
	}

	void Reverse(string& str, int b, int e)
	{
		if (b < e)
			swap(str[b++], str[e--]);
	}
};