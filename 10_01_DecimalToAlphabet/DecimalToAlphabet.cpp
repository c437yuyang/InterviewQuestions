#include <iostream>
#include <string>
using namespace std;

string DecimalToAlphabet(int num)
{
	string str = "";
	while (num != 0)
	{
		int rem = num % 26;
		num /= 26;
		str.insert(str.begin(), static_cast<char>('A' + rem - 1));
	}
	return str;
}


int main()
{
	cout << DecimalToAlphabet(28) << endl;
	cout << DecimalToAlphabet(33) << endl;
	cout << DecimalToAlphabet(44) << endl;
	cout << DecimalToAlphabet(55) << endl;
	cout << DecimalToAlphabet(555) << endl;



	system("pause");
}