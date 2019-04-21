#include <algorithm>
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
	int TreeDepth(TreeNode* pRoot)
	{
		if (pRoot == nullptr)
			return 0;
		int leftDepth = TreeDepth(pRoot->left);
		int rightDepth = TreeDepth(pRoot->right);
		return 1 + std::max(leftDepth, rightDepth);
	}
};