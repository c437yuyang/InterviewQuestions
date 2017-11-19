// NumberOf1InBinary.cpp : Defines the entry point for the console application.
//

// 《剑指Offer——名企面试官精讲典型编程题》代码
// 著作权所有者：何海涛

#include "stdafx.h"

//可能引起死循环的解法,当输入负数的时候，n右移是补符号位
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

//所以改为左移flag来避免上面的问题
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


//附加题目:
//1.一条语句判断一个整数是不是2的整数次方
//如果是2的整数次方，那么这个数的二进制中只有1个1
//那么这个数与上自己-1就会变成0
bool isPowerOf2(int num)
{
	return num&(num - 1) == 0;
}

//2.两个整数，判断需要改变m的二进制位中的多少位才能得到n
int ChangeM2N(int m, int n)
{
	int tmp = m^n; //异或
	return NumberOf1_Solution2(tmp); //返回异或结果中1的个数
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
	// 输入0，期待的输出是0
	Test(0, 0);

	// 输入1，期待的输出是1
	Test(1, 1);

	// 输入10，期待的输出是2
	Test(10, 2);

	// 输入0x7FFFFFFF，期待的输出是31
	Test(0x7FFFFFFF, 31);

	// 输入0xFFFFFFFF（负数），期待的输出是32
	Test(0xFFFFFFFF, 32);

	// 输入0x80000000（负数），期待的输出是1
	Test(0x80000000, 1);

	return 0;
}

