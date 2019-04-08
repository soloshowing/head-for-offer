#include <iostream>
#include <unordered_set>

int solution1(const std::vector<int> &v)
{
	std::unordered_set<int> hashTable;
	for (std::size_t i = 0; i != v.size(); i++)
	{
		if (hashTable.find(v[i]) != hashTable.end())
			return v[i];
		hashTable.insert(v[i]);
	}
	return -1;
}