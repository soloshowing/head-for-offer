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
	TreeNode* KthNode(TreeNode* pRoot, int k)
	{
		if (k == 0 || pRoot == nullptr)
			return nullptr;
		vector<TreeNode*> vec;
		inOrder(pRoot, vec);
		if (vec.size() < k)
			return nullptr;
		return vec[k - 1];
	}

	void inOrder(TreeNode* pRoot, vector<TreeNode*>& vec)
	{
		if (pRoot)
		{
			inOrder(pRoot->left, vec);
			vec.push_back(pRoot);
			inOrder(pRoot->right, vec);
		}
	}
};