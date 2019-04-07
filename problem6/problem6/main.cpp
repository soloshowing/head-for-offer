#include "ListNode.h"

int main()
{
	auto root = new ListNode;	
	auto p = root;
	for (int i = 1; i < 10; i++)
	{
		auto node = new ListNode(i);
		p = p->next = node;
	}
	
	print(root);
	cout << endl;
	reversePrintStack(root);
	cout << endl;
	reversePrintRecursive(root);
	cout << endl;
	
	
	p = root;
	while (p)
	{
		auto temp = p;
		p = p->next;
		delete temp;
	}

	return 0;
}

