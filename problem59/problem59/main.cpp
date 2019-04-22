#include <deque>
#include <vector>
using namespace std;

vector<int> maxInWindows(const vector<int>& num, unsigned size)
{
	vector<int> res;
	if (size == 0)
		return res;
	deque<int> s;
	for (unsigned i = 0; i < num.size(); i++)
	{
		while (s.size() && num[s.back()] < num[i])
			s.pop_back();
		if (s.size() && i - s.front() + 1 > size)
			s.pop_front();
		s.push_back(i);
		if (i + 1 >= size)
			res.push_back(num[s.front()]);
	}
	return res;
}