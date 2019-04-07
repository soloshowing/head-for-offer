#include <iostream>
#include "BinaryTreeNode.h"
#include <vector>
using namespace std;

BinaryTreeNode* construct(vector<int> pre, vector<int> mid, int pL, int pR, int mL, int  mR)
{
	if (pL > pR || mL > mR)
		return nullptr;

	auto root = new BinaryTreeNode;
	root->value = pre[pL];
	int pos = mL;
	while (pos <= mR)
	{
		if (mid[pos] == root->value)
			break;
		pos++;
	}
	int leftNum = pos - mL;
	int rightNum = mR - pos;
	root->left = construct(pre, mid, pL + 1, pL + leftNum, mL, pos - 1);
	root->right = construct(pre, mid, pL + leftNum + 1, pR, pos + 1, mR);
	return root;
}

int main()
{
	vector<int> preOrder = { 1,2,4,7,3,5,6,8 };
	vector<int> midOrder = { 4,7,2,1,5,3,8,6 };
	BinaryTreeNode* btTree = construct(preOrder, midOrder, 0, preOrder.size() - 1, midOrder.size() - 1);
	return 0;
}