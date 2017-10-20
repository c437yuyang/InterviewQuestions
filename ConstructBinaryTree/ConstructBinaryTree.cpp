// ConstructBinaryTree.cpp : Defines the entry point for the console application.
//

// ����ָOffer�����������Թپ������ͱ���⡷����
// ����Ȩ�����ߣ��κ���

#include "stdafx.h"
#include "..\Utilities\BinaryTree.h"
#include <exception>




#pragma region MY,�ܹ��������������ǵ�������Ч��ʱ��û�����(�ܼ�⣬����û������Ϊ���Ӷ�̫�ߣ���ÿ�ο����������������ĳ�Ա�Ƿ�ȫ����ͬ)
//BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder);
//BinaryTreeNode* Construct(int* preorder, int* inorder, int length)
//{
//	if (length <= 0 || preorder == NULL || inorder == NULL)
//		return NULL;
//
//	BinaryTreeNode *root = ConstructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
//	return root;
//}
//
//
//BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder)
//{
//	BinaryTreeNode * root = new BinaryTreeNode();
//	root->m_nValue = *startPreorder;
//  root->m_pLeft = root->m_pRight = NULL; //��ΪNULL�����ɺ�ϰ��
//	//ȷ���ݹ��ӽ��̵ķ�Χ
//	//���ҵ����ڵ���inorder�е�λ��
//	int *p = startInorder;
//	for (; *p != *startPreorder; ++p);
//
//	if (p - startInorder > 0) //p-startInorder��������������Ŀ
//		root->m_pLeft = ConstructCore(startPreorder + 1, startPreorder + (p - startInorder), startInorder, p - 1);
//	
//	if (endInorder - p > 0) //endInorder - p��������������Ŀ
//		root->m_pRight = ConstructCore(startPreorder + (p - startInorder) + 1, endPreorder, p + 1, endInorder);
//
//	return root;
//}


#pragma endregion



#pragma region Origin
BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder);
BinaryTreeNode* Construct(int* preorder, int* inorder, int length)
{
	if (preorder == NULL || inorder == NULL || length <= 0)
		return NULL;

	return ConstructCore(preorder, preorder + length - 1,
		inorder, inorder + length - 1);
}

BinaryTreeNode* ConstructCore
(
	int* startPreorder, int* endPreorder,
	int* startInorder, int* endInorder
)
{
	// ǰ��������еĵ�һ�������Ǹ�����ֵ
	int rootValue = startPreorder[0];
	BinaryTreeNode* root = new BinaryTreeNode();
	root->m_nValue = rootValue;
	root->m_pLeft = root->m_pRight = NULL;

	if (startPreorder == endPreorder) //ֻ��һ������
	{
		if (startInorder == endInorder && *startPreorder == *startInorder) //��������Ƿ�Ҳֻ��һ�������������ǰ�����������ȣ����������Ч����
			return root;
		else
			throw std::exception("Invalid input.");
	}

	// ������������ҵ�������ֵ
	int* rootInorder = startInorder;
	while (rootInorder <= endInorder && *rootInorder != rootValue) //���Կ�������д��ȷʵ��ȫ�濼�ǵ�
		++rootInorder;

	if (rootInorder == endInorder && *rootInorder != rootValue) //�ߵ������˵���϶���ֹһ�����ˣ��������rootInorder==endInorder˵��������Ч����
		throw std::exception("Invalid input.");

	int leftLength = rootInorder - startInorder;
	int* leftPreorderEnd = startPreorder + leftLength;
	if (leftLength > 0)
	{
		// ����������
		root->m_pLeft = ConstructCore(startPreorder + 1, leftPreorderEnd,
			startInorder, rootInorder - 1);
	}
	if (leftLength < endPreorder - startPreorder)
	{
		// ����������
		root->m_pRight = ConstructCore(leftPreorderEnd + 1, endPreorder,
			rootInorder + 1, endInorder);
	}

	return root;
}
#pragma endregion


// ====================���Դ���====================
void Test(char* testName, int* preorder, int* inorder, int length)
{
	if (testName != NULL)
		printf("%s begins:\n", testName);

	printf("The preorder sequence is: ");
	for (int i = 0; i < length; ++i)
		printf("%d ", preorder[i]);
	printf("\n");

	printf("The inorder sequence is: ");
	for (int i = 0; i < length; ++i)
		printf("%d ", inorder[i]);
	printf("\n");

	try
	{
		BinaryTreeNode* root = Construct(preorder, inorder, length);
		PrintTree(root);

		DestroyTree(root);
	}
	catch (std::exception& exception)
	{
		printf("Invalid Input.\n");
	}
}

// ��ͨ������
//              1
//           /     \
//          2       3  
//         /       / \
//        4       5   6
//         \         /
//          7       8
void Test1()
{
	const int length = 8;
	int preorder[length] = { 1, 2, 4, 7, 3, 5, 6, 8 };
	int inorder[length] = { 4, 7, 2, 1, 5, 3, 8, 6 };

	Test("Test1", preorder, inorder, length);
}

// ���н�㶼û�����ӽ��
//            1
//           / 
//          2   
//         / 
//        3 
//       /
//      4
//     /
//    5
void Test2()
{
	const int length = 5;
	int preorder[length] = { 1, 2, 3, 4, 5 };
	int inorder[length] = { 5, 4, 3, 2, 1 };

	Test("Test2", preorder, inorder, length);
}

// ���н�㶼û�����ӽ��
//            1
//             \ 
//              2   
//               \ 
//                3 
//                 \
//                  4
//                   \
//                    5
void Test3()
{
	const int length = 5;
	int preorder[length] = { 1, 2, 3, 4, 5 };
	int inorder[length] = { 1, 2, 3, 4, 5 };

	Test("Test3", preorder, inorder, length);
}

// ����ֻ��һ�����
void Test4()
{
	const int length = 1;
	int preorder[length] = { 1 };
	int inorder[length] = { 1 };

	Test("Test4", preorder, inorder, length);
}

// ��ȫ������
//              1
//           /     \
//          2       3  
//         / \     / \
//        4   5   6   7
void Test5()
{
	const int length = 7;
	int preorder[length] = { 1, 2, 4, 5, 3, 6, 7 };
	int inorder[length] = { 4, 2, 5, 1, 6, 3, 7 };

	Test("Test5", preorder, inorder, length);
}

// �����ָ��
void Test6()
{
	Test("Test6", NULL, NULL, 0);
}

// ������������в�ƥ��
void Test7()
{
	const int length = 7;
	int preorder[length] = { 1, 2, 4, 5, 3, 6, 7 };
	int inorder[length] = { 4, 2, 8, 1, 6, 3, 7 };

	Test("Test7: for unmatched input", preorder, inorder, length);
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

	return 0;
}

