#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

inline int randomInRange(int m, int n)
{
	return rand() % (n - m + 1) + m;
}


//假设范围在0-99
void SortAges(int *arr, int n)
{
	if (arr == NULL || n <= 0)
		return;
	int range = 100;
	vector<int> bin(range, 0);
	for (int i = 0; i != n; ++i)
	{
		if (arr[i] < 0 || arr[i] > range - 1)
			throw new std::exception("age out of range.");
		++bin[arr[i]];
	}

	int j = 0;
	for (int i = 0; i != n; ++i)
	{
		while (bin[j] == 0)
		{
			++j;
		}
		arr[i] = j;
		--bin[j];
	}


	//这样是书上的做法
	//int index = 0;
	//for (int i = 0; i <= range-1; ++i)
	//{
	//	for (int j = 0; j < bin[i]; ++j)
	//	{
	//		arr[index] = i;
	//		++index;
	//	}
	//}

}

int main()
{
	const int n = 200;
	int arr[n] = { 0 };
	for (int i = 0; i != n; ++i)
	{
		arr[i] = randomInRange(0, 99);
	}

	SortAges(arr, n);

	system("pause");
	return 0;
}