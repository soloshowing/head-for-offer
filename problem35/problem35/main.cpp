#include <iostream>

struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
			label(x), next(NULL), random(NULL) {
	}
};

class Solution {
public:
	//无脑的方法
	RandomListNode* CloneFool(RandomListNode* pHead)
	{
		if (pHead == nullptr)
			return nullptr;
		auto newHead = new RandomListNode(pHead->label);
		auto pNew = newHead;
		auto pOld = pHead;
		while (pOld->next)
		{
			pNew = pNew->next = new RandomListNode(pOld->next->label);
			pOld = pOld->next;
		}

		pNew = newHead;
		while (pHead)
		{
			if (pHead->random)
			{
				auto p = newHead;
				int value = pHead->random->label;
				while (p)
				{
					if (p->label == value)
						pNew->random = p;
					p = p->next;
				}
			}
			pHead = pHead->next;
			pNew = pNew->next;
		}
		return newHead;
	}

	RandomListNode* CloneSmart(RandomListNode* pHead)
	{
		if (pHead == nullptr)
			return nullptr;
		auto curNode = pHead;
		while (curNode) {
			auto newNode = new RandomListNode(curNode->label);
			newNode->next = curNode->next;
			curNode->next = newNode;
			curNode = newNode->next;
		}

		curNode = pHead;
		while (curNode)
		{
			if (curNode->random)
				curNode->next->random = curNode->random->next;
			curNode = curNode->next->next;
		}
		curNode = pHead;
		auto newHead = pHead->next;
		while (curNode->next)
		{
			auto temp = curNode->next;
			curNode->next = temp->next;
			curNode = temp;
		}
		return newHead;
	}
};