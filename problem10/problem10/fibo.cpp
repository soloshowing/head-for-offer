#include <iostream>
using namespace std;

int fibo_recursive(int n)
{
	if (n <= 1)
		return n;
	return fibo_recursive(n - 1) + fibo_recursive(n - 2);
}

long long fibo_loop(int n)
{
	if (n <= 1)
		return n;
	long long lastOne = 1;
	long long lastTwo = 0;
	long long result;
	for (int i = 2; i <= n; i++)
	{
		result = lastOne + lastTwo;
		lastTwo = lastOne;
		lastOne = result;
	}
	return result;
}


int main()
{
	cout << fibo_loop(5) << endl;
	cout << fibo_loop(6) << endl;
	cout << fibo_loop(10) << endl;
	cout << fibo_loop(50) << endl;
	cout << fibo_loop(100) << endl;
	//cout << fibo_recursive(5) << endl;
	//cout << fibo_recursive(6) << endl;
	//cout << fibo_recursive(10) << endl;
	//cout << fibo_recursive(100) << endl;
	//cout << fibo_recursive(1000) << endl;
	return 0;
}


