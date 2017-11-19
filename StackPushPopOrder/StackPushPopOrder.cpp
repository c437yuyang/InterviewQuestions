// StackPushPopOrder.cpp : Defines the entry point for the console application.
//

// 《剑指Offer——名企面试官精讲典型编程题》代码
// 著作权所有者：何海涛

#include "stdafx.h"
#include <stack>
using std::stack;

#pragma region 自己的版本
bool IsPopOrder(const int* pPush, const int* pPop, int nLength)
{
	if (pPush == NULL || pPop == NULL || nLength <= 0)
		return false;
	stack<int> s;
	int s1Idx = 0, s2Idx = 0;
	while (s1Idx != nLength || s2Idx != nLength) //停止条件
	{
		if (s1Idx == nLength && s.top() != pPop[s2Idx]) //如果能够压入的全部压入了，弹出却不等于栈顶，则是错误的
			break;
		while ((s1Idx != nLength) && (s.empty() || s.top() != pPop[s2Idx])) //如果还没有找到弹出序列中的数，则继续压入
		{
			s.push(pPush[s1Idx]);
			++s1Idx;
		}
		while (!s.empty() && s.top() == pPop[s2Idx]) //如果弹出序列与推入序列相等，则继续弹出
		{
			s.pop();
			++s2Idx;
		}
	}
	return s2Idx == nLength ? true : false; //如果能够走完，则是正确的

}
#pragma endregion


#pragma region 书上的版本
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
			// 当辅助栈的栈顶元素不是要弹出的元素
			// 先压入一些数字入栈
			while (stackData.empty() || stackData.top() != *pNextPop)
			{
				// 如果所有数字都压入辅助栈了，退出循环
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


// ====================测试代码====================
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

// push和pop序列只有一个数字
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

