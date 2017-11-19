// MinInStack.cpp : Defines the entry point for the console application.
//

// 《剑指Offer——名企面试官精讲典型编程题》代码
// 著作权所有者：何海涛

#include "stdafx.h"
#include "..\MinInStack\StackWithMin.h"
//左程云的书上的版本(01_01_GetMinStack)的解法更优，其实就是每次压入辅助栈的时候，再判断一下，到底需不需要压入，如果最小值需要刷新才压入，弹出的时候也做相应的操作
void Test(char* testName, const StackWithMin<int>& stack, int expected)
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    if(stack.min() == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

int _tmain(int argc, _TCHAR* argv[])
{
    StackWithMin<int> stack;

    stack.push(3);
    Test("Test1", stack, 3);

    stack.push(4);
    Test("Test2", stack, 3);

    stack.push(2);
    Test("Test3", stack, 2);

    stack.push(3);
    Test("Test4", stack, 2);

    stack.pop();
    Test("Test5", stack, 2);

    stack.pop();
    Test("Test6", stack, 3);

    stack.pop();
    Test("Test7", stack, 3);

    stack.push(0);
    Test("Test8", stack, 0);

    return 0;
}

