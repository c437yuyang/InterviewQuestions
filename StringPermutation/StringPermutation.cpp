// StringPermutation.cpp : Defines the entry point for the console application.
//

// ����ָOffer�����������Թپ������ͱ���⡷����
// ����Ȩ�����ߣ��κ���

#include "stdafx.h"
#include <string>
#include <iostream>


#pragma region MyOwn
void Permutation(std::string str, int idx);
void Permutation(char* pStr)
{
	if (pStr == nullptr || strlen(pStr) <= 0)
		return;
	Permutation(std::string(pStr), 0);
}

void Permutation(std::string str, int idx)
{
	if (idx == str.length() - 1)
	{
		std::cout << str << std::endl;
		return;
	}
	for (int i = idx; i <= str.length() - 1; i++) //���������������������Ҳ���ڣ�������û���
	{
		std::swap(str[i], str[idx]);
		Permutation(str, idx + 1);
		std::swap(str[i], str[idx]);
	}
}

#pragma region ������Ŀ�������



#pragma endregion

//����ģ�������������abc,ac���Ҳ���,ʵ���ϴ�Ļ������ס���

void Combination(std::string str, int startIdx, int length);
void Combination(char* pStr)
{
	if (pStr == nullptr || strlen(pStr) <= 0)
		return;
	for (int i = 1; i <= strlen(pStr); ++i) //ÿ�ֳ��ȵ����
	{
		Combination(std::string(pStr), 0, i);
	}

}
void Combination(std::string str, int startIdx, int length)
{
	if ((str.length() - startIdx) < length) //���Ȳ����ˣ�����
		return;
	if (startIdx == str.length() - 1)
	{
		std::string out(str.c_str() + str.length()- length, str.c_str() + str.length());
		std::cout << out << std::endl;
		return;
	}
	Combination(str, startIdx + 1, length - 1); //Ҫ�˵�ǰ�ַ�
	Combination(str, startIdx + 1, length); //��Ҫ��ǰ�ַ�
}

#pragma endregion





//void Permutation(char* pStr, char* pBegin);

//void Permutation(char* pStr)
//{
//    if(pStr == NULL)
//        return;
//
//    Permutation(pStr, pStr);
//}
//
//void Permutation(char* pStr, char* pBegin)
//{
//    if(*pBegin == '\0')
//    {
//        printf("%s\n", pStr);
//    }
//    else
//    {
//        for(char* pCh = pBegin; *pCh != '\0'; ++ pCh)
//        {
//            char temp = *pCh;
//            *pCh = *pBegin;
//            *pBegin = temp;
//
//            Permutation(pStr, pBegin + 1);
//
//            temp = *pCh;
//            *pCh = *pBegin;
//            *pBegin = temp;
//        }
//    }
//}

// ====================���Դ���====================
void Test(char* pStr)
{
	if (pStr == NULL)
		printf("Test for NULL begins:\n");
	else
		printf("Test for %s begins:\n", pStr);

	Permutation(pStr);

	printf("\n");
}

int _tmain(int argc, _TCHAR* argv[])
{
	Test(NULL);

	char string1[] = "";
	Test(string1);

	char string2[] = "a";
	Test(string2);

	char string3[] = "ab";
	Test(string3);

	char string4[] = "abc";
	Test(string4);

	Combination(string4);

	system("pause");
	return 0;
}

