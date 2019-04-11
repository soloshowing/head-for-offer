//链表中倒数第k个节点
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
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		if (pListHead == nullptr || k == 0)
			return nullptr;

		ListNode* front = pListHead;
		ListNode* back = pListHead;
		for (unsigned i = 0; i < k; i++)
		{
			if (front)
				front = front->next;
			else
				return nullptr;
		}
		while (front)
		{
			front = front->next;
			back = back->next;
		}
		return back;
	}
	
	ListNode* FindMidNode(ListNode* pListHead)
	{
		if (pListHead == nullptr)
			return nullptr;
		ListNode* pOne = pListHead;
		ListNode* pTwo = pListHead;

		while (pTwo != nullptr)
		{
			if (pTwo->next == nullptr)
				return pOne;
			pTwo = pTwo->next;
			if (pTwo->next == nullptr)
				return pOne;
			pTwo = pTwo->next;
			pOne = pOne->next;
		}
		return nullptr;
	}
};

void printList(ListNode* head)
{
	while (head)
	{
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}

int main()
{
	ListNode* head = new ListNode(0);
	ListNode* p = head;
	for (int i = 1; i < 10; i++)
	{
		ListNode* n = new ListNode(i);
		p->next = n;
		p = p->next;
	}
	printList(head);
	Solution s;
	s.FindMidNode(head);
	cout << s.FindMidNode(head)->val << endl;
	return 0;
}