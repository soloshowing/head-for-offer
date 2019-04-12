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
	void Mirror(TreeNode *root) {
		if (root == nullptr)
			return;
		TreeNode* tmp = root->left;
		root->left = root->right;
		root->right = tmp;
		Mirror(root->left);
		Mirror(root->right);
		return;
	}
};