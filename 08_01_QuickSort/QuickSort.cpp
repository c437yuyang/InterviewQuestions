#include <iostream>
#include <random>
#include <algorithm>
using namespace std;

inline int randomInRange(int m, int n)
{
	return rand() % (n - m + 1) + m;
}


int partition(int *arr, int n, int start, int end)
{
	int index = randomInRange(start, end);

	std::swap(arr[index], arr[end]); //主元换到最后去
	int small = start - 1; //小于主元的数的最后一个的位置

	for (int i = start; i < end; ++i)
	{
		if (arr[i] <= arr[end])
		{
			++small;
			std::swap(arr[small], arr[i]);
		}

	}

	std::swap(arr[small + 1], arr[end]);
	return small + 1;
}

void process(int *arr, int n, int start, int end)
{
	if (start == end)
		return;

	int index = partition(arr, n, start, end);

	if (index > start)
		process(arr, n, start, index - 1);
	if (index < end)
		process(arr, n, index + 1, end);

}

void quickSort(int *arr, int n)
{
	process(arr, n, 0, n - 1);
}



int main()
{
	int a[10] = { 3, 2, 4, 1, 6, 9, 8, 7, 5, 0 };

	quickSort(a, 10);

	for_each(a, a + 10, [](int val) {cout << val << " "; });
	cout << endl;

	system("pause");
	return 0;
}