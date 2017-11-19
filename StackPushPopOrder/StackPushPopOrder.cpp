// StackPushPopOrder.cpp : Defines the entry point for the console application.
//

// ����ָOffer�����������Թپ������ͱ���⡷����
// ����Ȩ�����ߣ��κ���

#include "stdafx.h"
#include <stack>
using std::stack;

#pragma region �Լ��İ汾
bool IsPopOrder(const int* pPush, const int* pPop, int nLength)
{
	if (pPush == NULL || pPop == NULL || nLength <= 0)
		return false;
	stack<int> s;
	int s1Idx = 0, s2Idx = 0;
	while (s1Idx != nLength || s2Idx != nLength) //ֹͣ����
	{
		if (s1Idx == nLength && s.top() != pPop[s2Idx]) //����ܹ�ѹ���ȫ��ѹ���ˣ�����ȴ������ջ�������Ǵ����
			break;
		while ((s1Idx != nLength) && (s.empty() || s.top() != pPop[s2Idx])) //�����û���ҵ����������е����������ѹ��
		{
			s.push(pPush[s1Idx]);
			++s1Idx;
		}
		while (!s.empty() && s.top() == pPop[s2Idx]) //�����������������������ȣ����������
		{
			s.pop();
			++s2Idx;
		}
	}
	return s2Idx == nLength ? true : false; //����ܹ����꣬������ȷ��

}
#pragma endregion


#pragma region ���ϵİ汾
bool IsPopOrder(const int* pPush, const int* pPop, int nLength)
{
	bool bPossible = false;

	if (pPush != NULL && pPop != NULL && nLength > 0)
	{
		const int* pNextPush = pPush;
		const int* pNextPop = pPop;

		std::stack<int> stackData;

		while (pNextPop - pPop < nLength)
		{
			// ������ջ��ջ��Ԫ�ز���Ҫ������Ԫ��
			// ��ѹ��һЩ������ջ
			while (stackData.empty() || stackData.top() != *pNextPop)
			{
				// ����������ֶ�ѹ�븨��ջ�ˣ��˳�ѭ��
				if (pNextPush - pPush == nLength)
					break;

				stackData.push(*pNextPush);

				pNextPush++;
			}

			if (stackData.top() != *pNextPop)
				break;

			stackData.pop();
			pNextPop++;
		}

		if (stackData.empty() && pNextPop - pPop == nLength)
			bPossible = true;
	}

	return bPossible;
}
#pragma endregion


// ====================���Դ���====================
void Test(char* testName, const int* pPush, const int* pPop, int nLength, bool expected)
{
	if (testName != NULL)
		printf("%s begins: ", testName);

	if (IsPopOrder(pPush, pPop, nLength) == expected)
		printf("Passed.\n");
	else
		printf("failed.\n");
}

void Test1()
{
	const int nLength = 5;
	int push[nLength] = { 1, 2, 3, 4, 5 };
	int pop[nLength] = { 4, 5, 3, 2, 1 };

	Test("Test1", push, pop, nLength, true);
}

void Test2()
{
	const int nLength = 5;
	int push[nLength] = { 1, 2, 3, 4, 5 };
	int pop[nLength] = { 3, 5, 4, 2, 1 };

	Test("Test2", push, pop, nLength, true);
}

void Test3()
{
	const int nLength = 5;
	int push[nLength] = { 1, 2, 3, 4, 5 };
	int pop[nLength] = { 4, 3, 5, 1, 2 };

	Test("Test3", push, pop, nLength, false);
}

void Test4()
{
	const int nLength = 5;
	int push[nLength] = { 1, 2, 3, 4, 5 };
	int pop[nLength] = { 3, 5, 4, 1, 2 };

	Test("Test4", push, pop, nLength, false);
}

// push��pop����ֻ��һ������
void Test5()
{
	const int nLength = 1;
	int push[nLength] = { 1 };
	int pop[nLength] = { 2 };

	Test("Test5", push, pop, nLength, false);
}

void Test6()
{
	const int nLength = 1;
	int push[nLength] = { 1 };
	int pop[nLength] = { 1 };

	Test("Test6", push, pop, nLength, true);
}

void Test7()
{
	Test("Test7", NULL, NULL, 0, false);
}

int _tmain(int argc, _TCHAR* argv[])
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();
	Test7();
	system("pause");
	return 0;
}

