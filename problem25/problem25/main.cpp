struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(nullptr) {
	}
};

class Solution {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		ListNode* newHead = new ListNode(-1);
		ListNode* p = newHead;
		while (pHead1 && pHead2)
		{
			if (pHead1->val < pHead2->val)
			{
				p = p->next = pHead1;
				pHead1 = pHead1->next;
			}
			else
			{
				p->next = pHead2;
				pHead2 = pHead2->next;
			}
		}
		if (pHead1)
			p->next = pHead1;
		if (pHead2)
			p->next = pHead2;
		p = newHead->next;
		delete newHead;
		return p;
	}

	ListNode* MergeRecursive(ListNode* pHead1, ListNode* pHead2)
	{
		if (pHead1 == nullptr)
			return pHead2;
		if (pHead2 == nullptr)
			return pHead1;

		if (pHead1->val < pHead2->val) {
			pHead1->next = MergeRecursive(pHead1->next, pHead2);
			return pHead1;
		}

		else
		{
			pHead2->next = MergeRecursive(pHead1, pHead2->next);
			return pHead2;
		}
	}
};