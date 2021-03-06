// PrintTreeFromTopToBottom.cpp : Defines the entry point for the console application.
//

// 《剑指Offer——名企面试官精讲典型编程题》代码
// 著作权所有者：何海涛

#include "stdafx.h"
#include "..\Utilities\BinaryTree.h"
#include <deque>
#include <queue>
#include <unordered_map>
#include <iostream>



#pragma region my own
void PrintFromTopToBottom(BinaryTreeNode* pRoot)
{
	if (pRoot == NULL)
		return;

	std::deque<BinaryTreeNode *> q;
	q.push_back(pRoot);
	while (!q.empty())
	{
		printf("%d ", q.front()->m_nValue);
		if (q.front()->m_pLeft != NULL)
			q.push_back(q.front()->m_pLeft);
		if (q.front()->m_pRight != NULL)
			q.push_back(q.front()->m_pRight);
		q.pop_front();
	}
}



#pragma region 网上找到的，按照每层的打印，但是还是没有办法显示成树的样子，只是一层换一次行
void levelOrder(BinaryTreeNode* root)
{
	if (nullptr == root)
		return;
	int curLevelCount = 1, nextLevelCount = 0; //记录当前层结点总数和下一层结点总数
	std::queue<BinaryTreeNode *> q;
	q.push(root);
	BinaryTreeNode* curPtr = nullptr;
	while (!q.empty())
	{
		curPtr = q.front();
		q.pop();
		std::cout << curPtr->m_nValue << " ";
		curLevelCount--;

		if (nullptr != curPtr->m_pLeft) //左右子节点有的话，则下一层总数加1
		{
			q.push(curPtr->m_pLeft);
			nextLevelCount++;
		}
		if (nullptr != curPtr->m_pRight) 
		{
			q.push(curPtr->m_pRight);
			nextLevelCount++;
		}
		if (0 == curLevelCount)//当前层减到了0，说明是当前层最后一个结点，那么就进行切换
		{
			endl(std::cout);
			curLevelCount = nextLevelCount;
			nextLevelCount = 0;
		}
	}
}

void InOrderGetSpaceNum(BinaryTreeNode *pRoot, std::unordered_map<BinaryTreeNode *, int> &map, int &pre_space_num)
{
	if (pRoot == NULL)
		return;

	if (pRoot->m_pLeft != NULL)
		InOrderGetSpaceNum(pRoot->m_pLeft, map, pre_space_num);
	map[pRoot] = ++pre_space_num;

	if (pRoot->m_pRight != NULL)
		InOrderGetSpaceNum(pRoot->m_pRight, map, pre_space_num);
}

int GetHeight(BinaryTreeNode* root)
{
	if (root == NULL)
		return 0;
	int left_height, right_height = 0;
	if (root->m_pLeft != NULL)
		left_height = GetHeight(root->m_pLeft);
	if (root->m_pRight != NULL)
		right_height = GetHeight(root->m_pRight);
	return std::max(left_height, right_height) + 1;
}
//根据找到的层次遍历来写的类似于真实打印的方法，但是还有问题。
void RealPrintTree(BinaryTreeNode* root)
{
	if (nullptr == root)
		return;

	std::unordered_map<BinaryTreeNode *, int> space_num_table;
	//中序遍历获取每个结点的空格数量
	int space_num = 0;
	InOrderGetSpaceNum(root, space_num_table, space_num);
	int total_height = GetHeight(root);

	int curLevelCount = 1, nextLevelCount = 0; //记录当前层结点总数和下一层结点总数
	std::queue<BinaryTreeNode *> q;
	q.push(root);
	BinaryTreeNode* curPtr = nullptr;
	int height = 1;
	bool last_layer_first = true;
	while (!q.empty())
	{
		curPtr = q.front();
		q.pop();
		if (nextLevelCount == 0 && last_layer_first) //当前层第一个结点
		{
			if (height == total_height)
				last_layer_first = false;
			for (int i = 0; i != space_num_table[curPtr]; ++i)
			{
				std::cout << " ";
			}
		}
		std::cout << curPtr->m_nValue << " ";

		curLevelCount--;

		if (nullptr != curPtr->m_pLeft) //左右子节点有的话，则下一层总数加1
		{
			q.push(curPtr->m_pLeft);
			nextLevelCount++;
		}
		if (nullptr != curPtr->m_pRight)
		{
			q.push(curPtr->m_pRight);
			nextLevelCount++;
		}
		if (0 == curLevelCount)//当前层减到了0，说明是当前层最后一个结点，那么就进行切换
		{
			endl(std::cout);
			curLevelCount = nextLevelCount;
			nextLevelCount = 0;
			++height;
		}
	}
}

#pragma endregion


#pragma endregion



//void PrintFromTopToBottom(BinaryTreeNode* pRoot)
//{
//	if (pRoot == NULL)
//		return;
//
//	std::deque<BinaryTreeNode *> dequeTreeNode;
//
//	dequeTreeNode.push_back(pRoot);
//
//	while (dequeTreeNode.size())
//	{
//		BinaryTreeNode *pNode = dequeTreeNode.front();
//		dequeTreeNode.pop_front();
//
//		printf("%d ", pNode->m_nValue);
//
//		if (pNode->m_pLeft)
//			dequeTreeNode.push_back(pNode->m_pLeft);
//
//		if (pNode->m_pRight)
//			dequeTreeNode.push_back(pNode->m_pRight);
//	}
//}

// ====================测试代码====================
void Test(char* testName, BinaryTreeNode* pRoot)
{
	if (testName != NULL)
		printf("%s begins: \n", testName);

	PrintTree(pRoot);

	printf("The nodes from top to bottom, from left to right are: \n");
	PrintFromTopToBottom(pRoot);

	RealPrintTree(pRoot);
	printf("\n\n");
}

//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16
void Test1()
{
	BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode14 = CreateBinaryTreeNode(14);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
	BinaryTreeNode* pNode16 = CreateBinaryTreeNode(16);

	ConnectTreeNodes(pNode10, pNode6, pNode14);
	ConnectTreeNodes(pNode6, pNode4, pNode8);
	ConnectTreeNodes(pNode14, pNode12, pNode16);

	Test("Test1", pNode10);

	DestroyTree(pNode10);
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
void Test2()
{
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
	BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
	BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);

	ConnectTreeNodes(pNode5, pNode4, NULL);
	ConnectTreeNodes(pNode4, pNode3, NULL);
	ConnectTreeNodes(pNode3, pNode2, NULL);
	ConnectTreeNodes(pNode2, pNode1, NULL);

	Test("Test2", pNode5);

	DestroyTree(pNode5);
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
void Test3()
{
	BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
	BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
	BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);

	ConnectTreeNodes(pNode1, NULL, pNode2);
	ConnectTreeNodes(pNode2, NULL, pNode3);
	ConnectTreeNodes(pNode3, NULL, pNode4);
	ConnectTreeNodes(pNode4, NULL, pNode5);

	Test("Test3", pNode1);

	DestroyTree(pNode1);
}

// 树中只有1个结点
void Test4()
{
	BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
	Test("Test4", pNode1);

	DestroyTree(pNode1);
}

// 树中没有结点
void Test5()
{
	Test("Test5", NULL);
}

int _tmain(int argc, _TCHAR* argv[])
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	system("pause");
	return 0;
}

