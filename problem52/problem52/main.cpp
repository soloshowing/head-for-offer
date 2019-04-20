#include <iostream>
using namespace std;
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
		int len1 = ListLen(pHead1);
		int len2 = ListLen(pHead2);
		ListNode* p1 = pHead1;
		ListNode* p2 = pHead2;
		if (len1 > len2)
			p1 = moveSteps(p1, len1 - len2);
		else
			p2 = moveSteps(p2, len2 - len1);

		while (p1 != p2) {
			p1 = p1->next;
			p2 = p2->next;
		}
		return p1;
	};

	int ListLen(ListNode* pHead)
	{
		int len = 0;
		while (pHead) {
			len++;
			pHead = pHead->next;
		}
		return len;
	}

	ListNode* moveSteps(ListNode* pHead, int steps)
	{
		for (int i = 0; i < steps; i++)
			pHead = pHead->next;
		return pHead;
	}
};