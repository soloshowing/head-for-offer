#include <list>
using namespace std;

int LastRemaining_Solution(int n, int m)
{
	if (n < 1 || m < 1)
		return -1;

	list<int> numbers;
	for (int i = 0; i < n; i++)
		numbers.push_back(i);

	list<int>::iterator cur = numbers.begin();

	while (numbers.size() > 1)
	{
		for (int i = 0; i < m; i++)
		{
			cur++;
			if (cur == numbers.end())
				cur = numbers.begin();
		}

		list<int>::iterator next = ++cur;
		if (next == numbers.end())
			next = numbers.begin();
		numbers.erase(--cur);
		cur = next;
	}
	return *cur;
}