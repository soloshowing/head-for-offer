#include <queue>
#include <stack>
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(nullptr), right(nullptr) {
	}
};

class Solution {
public:
	void Mirror(TreeNode* root) {
		if (root == nullptr)
			return;
		TreeNode* tmp = root->left;
		root->left = root->right;
		root->right = tmp;
		Mirror(root->left);
		Mirror(root->right);
		return;
	}

	void MirrorQueue(TreeNode* root)
	{
		if (root == nullptr)
			return;
		std::queue<TreeNode*> q;
		q.push(root);
		while (q.empty() == false)
		{
			auto cur = q.front();
			auto tmp = cur->left;
			cur->left = cur->right;
			cur->right = tmp;
			q.pop();
			if(cur->left)
				q.push(cur->left);
			if(cur->right)
				q.push(cur->right);
		}
	}

	void MirrorStack(TreeNode* root)
	{
		if (root == nullptr)
			return;
		std::stack<TreeNode*> stk;
		stk.push(root);
		while (stk.empty() == false)
		{
			auto cur = stk.top();
			stk.pop();
			if(cur->left)
				stk.push(cur->left);
			if (cur->right)
				stk.push(cur->right);
			std::swap(cur->left, cur->right);
		}
	}
};