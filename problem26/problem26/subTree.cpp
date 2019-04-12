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
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if (pRoot1 == nullptr || pRoot2 == nullptr)
			return false;
		
		int result = false;

		if (pRoot1->val == pRoot2->val)
			result = doHasSubtree(pRoot1, pRoot2);

		if (result == true)
			return true;
		else
			return HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
	}

	bool doHasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if (pRoot2 == nullptr)
			return true;
		if (pRoot1 == nullptr)
			return false;
		if (pRoot1->val == pRoot2->val)
			return doHasSubtree(pRoot1->left, pRoot2->left) && doHasSubtree(pRoot1->right, pRoot2->right);
		else
			return false;
	}
};