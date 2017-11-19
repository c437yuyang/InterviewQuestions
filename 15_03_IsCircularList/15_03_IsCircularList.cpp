// KthNodeFromEnd.cpp : Defines the entry point for the console application.
//

// ����ָOffer�����������Թپ������ͱ���⡷����
// ����Ȩ�����ߣ��κ���

#include "stdafx.h"
#include <iostream>
#include "..\Utilities\List.h"


bool IsCircularList(ListNode *pHead)
{
	if (pHead == NULL)
		return false;

	ListNode* pFast = pHead;
	ListNode* pSlow = pHead;
	if (pFast->m_pNext == NULL)
		return false; //ֻ��һ���ڵ㣬��Ϊ���ǻ�������

	//������ִ��һ�Σ���Ȼʼ���ǲ������ѭ���ġ�
	do
	{
		pFast = pFast->m_pNext;
		if (pFast->m_pNext != NULL && pFast != pSlow)
			pFast = pFast->m_pNext;
		if (pFast != pSlow)
			pSlow = pSlow->m_pNext;
	} while (pFast->m_pNext != NULL && pFast != pSlow);


	return pFast == pSlow;
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
	ConnectListNodes(pNode5, pNode1);

	std::cout << (IsCircularList(pNode1) ? "�ǻ�������" : "���ǻ�������") << std::endl;


	//DestroyList(pNode1);
}

void Test2()
{
	printf("=====Test2 starts:=====\n");
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

	std::cout << (IsCircularList(pNode1) ? "�ǻ�������" : "���ǻ�������") << std::endl;

	DestroyList(pNode1);
}


// ���Կ�����
void Test4()
{
	std::cout << (IsCircularList(NULL) ? "�ǻ�������" : "���ǻ�������") << std::endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	Test1();
	Test2();
	Test4();
	return 0;
}

