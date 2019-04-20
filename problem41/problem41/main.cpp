#include <queue>
using namespace std;

class Solution
{
public:
	void Insert(int num)
	{
		if (left.empty() || num <= left.top())
			left.push(num);
		else
			right.push(num);

		if (left.size() == right.size() + 2)
		{
			right.push(left.top());
			left.pop();
		}
		if (left.size() + 1 == right.size())
		{
			left.push(right.top());
			right.pop();
		}
	}
	double GetMedian()
	{
		if (left.size() == right.size())
			return (left.top() + right.top()) / 2.0;
		return left.top();
	}
private:
	priority_queue<int, vector<int>, less<int>> left;//max_heap
	priority_queue<int, vector<int>, greater<int>> right;//min_heap
};