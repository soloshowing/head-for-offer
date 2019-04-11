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
	ListNode* ReverseList(ListNode* pHead) {
		if (pHead == nullptr)
			return nullptr;

		ListNode* pre = nullptr;
		ListNode* cur = pHead;
		while (cur->next != nullptr)
		{
			ListNode* temp = cur->next;
			cur->next = pre;
			pre = cur;
			cur = temp;
		}
		cur->next = pre;
		return cur;
	}
};

void printLink(ListNode* head)
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
		ListNode* nd = new ListNode(i);
		p->next = nd;
		p = p->next;
	}

	printLink(head);
	Solution s;
	auto newHead = s.ReverseList(head);
	printLink(newHead);
	while (head)
	{
		ListNode* pNext = head->next;
		delete head;
		head = pNext;
	}
	return 0;
}
