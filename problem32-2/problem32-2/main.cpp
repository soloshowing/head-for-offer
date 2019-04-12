#include <vector>
#include <queue>
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
	vector<vector<int> > Print(TreeNode* pRoot)
	{
		vector<vector<int>> result;
		if (pRoot == NULL)
			return result;
		queue<TreeNode*> q;
		q.push(pRoot);

		while (q.empty() == false)
		{
			int low = 0, high = q.size();
			vector<int> curLine;
			while (low++ < high)
			{
				TreeNode* curNode = q.front();
				q.pop();
				curLine.push_back(curNode->val);
				if (curNode->left)
					q.push(curNode->left);
				if (curNode->right)
					q.push(curNode->right);
			}
			result.push_back(curLine);
		}
		return result;
	}
};