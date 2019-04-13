#include <iostream>
#include <vector>
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
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		vector<vector<int>> result;
		if (root == nullptr)
			return result;
		vector<int> trace;
		dfs(root, expectNumber, result, trace);
		return result;
	}
	void dfs(TreeNode* root, int s, vector<vector<int>>& result, vector<int> trace)
	{
		trace.push_back(root->val);
		if (!root->left && !root->right)//叶子节点
		{
			if (s == root->val)
				result.push_back(trace);
		}
		if (root->left)
			dfs(root->left, s - root->val, result, trace);
		if (root->right)
			dfs(root->right, s - root->val, result, trace);
		trace.pop_back();
	}
};