#include "solutions.h"
#include <vector>
#include <iostream>

int solution4(const std::vector<int> &v)
{
	std::vector<int> arr(v);
	for (int i = 0; i < arr.size(); i++)
	{	
		int cur = arr[i];
		while (cur != i) {
			if (cur == arr[cur])
				return cur;
			//swap
			arr[i] = arr[cur];
			arr[cur] = cur;
			cur = arr[i];
		}
	}
	return -1;
}