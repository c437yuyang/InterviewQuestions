// SquenceOfBST.cpp : Defines the entry point for the console application.
//

// 《剑指Offer——名企面试官精讲典型编程题》代码
// 著作权所有者：何海涛

#include "stdafx.h"
#include <iostream>

#pragma region MyRegion
//总的来说思路就是，找到根节点，然后找到第一个比它大的节点来划分左右子树，这时如果右子树中还有比根节点小的树，就不是二叉搜索树了，否则就继续遍历这棵树的左右子树再进行判断
bool VerifySquenceOfBST(int sequence[], int length)
{
	if (sequence == nullptr || length <= 0)
		return false;
	if (length == 1)
		return true;

	int last = sequence[length - 1];
	int first_gt = -1;
	bool findfirst = false;
	for (int i = 0; i <= length - 2; ++i)
	{
		if (!findfirst &&sequence[i] > last)
		{
			first_gt = i;
			findfirst = true;
		}

		if (findfirst && sequence[i] < last)
			return false;
	}

	if (first_gt == 0) //只有右子树
		return VerifySquenceOfBST(sequence, length - 1);
	if (first_gt == -1)//只有左子树
		return VerifySquenceOfBST(sequence, length - 1);
	else
		return VerifySquenceOfBST(sequence + first_gt, length - 1 - first_gt)
		&& VerifySquenceOfBST(sequence, first_gt);

}

//补充题目:判断是否是前序遍历的序列
bool VerifySquenceOfBSTPreOrder(int sequence[], int length)
{
	if (sequence == nullptr || length <= 0)
		return false;
	if (length == 1)
		return true;

	int first = sequence[0];
	int first_gt = -1;
	bool findfirst = false;
	for (int i = 1; i <= length - 1; ++i)
	{
		if (!findfirst &&sequence[i] > first)
		{
			first_gt = i;
			findfirst = true;
		}

		if (findfirst && sequence[i] < first) //找到的右子树里面有比根节点小的，返回false
			return false;
	}

	if (first_gt == 1) //只有右子树
		return VerifySquenceOfBSTPreOrder(sequence + 1, length - 1);
	if (first_gt == -1)//只有左子树
		return VerifySquenceOfBSTPreOrder(sequence + 1, length - 1);
	else //判断左右子树是否都满足条件
		return VerifySquenceOfBSTPreOrder(sequence + 1, first_gt - 1)
		&& VerifySquenceOfBSTPreOrder(sequence + first_gt, length - first_gt);

}

#pragma endregion



// BST：Binary Search Tree，二叉搜索树
//bool VerifySquenceOfBST(int sequence[], int length)
//{
//	if (sequence == NULL || length <= 0)
//		return false;
//
//	int root = sequence[length - 1];
//
//	// 在二叉搜索树中左子树的结点小于根结点
//	int i = 0;
//	for (; i < length - 1; ++i)
//	{
//		if (sequence[i] > root)
//			break;
//	}
//
//	// 在二叉搜索树中右子树的结点大于根结点
//	int j = i;
//	for (; j < length - 1; ++j)
//	{
//		if (sequence[j] < root)
//			return false;
//	}
//
//	// 判断左子树是不是二叉搜索树
//	bool left = true;
//	if (i > 0)
//		left = VerifySquenceOfBST(sequence, i);
//
//	// 判断右子树是不是二叉搜索树
//	bool right = true;
//	if (i < length - 1)
//		right = VerifySquenceOfBST(sequence + i, length - i - 1);
//
//	return (left && right);
//}

// ====================测试代码====================
void Test(char* testName, int sequence[], int length, bool expected)
{
	if (testName != NULL)
		printf("%s begins: ", testName);

	if (VerifySquenceOfBST(sequence, length) == expected)
		printf("passed.\n");
	else
		printf("failed.\n");
}

//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16
void Test1()
{
	int data[] = { 4, 8, 6, 12, 16, 14, 10 };
	Test("Test1", data, sizeof(data) / sizeof(int), true);
}

//           5
//          / \
//         4   7
//            /
//           6
void Test2()
{
	int data[] = { 4, 6, 7, 5 };
	Test("Test2", data, sizeof(data) / sizeof(int), true);
}

//               5
//              /
//             4
//            /
//           3
//          /
//         2
//        /
//       1
void Test3()
{
	int data[] = { 1, 2, 3, 4, 5 };
	Test("Test3", data, sizeof(data) / sizeof(int), true);
}

// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
void Test4()
{
	int data[] = { 5, 4, 3, 2, 1 };
	Test("Test4", data, sizeof(data) / sizeof(int), true);
}

// 树中只有1个结点
void Test5()
{
	int data[] = { 5 };
	Test("Test5", data, sizeof(data) / sizeof(int), true);
}

void Test6()
{
	int data[] = { 7, 4, 6, 5 };
	Test("Test6", data, sizeof(data) / sizeof(int), false);
}

void Test7()
{
	int data[] = { 4, 6, 12, 8, 16, 14, 10 };
	Test("Test7", data, sizeof(data) / sizeof(int), false);
}

void Test8()
{
	Test("Test8", NULL, 0, false);
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
	Test8();


	int data[] = { 4, 8, 6, 12, 16, 14, 10 };
	std::cout << VerifySquenceOfBSTPreOrder(data, sizeof(data) / sizeof(int)) << std::endl;

	int data1[] = { 5,3,2,4,7,6,8 };
	std::cout << VerifySquenceOfBSTPreOrder(data1, sizeof(data1) / sizeof(int)) << std::endl;

	system("pause");
	return 0;
}

