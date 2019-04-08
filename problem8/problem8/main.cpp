//二叉树的下一结点
struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	TreeLinkNode(int x) :val(x), left(nullptr), right(nullptr), next(nullptr) {}
};

class Solution {
public:
	TreeLinkNode* GetNext(TreeLinkNode* pNode)
	{
		if (!pNode)
			return nullptr;

		TreeLinkNode* p = nullptr;
		// 右儿子存在,下一结点为右子树的最左结点
		if (pNode->right)
		{
			p = pNode->right;
			while (p->left)
				p = p->left;
			return p;
		}

		// 没有右儿子
		p = pNode;
		while (p->next)
		{
			if (p == p->next->left)
				return p->next;
			p = p->next;
		}
		return nullptr;
	}
};