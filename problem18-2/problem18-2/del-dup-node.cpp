#include <iostream>
using namespace std;
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(nullptr) {
	}
};


class Solution {
public:
	void printNode(ListNode* pHead)
	{
		while (pHead)
		{
			cout << pHead->val << " ";
			pHead = pHead->next;
		}
	}
	ListNode* deleteDuplicationRecursive(ListNode* pHead)
	{
		if (pHead == nullptr)
			return nullptr;
		if (pHead->next == nullptr)
			return pHead;

		if (pHead->val != pHead->next->val)
		{
			ListNode* curNode = pHead->next;
			pHead->next = deleteDuplicationRecursive(curNode);
		}
		else
		{
			ListNode* curNode = pHead->next->next;
			while (curNode && curNode->val == pHead->val)
			{
				curNode = curNode->next;
			}
			return deleteDuplicationRecursive(curNode);
		}
		return pHead;
	}

	ListNode* deleteDuplicationIteration(ListNode* pHead)
	{
		ListNode* first = new ListNode(-1);
		first->next = pHead;
		ListNode* p = pHead;
		ListNode* last = first;

		while (p && p->next)
		{
			if (p->val == p->next->val)
			{
				int temp = p->val;
				p = p->next;
				while (p && p->val == temp)
					p = p->next;
				last->next = p;
			}
			else
			{
				last = p;
				p = p->next;
			}
		}
		p = first->next;
		delete first;
		return p;
	}
};

int main()
{
	ListNode *n1 = new ListNode(1);
	ListNode *n2 = new ListNode(2);
	ListNode *n3 = new ListNode(3);
	ListNode *n4 = new ListNode(3);
	ListNode *n5 = new ListNode(4);
	ListNode *n6 = new ListNode(4);
	ListNode *n7 = new ListNode(4);
	ListNode *n8 = new ListNode(5);
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = n7;
	n7->next = n8;
	Solution s;
	//s.printNode(n1);
	s.printNode(s.deleteDuplicationIteration(n1));
	return 0;
}