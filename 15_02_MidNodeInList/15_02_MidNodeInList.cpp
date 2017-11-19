// KthNodeFromEnd.cpp : Defines the entry point for the console application.
//

// ����ָOffer�����������Թپ������ͱ���⡷����
// ����Ȩ�����ߣ��κ���

#include "stdafx.h"
#include "..\Utilities\List.h"


ListNode* FindMidNodeInList(ListNode *pHead)
{
	if (pHead == NULL)
		return NULL;

	ListNode* pFast = pHead;
	ListNode* pSlow = pHead;


	//ż�������ص�������λ��
	while (pFast->m_pNext != NULL)
	{
		pFast = pFast->m_pNext;
		if (pFast->m_pNext != NULL)
			pFast = pFast->m_pNext;
		pSlow = pSlow->m_pNext;
	}

	return pSlow;
}


// ====================���Դ���====================
// ����Ҫ�ҵĽ���������м�
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

	printf("expected result: 3.\n");
	ListNode* pNode = FindMidNodeInList(pNode1);
	PrintListNode(pNode);

	DestroyList(pNode1);
}

void Test2()
{
	printf("=====Test1 starts:=====\n");
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);
	ListNode* pNode6 = CreateListNode(6);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);
	ConnectListNodes(pNode5, pNode6);

	printf("expected result: 4.\n");
	ListNode* pNode = FindMidNodeInList(pNode1);
	PrintListNode(pNode);

	DestroyList(pNode1);
}


// ���Կ�����
void Test4()
{
	printf("=====Test4 starts:=====\n");
	printf("expected result: NULL.\n");
	ListNode* pNode = FindMidNodeInList(NULL);
	PrintListNode(pNode);
}





int _tmain(int argc, _TCHAR* argv[])
{
	Test1();
	Test2();
	Test4();

	return 0;
}

