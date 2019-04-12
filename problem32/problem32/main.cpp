#include <queue>
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
	vector<int> PrintFromTopToBottom(TreeNode* root) {
		vector<int> result;
		if (root == nullptr)
			return result;
		queue<TreeNode*> q;
		result.push_back(root->val);
		q.push(root->left);
		q.push(root->right);
		while (q.empty() == false)
		{
			TreeNode* curNode = q.front();
			if (curNode != nullptr) {
				result.push_back(curNode->val);
				q.push(curNode->left);
				q.push(curNode->right);
			}
			q.pop();
		}
		return result;
	}
};