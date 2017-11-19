// KthNodeFromEnd.cpp : Defines the entry point for the console application.
//

// ����ָOffer�����������Թپ������ͱ���⡷����
// ����Ȩ�����ߣ��κ���

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
//��򵥵Ľⷨ���ȱ���һ����ýڵ���Ŀ
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

	//if (n - k < 0) //�����ڵ�����k��,���ﲻ����n-kС��0���޷�����������������Ǵ��
	//	return NULL;
	if (n < k)
		return NULL; //Ӧ������

	//��ͷ��㿪ʼ�ĵ�n-k+1���ڵ���ҵ��˵�����k���ڵ�
	pNode = pListHead;
	for (unsigned int i = 0; i < n - k; ++i)
	{
		pNode = pNode->m_pNext;
	}
	return pNode;
}

//��ȷ��˫ָ�뷨
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
	if (i < k - 1) return NULL; //��ǰk���ڵ�(����k-1������������k���ڵ�)��û�У������ܴ��ڵ�����k��
	pSecond = pListHead;
	while (pFisrt->m_pNext != NULL)
	{
		pFisrt = pFisrt->m_pNext;
		pSecond = pSecond->m_pNext;
	}
	return pSecond;
}
#pragma endregion


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

	printf("expected result: 4.\n");
	ListNode* pNode = FindKthToTail(pNode1, 2);
	PrintListNode(pNode);

	DestroyList(pNode1);
}

// ����Ҫ�ҵĽ���������β���
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

// ����Ҫ�ҵĽ���������ͷ���
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

// ���Կ�����
void Test4()
{
	printf("=====Test4 starts:=====\n");
	printf("expected result: NULL.\n");
	ListNode* pNode = FindKthToTail(NULL, 100);
	PrintListNode(pNode);
}

// ��������ĵڶ���������������Ľ������
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

// ��������ĵڶ�������Ϊ0
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

