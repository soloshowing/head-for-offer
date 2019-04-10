#include <iostream>
using namespace std;

struct Node
{
	int value;
	Node* next;
};

//无法保证被删除节点是否在链中
void delNode(Node* pRoot, Node* pDeleted)
{
	if (!pRoot || !pDeleted)
		return;
	//不是尾节点
	if (pDeleted->next)
	{
		Node* pNext = pDeleted->next;
		pDeleted->value = pNext->value;
		pDeleted->next = pNext->next;
		delete pNext;
		pNext = nullptr;
	}
	//链只有一个节点
	else if (pRoot == pDeleted)
	{
		delete pRoot;
		pRoot = pDeleted = nullptr;
	}
	//普通的尾节点
	else
	{
		Node* pNode = pRoot;
		while (pNode->next != pDeleted)
		{
			pNode = pNode->next;
		}
		pNode->next = nullptr;
		delete pDeleted;
		pDeleted = nullptr;
	}

}

int main()
{
	return 0;
}