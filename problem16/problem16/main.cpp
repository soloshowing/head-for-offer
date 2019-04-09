#include <cmath>
using namespace std;

class Solution {
public:
	double Power(double base, int exponent) {
		if (exponent >= 0)
			return PowerPositive(base, exponent);
		else
			return 1.0 / PowerPositive(base, exponent*(-1));
	}

	double PowerPositive(double base, int exponent)
	{
		if (exponent == 0)
			return 1;
		if (exponent == 1)
			return base;
		double result = PowerPositive(base, exponent >> 1);
		result *= result;
		if (exponent & 1)
			result *= base;
		return result;
	}
};