//面试题23：链表中环的入口结点


//定理：两个指针一个fast、一个slow同时从一个链表的头部出发
//fast一次走2步，slow一次走一步，如果该链表有环，两个指针必然在环内相遇
//此时只需要把其中的一个指针重新指向链表头部，另一个不变（还在环内），
//这次两个指针一次走一步，相遇的地方就是入口节点。

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(nullptr) {
	}
};

class Solution {
public:
	ListNode* EntryNodeOfLoop(ListNode* pHead)
	{
		auto p1 = pHead;
		auto p2 = pHead;
		while (p2)
		{
			if (p2->next == nullptr)
				return nullptr;
			p2 = p2->next;

			if (p2->next == nullptr)
				return nullptr;
			p2 = p2->next;

			p1 = p1->next;
			//伟大的邂逅
			if (p1 == p2)
				break;
		}

		p2 = pHead;
		while (p1 != p2)
		{
			p1 = p1->next;
			p2 = p2->next;
		}
		return p1;
	}
};