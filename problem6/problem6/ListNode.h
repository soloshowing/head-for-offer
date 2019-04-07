#pragma once
#include <iostream>
using std::cout;
using std::endl;
struct ListNode
{
	ListNode(int n = 0, ListNode* nd = nullptr)
		:value(n), next(nd) {}
	int value;
	ListNode* next;
};

void print(ListNode* root);

void reversePrintStack(ListNode* root);
void reversePrintRecursive(ListNode* root);