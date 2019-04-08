#include <iostream>
//题目二：青蛙跳台阶问题

int cntJunp(int n)
{
	if (n <= 2)
		return n;
	int cntLastOne = 2;
	int cntLastTwo = 1;
	int count;
	for (int i = 3; i <= n; i++)
	{
		count = cntLastOne + cntLastTwo;
		cntLastTwo = cntLastOne;
		cntLastOne = count;
	}
	return count;
}

//青蛙跳台阶问题拓展，可以跳n阶
int cntJump2(int n)
{
	int cnt = 1;
	while (n >= 2) {
		cnt *= 2;
		n--;
	}
	return cnt;
}

int main()
{
	std::cout << cntJunp(5) << std::endl;
}