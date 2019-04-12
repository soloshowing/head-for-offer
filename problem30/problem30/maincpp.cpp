#include <stack>

class Solution {
public:
	void push(int value) {
		s1.push(value);
		if (s2.empty() || value <= s2.top())
			s2.push(value);
	}
	void pop() {
		if (s1.empty())
			return;
		if (s1.top() == s2.top())
			s2.pop();
		s1.pop();
	}
	int top() {
		if (s1.empty())
			return;
		return s1.top();
	}
	int min() {
		if (s2.empty())
			return -1;
		return s2.top();
	}
private:
	std::stack<int> s1;
	std::stack<int> s2;
};