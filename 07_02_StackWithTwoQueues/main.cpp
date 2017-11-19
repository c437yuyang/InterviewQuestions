#include "Stack.h"
#include <iostream>
using namespace std;

int main() 
{
	CStack<int> s;

	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	s.push(5);
	s.push(6);
	cout << s.pop() << endl;
	cout << s.pop() << endl;
 	system("pause");
	return 0;
}