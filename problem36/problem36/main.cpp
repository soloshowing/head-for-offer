
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
	TreeNode* Convert(TreeNode* root)
	{
		if (root == nullptr)
			return nullptr;
		TreeNode* pre = nullptr;
		Convert(root, pre);
		while (root->left)
			root = root->left;
		return root;
	}

	void Convert(TreeNode* root, TreeNode*& pre)
	{
		if (root->left)
			Convert(root->left, pre);

		if (pre)
			pre->right = root;
		root->left = pre;
		pre = root;

		if (root->right)
			Convert(root->right, pre);
	}
};