// MoreThanHalfNumber.cpp : Defines the entry point for the console application.
//

// 《剑指Offer——名企面试官精讲典型编程题》代码
// 著作权所有者：何海涛

#include "stdafx.h"
#include "..\Utilities\Array.h"


bool g_bInputInvalid = false;
bool CheckInvalidArray(int* numbers, int length)
{
	g_bInputInvalid = false;
	if (numbers == NULL && length <= 0)
		g_bInputInvalid = true;

	return g_bInputInvalid;
}

bool CheckMoreThanHalf(int* numbers, int length, int number)
{
	int times = 0;
	for (int i = 0; i < length; ++i)
	{
		if (numbers[i] == number)
			times++;
	}

	bool isMoreThanHalf = true;
	if (times * 2 <= length)
	{
		g_bInputInvalid = true;
		isMoreThanHalf = false;
	}

	return isMoreThanHalf;
}

#pragma region MY OWN

// ====================方法1====================
// 自己的思路，弄一个hash表记录
#include <unordered_map>

int MoreThanHalfNum_Solution1(int* numbers, int length)
{
	if (numbers == NULL || length <= 0)
	{
		g_bInputInvalid = true;
		return 0;
	}
	g_bInputInvalid = false;
	std::unordered_map<int, int> hist; //这种方法时间复杂度也是O(n),只是空间复杂度是O(n)了
	for (int i = 0; i != length; ++i)
		++hist[numbers[i]];
	for (auto it = hist.begin(); it != hist.end(); ++it)
		if (it->second *1.0 / length > 0.5)
			return it->first;
	g_bInputInvalid = true;
	return 0; //没找到
}

int MoreThanHalfNum_Solution2(int* numbers, int length)
{
	if (numbers == NULL || length <= 0)
	{
		g_bInputInvalid = true;
		return NULL;
	}
	g_bInputInvalid = false;

	int candidate = numbers[0];
	int times = 1;
	for (int i = 1; i != length; ++i)
	{
		if (times != 0)
		{
			if (numbers[i] != candidate)
				times--;
			else 
				times++;
		}
		else if (times == 0)
			candidate = numbers[i];
	}

	if (CheckMoreThanHalf(numbers, length, candidate))
		return candidate;
	else
	{
		g_bInputInvalid = true;
		return NULL;
	
	}
}



#pragma endregion


// ====================方法1====================
//用Partition的思想:总的来说就是，如果是出现大于一半的数，那么排序后一定是位于中间的数字
//因此就用partition来找中位数，如果选中数下标小于n/2就在右边，以此类推。
//找到中位数后，再判断一次到底是不是大于一半的就可以了
//int MoreThanHalfNum_Solution1(int* numbers, int length)
//{
//	if (CheckInvalidArray(numbers, length))
//		return 0;
//
//	int middle = length >> 1;
//	int start = 0;
//	int end = length - 1;
//	int index = Partition(numbers, length, start, end);
//	while (index != middle)
//	{
//		if (index > middle)
//		{
//			end = index - 1;
//			index = Partition(numbers, length, start, end);
//		}
//		else
//		{
//			start = index + 1;
//			index = Partition(numbers, length, start, end);
//		}
//	}
//
//	int result = numbers[middle];
//	if (!CheckMoreThanHalf(numbers, length, result))
//		result = 0;
//
//	return result;
//}
//
//// ====================方法2====================
////方法二就和左程云的版本是一样的了
//int MoreThanHalfNum_Solution2(int* numbers, int length)
//{
//	if (CheckInvalidArray(numbers, length))
//		return 0;
//
//	int result = numbers[0];
//	int times = 1;
//	for (int i = 1; i < length; ++i)
//	{
//		if (times == 0)
//		{
//			result = numbers[i];
//			times = 1;
//		}
//		else if (numbers[i] == result)
//			times++;
//		else
//			times--;
//	}
//
//	if (!CheckMoreThanHalf(numbers, length, result))
//		result = 0;
//
//	return result;
//}

// ====================测试代码====================
void Test(char* testName, int* numbers, int length, int expectedValue, bool expectedFlag)
{
	if (testName != NULL)
		printf("%s begins: \n", testName);

	int* copy = new int[length];
	for (int i = 0; i < length; ++i)
		copy[i] = numbers[i];

	printf("Test for solution1: ");
	int result = MoreThanHalfNum_Solution1(numbers, length);
	if (result == expectedValue && g_bInputInvalid == expectedFlag)
		printf("Passed.\n");
	else
		printf("Failed.\n");

	printf("Test for solution2: ");
	result = MoreThanHalfNum_Solution2(copy, length);
	if (result == expectedValue && g_bInputInvalid == expectedFlag)
		printf("Passed.\n");
	else
		printf("Failed.\n");

	delete[] copy;
}

// 存在出现次数超过数组长度一半的数字
void Test1()
{
	int numbers[] = { 1, 2, 3, 2, 2, 2, 5, 4, 2 };
	Test("Test1", numbers, sizeof(numbers) / sizeof(int), 2, false);
}

// 不存在出现次数超过数组长度一半的数字
void Test2()
{
	int numbers[] = { 1, 2, 3, 2, 4, 2, 5, 2, 3 };
	Test("Test2", numbers, sizeof(numbers) / sizeof(int), 0, true);
}

// 出现次数超过数组长度一半的数字都出现在数组的前半部分
void Test3()
{
	int numbers[] = { 2, 2, 2, 2, 2, 1, 3, 4, 5 };
	Test("Test3", numbers, sizeof(numbers) / sizeof(int), 2, false);
}

// 出现次数超过数组长度一半的数字都出现在数组的后半部分
void Test4()
{
	int numbers[] = { 1, 3, 4, 5, 2, 2, 2, 2, 2 };
	Test("Test4", numbers, sizeof(numbers) / sizeof(int), 2, false);
}

// 输入空指针
void Test5()
{
	int numbers[] = { 1 };
	Test("Test5", numbers, 1, 1, false);
}

// 输入空指针
void Test6()
{
	Test("Test6", NULL, 0, 0, true);
}

int _tmain(int argc, _TCHAR* argv[])
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();
	system("pause");
	return 0;
}

