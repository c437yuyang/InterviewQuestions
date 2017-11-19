// KthNodeFromEnd.cpp : Defines the entry point for the console application.
//

// 《剑指Offer——名企面试官精讲典型编程题》代码
// 著作权所有者：何海涛

#include "stdafx.h"
#include "..\Utilities\List.h"

#pragma region orgin
//ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
//{
//	if (pListHead == NULL || k == 0)
//		return NULL;
//
//	ListNode *pAhead = pListHead;
//	ListNode *pBehind = NULL;
//
//	for (unsigned int i = 0; i < k - 1; ++i)
//	{
//		if (pAhead->m_pNext != NULL)
//			pAhead = pAhead->m_pNext;
//		else
//		{
//			return NULL;
//		}
//	}
//
//	pBehind = pListHead;
//	while (pAhead->m_pNext != NULL)
//	{
//		pAhead = pAhead->m_pNext;
//		pBehind = pBehind->m_pNext;
//	}
//
//	return pBehind;
//}
#pragma endregion

#pragma region myown
//最简单的解法，先遍历一遍求得节点数目
ListNode* FindKthToTail1(ListNode* pListHead, unsigned int k)
{
	if (pListHead == NULL || k < 1)
		return NULL;
	ListNode *pNode = pListHead;
	int n = 1;
	while (pNode->m_pNext)
	{
		pNode = pNode->m_pNext;
		++n;
	}

	//if (n - k < 0) //不存在倒数第k个,这里不能用n-k小于0，无符号数相减，剪出来是错的
	//	return NULL;
	if (n < k)
		return NULL; //应该这样

	//找头结点开始的第n-k+1个节点就找到了倒数第k个节点
	pNode = pListHead;
	for (unsigned int i = 0; i < n - k; ++i)
	{
		pNode = pNode->m_pNext;
	}
	return pNode;
}

//正确的双指针法
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
{
	if (pListHead == NULL || k < 1)
		return NULL;
	ListNode* pFisrt = pListHead, *pSecond = NULL;
	unsigned int i;
	for (i = 0; pFisrt->m_pNext&& i < k - 1; ++i)
	{
		pFisrt = pFisrt->m_pNext;
	}
	if (i < k - 1) return NULL; //连前k个节点(走了k-1步到了正数第k个节点)都没有，不可能存在倒数第k个
	pSecond = pListHead;
	while (pFisrt->m_pNext != NULL)
	{
		pFisrt = pFisrt->m_pNext;
		pSecond = pSecond->m_pNext;
	}
	return pSecond;
}
#pragma endregion


// ====================测试代码====================
// 测试要找的结点在链表中间
void Test1()
{
	printf("=====Test1 starts:=====\n");
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);

	printf("expected result: 4.\n");
	ListNode* pNode = FindKthToTail(pNode1, 2);
	PrintListNode(pNode);

	DestroyList(pNode1);
}

// 测试要找的结点是链表的尾结点
void Test2()
{
	printf("=====Test2 starts:=====\n");
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);

	printf("expected result: 5.\n");
	ListNode* pNode = FindKthToTail(pNode1, 1);
	PrintListNode(pNode);

	DestroyList(pNode1);
}

// 测试要找的结点是链表的头结点
void Test3()
{
	printf("=====Test3 starts:=====\n");
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);

	printf("expected result: 1.\n");
	ListNode* pNode = FindKthToTail(pNode1, 5);
	PrintListNode(pNode);

	DestroyList(pNode1);
}

// 测试空链表
void Test4()
{
	printf("=====Test4 starts:=====\n");
	printf("expected result: NULL.\n");
	ListNode* pNode = FindKthToTail(NULL, 100);
	PrintListNode(pNode);
}

// 测试输入的第二个参数大于链表的结点总数
void Test5()
{
	printf("=====Test5 starts:=====\n");
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);

	printf("expected result: NULL.\n");
	ListNode* pNode = FindKthToTail(pNode1, 6);
	PrintListNode(pNode);

	DestroyList(pNode1);
}

// 测试输入的第二个参数为0
void Test6()
{
	printf("=====Test6 starts:=====\n");
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);

	printf("expected result: NULL.\n");
	ListNode* pNode = FindKthToTail(pNode1, 0);
	PrintListNode(pNode);

	DestroyList(pNode1);
}

int _tmain(int argc, _TCHAR* argv[])
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();

	return 0;
}

