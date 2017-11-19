// ReverseList.cpp : Defines the entry point for the console application.
//

// 《剑指Offer——名企面试官精讲典型编程题》代码
// 著作权所有者：何海涛

#include "stdafx.h"
#include "..\Utilities\List.h"
#include <stack>
using std::stack;
#pragma region MyOwn

//用栈实现的一种做法
ListNode* ReverseList(ListNode* pHead)
{
	if (pHead == NULL)
		return NULL;
	stack<ListNode*> list_stack;
	ListNode* pNode = pHead;
	while (pNode != NULL)
	{
		list_stack.push(pNode);
		pNode = pNode->m_pNext;
	}

	ListNode* res = list_stack.top();
	pNode = list_stack.top();
	list_stack.pop();
	while (!list_stack.empty())
	{
		pNode->m_pNext = list_stack.top();
		pNode = pNode->m_pNext;
		list_stack.pop();
	}
	pNode->m_pNext = NULL;
	return res;
}
#pragma endregion

//书上的版本，定义三个指针变量来实现调整
ListNode* ReverseList1(ListNode* pHead)
{
	ListNode* pReversedHead = NULL;
	ListNode* pNode = pHead;
	ListNode* pPrev = NULL;
	while (pNode != NULL)
	{
		ListNode* pNext = pNode->m_pNext;

		if (pNext == NULL)
			pReversedHead = pNode;

		pNode->m_pNext = pPrev;//第一个节点的时候刚好就让其翻转后的next为NULL

		pPrev = pNode;
		pNode = pNext;
	}

	return pReversedHead;
}

// ====================测试代码====================
ListNode* Test(ListNode* pHead)
{
	printf("The original list is: \n");
	PrintList(pHead);

	ListNode* pReversedHead = ReverseList(pHead);

	printf("The reversed list is: \n");
	PrintList(pReversedHead);

	return pReversedHead;
}

// 输入的链表有多个结点
void Test1()
{
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);

	ListNode* pReversedHead = Test(pNode1);

	DestroyList(pReversedHead);
}

// 输入的链表只有一个结点
void Test2()
{
	ListNode* pNode1 = CreateListNode(1);

	ListNode* pReversedHead = Test(pNode1);

	DestroyList(pReversedHead);
}

// 输入空链表
void Test3()
{
	Test(NULL);
}

int _tmain(int argc, _TCHAR* argv[])
{
	Test1();
	Test2();
	Test3();

	return 0;
}

