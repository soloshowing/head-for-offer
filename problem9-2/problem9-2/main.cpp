#include <queue>
#include <iostream>
using namespace std;
//两个队列实现一个栈
class Stack
{
public:
	void push(int num)
	{
		if (q2.empty())
			q1.push(num);
		else
			q2.push(num);
	}

	int pop()
	{
		if (q1.empty() && q2.empty())
			return -1;
		int result = -1;;
		if (q1.empty())
		{
			while (q2.size() > 1)
			{
				q1.push(q2.front());
				q2.pop();
			}
			result = q2.front();
			q2.pop();
		}
		else
		{
			while (q1.size() > 1)
			{
				q2.push(q1.front());
				q1.pop();
			}
			result = q1.front();
			q1.pop();
		}
		return result;
	}

	bool empty()
	{
		return q1.empty() && q2.empty();
	}

	int top()
	{
		if (empty())
			return -1;
		if (q1.empty())
			return q2.back();
		return q1.back();
	}

private:
	queue<int> q1;
	queue<int> q2;
};

int main()
{
	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	s.push(4);
	cout << s.pop() << endl;
	cout << s.empty() << endl;
	s.push(5);
	cout << s.top() << endl;
	s.pop();
	s.pop();
	cout << s.empty() << endl;
}