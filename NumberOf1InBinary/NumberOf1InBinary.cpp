// NumberOf1InBinary.cpp : Defines the entry point for the console application.
//

// ����ָOffer�����������Թپ������ͱ���⡷����
// ����Ȩ�����ߣ��κ���

#include "stdafx.h"

//����������ѭ���Ľⷨ,�����븺����ʱ��n�����ǲ�����λ
int NumberOf1_Solution0(int n)
{
	int res = 0;
	while (n)
	{
		if (n & 1)
			++res;
		n >>= 1;
	}
	return res;
}

//���Ը�Ϊ����flag���������������
int NumberOf1_Solution1(int n)
{
	int count = 0;
	unsigned int flag = 1;
	while (flag)
	{
		if (n & flag)
			count++;

		flag = flag << 1;
	}

	return count;
}

int NumberOf1_Solution2(int n)
{
	int count = 0;

	while (n)
	{
		++count;
		n = (n - 1) & n;
	}

	return count;
}


//������Ŀ:
//1.һ������ж�һ�������ǲ���2�������η�
//�����2�������η�����ô������Ķ�������ֻ��1��1
//��ô����������Լ�-1�ͻ���0
bool isPowerOf2(int num)
{
	return num&(num - 1) == 0;
}

//2.�����������ж���Ҫ�ı�m�Ķ�����λ�еĶ���λ���ܵõ�n
int ChangeM2N(int m, int n)
{
	int tmp = m^n; //���
	return NumberOf1_Solution2(tmp); //�����������1�ĸ���
}

void Test(int number, unsigned int expected)
{
	int actual = NumberOf1_Solution1(number);
	if (actual == expected)
		printf("Solution1: Test for %p passed.\n", number);
	else
		printf("Solution1: Test for %p failed.\n", number);

	actual = NumberOf1_Solution2(number);
	if (actual == expected)
		printf("Solution2: Test for %p passed.\n", number);
	else
		printf("Solution2: Test for %p failed.\n", number);

	printf("\n");
}

int _tmain(int argc, _TCHAR* argv[])
{
	// ����0���ڴ��������0
	Test(0, 0);

	// ����1���ڴ��������1
	Test(1, 1);

	// ����10���ڴ��������2
	Test(10, 2);

	// ����0x7FFFFFFF���ڴ��������31
	Test(0x7FFFFFFF, 31);

	// ����0xFFFFFFFF�����������ڴ��������32
	Test(0xFFFFFFFF, 32);

	// ����0x80000000�����������ڴ��������1
	Test(0x80000000, 1);

	return 0;
}

