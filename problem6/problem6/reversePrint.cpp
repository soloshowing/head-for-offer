#include "ListNode.h"
#include <iostream>
#include <stack>
using namespace std;

void reversePrintStack(ListNode* root)
{
	stack<int> stk;
	//压栈
	while (root) {
		stk.push(root->value);
		root = root->next;
	}
	//出栈打印
	while (!stk.empty())
	{
		cout << stk.top() << ' ';
		stk.pop();
	}
	return;
}


void reversePrintRecursive(ListNode* root)
{
	if (root == NULL)
		return;
	reversePrintRecursive(root->next);
	cout << root->value << ' ';
}

//正向打印
void print(ListNode* root)
{
	while (root)
	{
		cout << root->value << " ";
		root = root->next;
	}
	return;
}