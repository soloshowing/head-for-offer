#include <iostream>
using namespace std;

int count_1(int n)
{
	int cnt = 0;
	unsigned flag = 1;
	while (flag)
	{
		if (n & flag)
			cnt++;
		flag <<= 1;
	}
	return cnt;
}

int count_2(int n)
{
	int cnt = 0;
	while (n)
	{
		cnt++;
		n = n & (n - 1);
	}
	return cnt;
}

int main()
{
	//cout << count_1(9) << endl;
	//cout << count_1(1) << endl;
	//cout << count_1(0x80000000) << endl;
	//cout << count_1(0x7FFFFFFF) << endl;
	//cout << count_2(9) << endl;
	//cout << count_2(1) << endl;
	//cout << count_2(0x80000000) << endl;
	//cout << count_2(0x7FFFFFFF) << endl;
	//int c = 0xffffffff;
	//cout << hex << c-1 << endl;
	return 0;
}