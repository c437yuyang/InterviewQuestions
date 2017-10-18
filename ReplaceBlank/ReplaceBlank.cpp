// ReplaceBlank.cpp : Defines the entry point for the console application.
//

// 《剑指Offer——名企面试官精讲典型编程题》代码
// 著作权所有者：何海涛

#include "stdafx.h"
#include <string>

///*length 为字符数组string的总容量*/
//void ReplaceBlank(char string[], int length)
//{
//    if(string == NULL && length <= 0)
//        return;
//
//    /*originalLength 为字符串string的实际长度*/
//    int originalLength = 0;
//    int numberOfBlank = 0;
//    int i = 0;
//    while(string[i] != '\0')
//    {
//        ++ originalLength;
//
//        if(string[i] == ' ')
//            ++ numberOfBlank;
//
//        ++ i;
//    }
//
//    /*newLength 为把空格替换成'%20'之后的长度*/
//    int newLength = originalLength + numberOfBlank * 2;
//    if(newLength > length)
//        return;
//
//    int indexOfOriginal = originalLength;
//    int indexOfNew = newLength;
//    while(indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
//    {
//        if(string[indexOfOriginal] == ' ')
//        {
//            string[indexOfNew --] = '0';
//            string[indexOfNew --] = '2';
//            string[indexOfNew --] = '%';
//        }
//        else
//        {
//            string[indexOfNew --] = string[indexOfOriginal];
//        }
//
//        -- indexOfOriginal;
//    }
//}


#pragma region My
//方法1，暴力方法，O(n^2)
//void ReplaceBlank(char string[], int length)  //length是数组的最大容量
//{
//	if (string == NULL)
//		return;
//	int originlength = 0;
//	for (int i = 0; string[i] != '\0'; ++i)
//		++originlength;
//
//	for (int i = 0; string[i] != '\0'; ++i)
//	{
//		if (string[i] == ' ')
//		{
//			originlength += 2;
//			if (originlength > length) //超出容量范围直接返回
//				return;
//			//从尾部向前面依次移动
//			string[originlength] = '\0'; //先把尾部置为'\0'
//			for (int j = originlength - 1; j != i + 2; --j)
//			{
//				string[j] = string[j - 2];
//			}
//			//最后再赋值指定位
//			string[i] = '%';
//			string[++i] = '2';
//			string[++i] = '0';
//		}
//	}
//}

//方法2:O(n),先遍历一遍得到最终长度，然后再从后往前拷贝替换
void ReplaceBlank(char string[], int length)  //length是数组的最大容量
{
	if (string == NULL)
		return;
	int originlength = 0;
	int newLength = 0;
	for (int i = 0; string[i] != '\0'; ++i) {
		++originlength;
		++newLength;
		if (string[i] == ' ')
			newLength += 2;
	}
	if (newLength > length)
		return;

	string[newLength] = '\0';
	int j = originlength - 1;
	for (int i = newLength - 1; i >= 0;)
	{
		if (string[j] == ' ')
		{
			string[i] = '0';
			string[i - 1] = '2';
			string[i - 2] = '%';
			i -= 3;
			j -= 1;
		}
		else
		{
			string[i--] = string[j--];
		}
	}

}
#pragma endregion


void Test(char* testName, char string[], int length, char expected[])
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    ReplaceBlank(string, length);

    if(expected == NULL && string == NULL)
        printf("passed.\n");
    else if(expected == NULL && string != NULL)
        printf("failed.\n");
    else if(strcmp(string, expected) == 0)
        printf("passed.\n");
    else
        printf("failed.\n");
}

// 空格在句子中间
void Test1()
{
    const int length = 100;

    char string[length] = "hello world";
    Test("Test1", string, length, "hello%20world");
}

// 空格在句子开头
void Test2()
{
    const int length = 100;

    char string[length] = " helloworld";
    Test("Test2", string, length, "%20helloworld");
}

// 空格在句子末尾
void Test3()
{
    const int length = 100;

    char string[length] = "helloworld ";
    Test("Test3", string, length, "helloworld%20");
}

// 连续有两个空格
void Test4()
{
    const int length = 100;

    char string[length] = "hello  world";
    Test("Test4", string, length, "hello%20%20world");
}

// 传入NULL
void Test5()
{
    Test("Test5", NULL, 0, NULL);
}

// 传入内容为空的字符串
void Test6()
{
    const int length = 100;

    char string[length] = "";
    Test("Test6", string, length, "");
}

//传入内容为一个空格的字符串
void Test7()
{
    const int length = 100;

    char string[length] = " ";
    Test("Test7", string, length, "%20");
}

// 传入的字符串没有空格
void Test8()
{
    const int length = 100;

    char string[length] = "helloworld";
    Test("Test8", string, length, "helloworld");
}

// 传入的字符串全是空格
void Test9()
{
    const int length = 100;

    char string[length] = "   ";
    Test("Test9", string, length, "%20%20%20");
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
    Test9();
	system("pause");

    return 0;
}

