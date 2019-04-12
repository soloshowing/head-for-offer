#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
	vector<vector<int> > Print(TreeNode* pRoot) {
		vector<vector<int>> result;
		if (pRoot == nullptr)
			return result;
		stack<TreeNode*> s1, s2;
		s1.push(pRoot);
		while (!s1.empty() || !s2.empty())
		{
			vector<int> curLine;
			if (!s1.empty())
			{
				while (!s1.empty())
				{
					TreeNode* curNode = s1.top();
					curLine.push_back(curNode->val);
					s1.pop();
					if (curNode->left)
						s2.push(curNode->left);
					if (curNode->right)
						s2.push(curNode->right);
				}
			}
			else
			{
				while (!s2.empty())
				{
					TreeNode* curNode = s2.top();
					curLine.push_back(curNode->val);
					s2.pop();
					if (curNode->right)
						s1.push(curNode->right);
					if (curNode->left)
						s1.push(curNode->left);
				}
			}
			result.push_back(curLine);
		}
		return result;
	}
};