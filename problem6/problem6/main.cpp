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
	//正向打印
	print(root);
	cout << endl;
	//反向打印
	reversePrintStack(root);
	cout << endl;
	reversePrintRecursive(root);
	cout << endl;
	//释放内存
	p = root;
	while (p)
	{
		auto temp = p;
		p = p->next;
		delete temp;
	}

	return 0;
}

