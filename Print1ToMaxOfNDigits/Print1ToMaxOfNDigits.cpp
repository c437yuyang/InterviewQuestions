// Print1ToMaxOfNDigits.cpp : Defines the entry point for the console application.
//

// 《剑指Offer——名企面试官精讲典型编程题》代码
// 著作权所有者：何海涛

#include "stdafx.h"
#include <memory>

void PrintNumber(char* number);
bool Increment(char* number);
void Print1ToMaxOfNDigitsRecursively(char* number, int length, int index);

// ====================方法一====================
void Print1ToMaxOfNDigits_1(int n)
{
	if (n <= 0)
		return;

	char *number = new char[n + 1];
	memset(number, '0', n);
	number[n] = '\0';

	while (!Increment(number))
	{
		PrintNumber(number);
	}

	delete[]number;
}

// 字符串number表示一个数字，在 number上增加1
// 如果做加法溢出，则返回true；否则为false
bool Increment(char* number)
{
	bool isOverflow = false;
	int nTakeOver = 0;
	int nLength = strlen(number);

	for (int i = nLength - 1; i >= 0; i--)
	{
		int nSum = number[i] - '0' + nTakeOver; //等于当前位+进位
		if (i == nLength - 1)
			nSum++; //执行加一

		if (nSum >= 10) //如果大于10了(其实和加不加一没多大关系)
		{
			if (i == 0)//第一位都大于了10，那么就溢出了
				isOverflow = true;
			else
			{
				nSum -= 10; //减去10，剩下一个不到10的部分
				nTakeOver = 1; //进位是1
				number[i] = '0' + nSum; //给这一位赋字符值
			}
		}
		else
		{
			number[i] = '0' + nSum; //如果没有进位就直接就是当前位加一了
			break;
		}
	}

	return isOverflow;
}

// ====================方法二====================
//void Print1ToMaxOfNDigits_2(int n)
//{
//    if(n <= 0)
//        return;
// 
//    char* number = new char[n + 1];
//    number[n] = '\0';
// 
//    for(int i = 0; i < 10; ++i)
//    {
//        number[0] = i + '0';
//        Print1ToMaxOfNDigitsRecursively(number, n, 0);
//    }
// 
//    delete[] number;
//}
// 
//void Print1ToMaxOfNDigitsRecursively(char* number, int length, int index)
//{
//    if(index == length - 1)
//    {
//        PrintNumber(number);
//        return;
//    }
// 
//    for(int i = 0; i < 10; ++i)
//    {
//        number[index + 1] = i + '0';
//        Print1ToMaxOfNDigitsRecursively(number, length, index + 1);
//    }
//}

#pragma region MyOwn

void Print1ToMaxOfNDigits_2(int n)
{
	if (n <= 0)
		return;

	char *number = new char[n + 1];
	memset(number, '0', n + 1);
	number[n] = '\0';

	Print1ToMaxOfNDigitsRecursively(number, n, -1); //我这样写会清晰一点其实，不会循环里再去调用递归，看着太复杂
}

void Print1ToMaxOfNDigitsRecursively(char* number, int length, int index)
{
	if (index == length - 1)
	{
		PrintNumber(number);
		return;
	}

	for (int i = 0; i != 10; ++i)
	{
		number[index + 1] = '0' + i;
		Print1ToMaxOfNDigitsRecursively(number, length, index + 1);
	}
}

#pragma endregion


// ====================公共函数====================
// 字符串number表示一个数字，数字有若干个0开头
// 打印出这个数字，并忽略开头的0
void PrintNumber(char* number)
{
	bool isBeginning0 = true;
	int nLength = strlen(number);

	for (int i = 0; i < nLength; ++i)
	{
		if (isBeginning0 && number[i] != '0')
			isBeginning0 = false;

		if (!isBeginning0)
		{
			printf("%c", number[i]);
		}
	}

	printf("\t");
}

// ====================测试代码====================
void Test(int n)
{
	printf("Test for %d begins:\n", n);

	Print1ToMaxOfNDigits_1(n);
	Print1ToMaxOfNDigits_2(n);

	printf("Test for %d ends.\n", n);
}

int _tmain(int argc, _TCHAR* argv[])
{
	Test(1);
	Test(2);
	Test(3);
	Test(0);
	Test(-1);

	return 0;
}

