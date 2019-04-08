#include <iostream>
#include "solutions.h"
int main()
{
	std::vector<int> v1{ 2,3,1,0,2,5,3 };
	std::vector<int> v2{ 2,1,4,3,5,6,4,0,5};
	//std::cout << solution1(v1) << std::endl;
	//std::cout << solution1(v2) << std::endl;
	//std::cout << solution2(v1) << std::endl;
	//std::cout << solution2(v2) << std::endl;
	//std::cout << solution3(v1) << std::endl;
	//std::cout << solution3(v2) << std::endl;
	std::cout << solution4(v1) << std::endl;
	std::cout << solution4(v2) << std::endl;
	return 0;
}