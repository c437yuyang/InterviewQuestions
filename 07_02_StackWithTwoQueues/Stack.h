#pragma once
#include <queue>
template <typename T>
class CStack
{
public:
	T pop();
	void push(const T&val);

private:
	std::queue<T> queue1;
	std::queue<T> queue2;
};

template <typename T>
void CStack<T>::push(const T&val)
{
	if (queue1.empty())
		queue2.push(val);
	else queue1.push(val);
}

template<typename T>
T CStack<T>::pop() 
{
	if (queue1.empty()) //´Óq2Íùq1ÒÆ¶¯ÔªËØ
	{
		while (queue2.size() > 1)
		{
			queue1.push(queue2.front());
			queue2.pop();
		}
		T res = queue2.front();
		queue2.pop();
		return res;
	}
	else
	{
		while (queue1.size() > 1)
		{
			queue2.push(queue1.front());
			queue1.pop();
		}
		
		T res = queue1.front();
		queue1.pop();
		return res;
	}
}