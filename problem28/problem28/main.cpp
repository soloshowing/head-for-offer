#include <stack>
#include <queue>
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
	bool isSymmetrical(TreeNode* pRoot)
	{
		if (pRoot == nullptr)
			return false;
		return isSymmetrical(pRoot->left, pRoot->right);
	}
	bool isSymmetrical(TreeNode* leftTree, TreeNode* rightTree)
	{
		if (leftTree == nullptr && rightTree == nullptr)
			return true;
		if (leftTree == nullptr || rightTree == nullptr)
			return false;
		if (leftTree->val != rightTree->val)
			return false;

		return isSymmetrical(leftTree->left, rightTree->right)
			&& isSymmetrical(leftTree->right, rightTree->left);
	}
	bool isSymmetricalStack(TreeNode* pRoot)
	{
		if (pRoot == nullptr)
			return true;
		std::stack<TreeNode*> stk;
		stk.push(pRoot->left);
		stk.push(pRoot->right);
		while (stk.empty() == false)
		{
			TreeNode* leftNode = stk.top();
			stk.pop();
			TreeNode* rightNode = stk.top();
			stk.pop();
			if (leftNode == nullptr && rightNode == nullptr)
				continue;
			if (leftNode == nullptr || rightNode == nullptr)
				return false;
			if (leftNode->val != rightNode->val)
				return false;
			stk.push(leftNode->right);
			stk.push(rightNode->left);
			stk.push(leftNode->left);
			stk.push(rightNode->right);
		}
		return true;
	}
	bool isSymmetricalQueue(TreeNode* pRoot)
	{
		if (pRoot == nullptr)
			return true;
		std::queue<TreeNode*> q;
		q.push(pRoot->left);
		q.push(pRoot->right);
		while (q.empty() == false)
		{
			auto leftNode = q.front();
			q.pop();
			auto rightNode = q.front();
			q.pop();
			if (leftNode == nullptr && rightNode == nullptr)
				continue;
			if (leftNode == nullptr || rightNode == nullptr)
				return false;
			if (leftNode->val != rightNode->val)
				return false;
			q.push(leftNode->left);
			q.push(rightNode->right);
			q.push(leftNode->right);
			q.push(rightNode->left);
		}
		return true;
	}
};