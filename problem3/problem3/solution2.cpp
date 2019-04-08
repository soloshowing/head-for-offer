#include "solutions.h"
#include <set>

int solution2(const std::vector<int> &v)
{
	std::set<int> Set;
	for (std::size_t i = 0; i != v.size(); i++)
	{
		if (Set.find(v[i]) != Set.end())
			return v[i];
		Set.insert(v[i]);
	}
	return -1;
}