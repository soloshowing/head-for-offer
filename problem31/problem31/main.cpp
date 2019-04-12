#include <stack>
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		stack<int> helpS;
		size_t pos = 0;
		for (size_t i = 0; i < pushV.size(); i++)
		{
			helpS.push(pushV[i]);
			while (pos < popV.size() && helpS.top() == popV[pos])
			{
				helpS.pop();
				pos++;
			}
		}
		return helpS.empty();
	}
};

int main()
{
	Solution s;
	vector<int> pushV = { 1,2,3,4,5 };
	vector<int> popV = { 4,5,3,2,1 };
	vector<int> popV2 = { 4,3,5,1,2 };
	cout << s.IsPopOrder(pushV, popV) << endl;
	return 0;
}