#include <iostream>
#include <vector>


int find_dup(const std::vector<int>& v, int left, int right)
{
	if (left == right)
		return left;
	int mid = (left + right) >> 1;
	int cnt = 0;
	for (const int i : v) {
		if (i >= left && i <= mid)
			cnt++;
	}
	if (cnt > mid - left + 1)
		find_dup(v, left, mid);
	else
		find_dup(v, mid + 1, right);
}

int main()
{
	std::vector<int> v1{ 2,3,5,4,3,2,6,7 };
	std::vector<int> v2{ 1,2,5,4,3,2,6,7 };
	std::vector<int> v3{ 1,4,5,4,3,2,6,7 };
	std::cout << find_dup(v1, 1, v1.size() - 1) << std::endl;
	std::cout << find_dup(v2, 1, v2.size() - 1) << std::endl;
	std::cout << find_dup(v3, 1, v3.size() - 1) << std::endl;
}