class Solution {
public:
	int NumberOf1Between1AndN_Solution(int n)
	{
		int count = 0;//1的个数
		int i = 1;//当前位
		int current = 0, after = 0, before = 0;
		while (n / i)
		{
			current = (n / i) % 10;//高位数字
			before = n / (i * 10);//当前位数字
			after = n - (n / i)*i;//低位数字

			if (current == 0)
				count += before * i;
			else if (current == 1)
				count += before * i + after + 1;
			else
				count += (before + 1)*i;

			i = i * 10;
		}
		return count;
	}
};